#pragma once

#ifndef COLD_HPP
#define COLD_HPP

#include "ActionlessEffect.hpp"
#include "Burning.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"

class Cold : public ActionlessEffect {
	public:
	Cold();

	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !COLD_HPP