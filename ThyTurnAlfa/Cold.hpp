#pragma once

#ifndef COLD_HPP
#define COLD_HPP

#include "ActionlessEffect.hpp"

class Cold : public ActionlessEffect {
	public:
	Cold();

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected, int duration,
		int frozen_duration = Const::Cold::COLD_DEFAULT_DURATION);
};

#endif // !COLD_HPP