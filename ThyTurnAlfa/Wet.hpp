#pragma once

#ifndef WET_HPP
#define WET_HPP

#include "ActionlessEffect.hpp"

class Wet : public ActionlessEffect {
	public:
	Wet();

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int frozen_duration = Const::Wet::WET_DEFAULT_DURATION);
};

#endif // !WET_HPP