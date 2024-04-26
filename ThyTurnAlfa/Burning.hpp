#pragma once

#ifndef BURNING_HPP
#define BURNING_HPP

#include "TemporaryDamagePerRound.hpp"

class Burning : public TemporaryDamagePerRound {
	public:
	Burning();

	// nextRound method is inherited from TemporaryDamagePerRound
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !BURNING_HPP