#pragma once

#include "ActionlessEffect.hpp"

#define EFFECT_NAME_WET "Wet"
#define WET_DEFAULT_FROZEN_DURATION 3

class Wet : public ActionlessEffect {
public:
	Wet(int duration) : ActionlessEffect(EFFECT_NAME_WET, duration) { };

	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, 
		int frozen_duration = WET_DEFAULT_FROZEN_DURATION);
};