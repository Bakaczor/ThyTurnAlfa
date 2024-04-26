#include "Burning.hpp"
#include "Cold.hpp"
#include "Wet.hpp"

Burning::Burning(): TemporaryDamagePerRound(Const::Buring::BURNING_EFFECT_NAME, 
											Const::Buring::BURNING_DEFAULT_DURATION,
											Const::Buring::BURNING_DEFAULT_DAMAGE_PER_ROUND) {};

bool Burning::addTo(Character& affected, int duration, int damage_per_round) {
	bool apply = true;

	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Burning*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		} else if (dynamic_cast<Wet*>(it->get())){
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			apply = false;
		}
	}

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Burning>());
	}
	return true;
}
