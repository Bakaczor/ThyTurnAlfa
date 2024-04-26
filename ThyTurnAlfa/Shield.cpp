#include "Shield.hpp"

Shield::Shield(): Effect(Const::Shield::SHIELD_EFFECT_NAME, Const::Shield::SHIELD_DEFAULT_DURATION) {}

bool Shield::nextRound(Character& affected) { return hp > 0; }

bool Shield::addTo(Character& affected, int hp) {
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Shield*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}

	affected.activeEffects.emplace_back(std::make_unique<Shield>());
	return true;
}
