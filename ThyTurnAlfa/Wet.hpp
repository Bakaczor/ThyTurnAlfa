#pragma once

#ifndef WET_HPP
#define WET_HPP

#include "ActionlessEffect.hpp"
#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"

class Wet : public ActionlessEffect {
	public:
	Wet();

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !WET_HPP