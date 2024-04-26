#pragma once

#ifndef WET_HPP
#define WET_HPP

#include "ActionlessEffect.hpp"

#define WET_EFFECT_NAME "Wet"
#define WET_DEFAULT_FROZEN_DURATION 3

class Wet : public ActionlessEffect {
public:
	Wet(int duration) : ActionlessEffect(WET_EFFECT_NAME, duration) { };

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int frozen_duration = WET_DEFAULT_FROZEN_DURATION);
};

#endif // !WET_HPP