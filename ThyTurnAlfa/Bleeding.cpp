#include "Bleeding.hpp"

Bleeding::Bleeding(): TemporaryDamagePerRound(Const::Bleeding::BLEEDING_EFFECT_NAME,
											  Const::Bleeding::BLEEDING_DEFAULT_DURATION,
											  Const::Bleeding::BLEEDING_DEFAULT_DAMAGE_PER_ROUND) {};

bool Bleeding::addTo(Character& affected, int duration, int damage_per_round) {
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Bleeding*>(it->get())) {
			(*it)->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}
	affected.activeEffects.emplace_back(std::make_unique<Bleeding>());
	return true;
}
