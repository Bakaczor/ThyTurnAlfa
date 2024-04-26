#pragma once

#ifndef FROZEN_HPP
#define FROZEN_HPP

#include "TemporaryDamageModifier.hpp"

class Frozen : public TemporaryDamageModifier {
	public:
	Frozen();

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
					  int atkDrop = Const::Frozen::FROZEN_DEFAULT_ATK_DROP,
					  int defDrop = Const::Frozen::FROZEN_DEFAULT_DEF_DROP);
};

#endif // !FROZEN_HPP