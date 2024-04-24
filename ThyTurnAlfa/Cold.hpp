#pragma once

#ifndef COLD_HPP
#define COLD_HPP

#include "ActionlessEffect.hpp"

#define COLD_EFFECT_NAME "Cold"
#define COLD_DEFAULT_FROZEN_DURATION 4

class Cold : public ActionlessEffect {
public:
	Cold(int duration) : ActionlessEffect(COLD_EFFECT_NAME, duration) { };

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int frozen_duration = COLD_DEFAULT_FROZEN_DURATION);
};

#endif // !COLD_HPP