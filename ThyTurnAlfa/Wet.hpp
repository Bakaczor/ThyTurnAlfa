#pragma once

#ifndef WET_HPP
#define WET_HPP

#include "ActionlessEffect.hpp"

#define EFFECT_NAME_WET "Wet"
#define WET_DEFAULT_FROZEN_DURATION 3

class Wet : public ActionlessEffect {
public:
	Wet(int duration) : ActionlessEffect(EFFECT_NAME_WET, duration) { };

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int frozen_duration = WET_DEFAULT_FROZEN_DURATION);
};

#endif // !WET_HPP