#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"

Cold::Cold(): ActionlessEffect(Const::Cold::COLD_EFFECT_NAME, Const::Cold::COLD_DEFAULT_DURATION) {}

bool Cold::addTo(Character& affected, int duration, int frozen_duration) {
	bool apply = true;
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Cold*>((*it).get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		} else if (dynamic_cast<Wet*>((*it).get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			affected.activeEffects.emplace_back(std::make_unique<Frozen>());
			apply = false;
		} 
		else if (dynamic_cast<Burning*>((*it).get())) {
			apply = false;
		}
	}

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Cold>());
	}
	return true;
}
