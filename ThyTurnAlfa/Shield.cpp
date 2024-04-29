#include "Shield.hpp"
#include "Character.hpp"

Shield::Shield(): Effect(Const::Shield::SHIELD_EFFECT_NAME, Const::Shield::SHIELD_DEFAULT_DURATION) {}

bool Shield::nextRound(Character& affected) { return hp > 0; }

bool Shield::addTo(Character& affected) {
	std::erase_if(affected.activeEffects, [&affected](auto& e) {
		if (dynamic_cast<Shield*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		}
		return false; });

	affected.activeEffects.emplace_back(std::make_unique<Shield>());
	return true;
}
