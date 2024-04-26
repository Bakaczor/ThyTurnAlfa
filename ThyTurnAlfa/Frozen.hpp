#pragma once

#ifndef FROZEN_HPP
#define FROZEN_HPP

#include "TemporaryDamageModifier.hpp"

class Frozen : public TemporaryDamageModifier {
	public:
	Frozen();

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected);
};

#endif // !FROZEN_HPP