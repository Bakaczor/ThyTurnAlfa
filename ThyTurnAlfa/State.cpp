#include <numeric>

#include "State.hpp"
#include "Character.hpp"
#include "Const.hpp"
#include "Heal.hpp"
#include "Revive.hpp"
#include "MagicAttack.hpp"

Node::Node(HeuristicList& t_movements) : movements{ t_movements } {}

State::State(Queue& t_queue, std::unordered_map<int, Character>& t_characters) :
	characters{t_characters}, queue{t_queue, t_characters}, node{nullptr} {}

bool State::extractNode(int characterId, std::unordered_map<std::string, Node>& transpositionTable, std::string& key)
{
	bool nodeSearched = false;

	if (transpositionTable.contains(key)) {
		nodeSearched = true;
	}
	else {
		HeuristicList movements(characters[characterId], characters);
		transpositionTable.emplace(key, Node(movements));
	}

	node = &transpositionTable.at(key);
	return nodeSearched;
}

bool State::makeMove(std::tuple<int, int, int>& move)
{
	int invokerId = std::get<0>(move);
	int movementId = std::get<1>(move);
	int targetId = std::get<2>(move);
	
	return characters[invokerId].movements[movementId]->invoke(characters[invokerId], characters[targetId]);
}

double State::evaluate(int playerId)
{
	return
		Const::Evaluation::HP_WEIGHT * evaluateHP(playerId) +
		Const::Evaluation::ATK_DEF_SPD_WEIGHT * evaluateAttackPotential(playerId) +
		Const::Evaluation::HEAL_WEIGHT * evaluateHealingPotential(playerId) +
		Const::Evaluation::MAGIC_ATTACK_WEIGHT * evaluateMagicAttackPotential(playerId);
}

double State::evaluateHP(int playerId)
{
	int firstPlayerHP = 0;
	int secondPlayerHP = 0;

	for (auto& character : characters) {
		int hp = character.second.currentHp;
		if (character.second.getPlayerId() == playerId) {
			firstPlayerHP += hp;
		}
		else {
			secondPlayerHP += hp;
		}
	}

	return (firstPlayerHP - secondPlayerHP) * 1.0 / (firstPlayerHP + secondPlayerHP);
}

double State::evaluateAttackPotential(int playerId)
{
	double firstPlayerAttackPotential = 0.0;
	int firstPlayerCharacterCount = 0;
	double secondPlayerAttackPotential = 0.0;
	int secondPlayerCharacterCount = 0;

	for (auto& character : characters) {
		int atk = character.second.getAtk();
		int def = character.second.getDef();
		int spd = character.second.getSpd();
		double eval = std::sqrt(atk * atk + def * def + spd * spd);
		if (character.second.getPlayerId() == playerId) {
			firstPlayerAttackPotential += eval;
			++firstPlayerCharacterCount;
		}
		else {
			secondPlayerAttackPotential += eval;
			++secondPlayerCharacterCount;
		}
	}

	return firstPlayerAttackPotential / firstPlayerCharacterCount - secondPlayerAttackPotential / secondPlayerCharacterCount;
}

double State::evaluateHealingPotential(int playerId)
{
	double firstPlayerHealingPotential = 0.0;
	double secondPlayerHealingPotential = 0.0;

	for (auto& character : characters) {
		int healingValue = 0;
		int healingCost = 0;
		for (auto& movement : character.second.movements) {
			if (movement->name == Const::Heal::HEAL_MOVEMENT_NAME) {
				auto ptr = std::dynamic_pointer_cast<Heal>(movement);
				healingValue += ptr->hpBoost;
				healingCost += ptr->getCost();
			}
			else if (movement->name == Const::Revive::REVIVE_MOVENT_NAME) {
				auto ptr = std::dynamic_pointer_cast<Revive>(movement);
				healingValue += character.second.getHp(); // probably should be something else but I dont care
				healingCost += ptr->getCost();
			}
		}
		double healingPotential = character.second.currentMp * healingValue * 1.0 / healingCost;
		if (character.second.getPlayerId() == playerId) {
			firstPlayerHealingPotential += healingPotential;
		}
		else {
			secondPlayerHealingPotential += healingPotential;
		}
	}

	return firstPlayerHealingPotential - secondPlayerHealingPotential;
}

double State::evaluateMagicAttackPotential(int playerId)
{
	double firstPlayerMagicAttackPotential = 0.0;
	double secondPlayerMagicAttackPotential = 0.0;

	for (auto& character : characters) {
		double magicAttackPotential = 0.0;

		for (int i = 0; i < character.second.movements.size(); ++i) {
			auto& movement = character.second.movements[i];

			if (movement->name == Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME ||
				movement->name == Const::IceAttack::ICE_ATTACK_MOVEMENT_NAME ||
				movement->name == Const::LightningAttack::LIGHTNING_ATTACK_MOVEMENT_NAME ||
				movement->name == Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME) {
				auto ptr = std::dynamic_pointer_cast<MagicAttack>(movement);

				// calculate avg damage
				int dmg = 0;
				int count = 0;
				for (auto& target : characters) {
					if (target.second.getPlayerId() != playerId) {
						dmg += character.second.dmgEstimationTable.getDmgEstimation(target.second.id, i);
						++count;
					}
				}
				double avgDmg = dmg * 1.0 / count;

				// calculate movement potential
				int cost = ptr->getCost();
				magicAttackPotential += avgDmg / cost;
			}
		} // movement loop

		// calculate character potential
		magicAttackPotential *= character.second.currentMp;
		if (character.second.getPlayerId() == playerId) {
			firstPlayerMagicAttackPotential += magicAttackPotential;
		}
		else {
			secondPlayerMagicAttackPotential += magicAttackPotential;
		}
	} // character loop

	return firstPlayerMagicAttackPotential - secondPlayerMagicAttackPotential;
}