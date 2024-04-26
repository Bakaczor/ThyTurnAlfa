#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"

Wet::Wet(): ActionlessEffect(Const::Wet::WET_EFFECT_NAME, Const::Wet::WET_DEFAULT_DURATION) {};

bool Wet::addTo(Character& affected, int duration, int frozen_duration) {
	bool apply = true;
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Wet*>(it->get()) || dynamic_cast<Burning*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
		else if (dynamic_cast<Cold*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			affected.activeEffects.emplace_back(std::make_unique<Frozen>());
			apply = false;
		}
	}

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Wet>());
	}
	return true;
}