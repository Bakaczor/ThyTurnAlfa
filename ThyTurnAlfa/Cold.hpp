#pragma once

#include "ActionlessEffect.hpp"

#define EFFECT_NAME_COLD "Cold"
#define COLD_DEFAULT_FROZEN_DURATION 4

class Cold : public ActionlessEffect {
public:
	Cold(int duration) : ActionlessEffect(EFFECT_NAME_COLD, duration) { };

	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, 
		int frozen_duration = COLD_DEFAULT_FROZEN_DURATION);
};