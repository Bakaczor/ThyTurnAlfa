#include <algorithm>

#include "Attack.hpp"
#include "Bleeding.hpp"
#include "Cure.hpp"
#include "FireAttack.hpp"
#include "Heal.hpp"
#include "HeuristicList.hpp"
#include "IceAttack.hpp"
#include "LightningAttack.hpp"
#include "Revive.hpp"
#include "WaterAttack.hpp"

HeuristicList::HeuristicList(const Character& who, std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players) {
	std::vector<std::pair<std::pair<suint, suint>, int>> v(who.movements.size() * players.size());
	for (suint i = 0; i < who.movements.size(); i++) {
		for (const auto& player : players) {
			for (const auto& character : player->party) {
				const auto& pair = std::make_pair(i, character.id);
				int weight = getWeight(who, who.movements.at(i).get(), character);
				weight += killHeuristic(who, i, character);
				v.emplace_back(std::make_pair(pair, weight));
			}
		}
	}
	std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
	std::transform(v.begin(), v.end(), std::back_inserter(list), [](const auto& pair) {
		return pair.first;
	});
}

int HeuristicList::killHeuristic(const Character& who, const suint& what, const Character& onWhom) const {
	const int dmg = who.dmgEstimationTable.getDmgEstimation(onWhom.id, what);
	if (dmg >= onWhom.currentHp) {
		return Const::Algorithmic::W_KILL;
	}
	return 0;
}

int HeuristicList::getWeight(const Character& who, const Movement* what, const Character& onWhom) const {
	int weight = 0;
	weight += reviveHeuristic(who, what, onWhom);
	weight += cureHeuristic(who, what, onWhom);
	weight += healHeuristic(who, what, onWhom);
	weight += wetHeuristic(who, what, onWhom);
	weight += coldHeuristic(who, what, onWhom);
	weight += burningHeuristic(who, what, onWhom);
	weight += frozenHeuristic(who, what, onWhom);
	weight += attackHeuristic(who, what, onWhom);
	return weight;
}

int HeuristicList::reviveHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const Revive* revive = dynamic_cast<const Revive*>(what);
	if (revive && who.getPlayerId() == onWhom.getPlayerId() && !onWhom.isAlive) {
		return Const::Algorithmic::W_REVIVE;
	}
	return -Const::Algorithmic::W_BAD_MOVE;
}

int HeuristicList::cureHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const Cure* cure = dynamic_cast<const Cure*>(what);
	if (cure && who.getPlayerId() == onWhom.getPlayerId()) {
		bool flag = false;
		for (const auto& effect : onWhom.activeEffects) {
			if (dynamic_cast<Bleeding*>(effect.get())) {
				flag = true;
				break;
			}
		}
		if (flag) {
			return Const::Algorithmic::W_CURE;
		}
	}
	return -Const::Algorithmic::W_BAD_MOVE;
}

int HeuristicList::healHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const Heal* heal = dynamic_cast<const Heal*>(what);
	if (heal && who.getPlayerId() == onWhom.getPlayerId()) {
		if (static_cast<float>(onWhom.currentHp) / onWhom.getHp() < Const::Algorithmic::HEAL_THRESHOLD) {
			return Const::Algorithmic::W_HEAL;
		} else if (onWhom.getHp() - onWhom.currentHp < heal->hpBoost) {
			return -Const::Algorithmic::W_HEAL;
		}
	}
	return 0;
}

int HeuristicList::wetHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const LightningAttack* lightningAttack = dynamic_cast<const LightningAttack*>(what);
	const IceAttack* iceAttack = dynamic_cast<const IceAttack*>(what);
	const FireAttack* fireAttack = dynamic_cast<const FireAttack*>(what);

	if (who.getPlayerId() != onWhom.getPlayerId()) {
		if (fireAttack) {
			return -Const::Algorithmic::W_WET;
		} else if (lightningAttack || iceAttack) {
			return Const::Algorithmic::W_WET;
		}
	}
	return 0;
}

int HeuristicList::coldHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const WaterAttack* waterAttack = dynamic_cast<const WaterAttack*>(what);
	if (waterAttack && who.getPlayerId() != onWhom.getPlayerId()) {
		return Const::Algorithmic::W_COLD;
	}
	return 0;
}

int HeuristicList::burningHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const WaterAttack* waterAttack = dynamic_cast<const WaterAttack*>(what);
	if (waterAttack) {
		if (who.getPlayerId() == onWhom.getPlayerId()) {
			return Const::Algorithmic::W_BURNING;
		} else {
			return Const::Algorithmic::W_BAD_MOVE;
		}
	}
	return 0;
}

int HeuristicList::frozenHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const FireAttack* fireAttack = dynamic_cast<const FireAttack*>(what);
	if (fireAttack) {
		if (who.getPlayerId() == onWhom.getPlayerId()) {
			return Const::Algorithmic::W_FROZEN;
		} else {
			return Const::Algorithmic::W_BAD_MOVE;
		}
	}
	return 0;
}

int HeuristicList::attackHeuristic(const Character& who, const Movement* what, const Character& onWhom) const {
	const Attack* attack = dynamic_cast<const Attack*>(what);
	if (attack && who.getPlayerId() != onWhom.getPlayerId()) {  
		return Const::Algorithmic::W_ATTACK;
	}
	return 0;
}
