#pragma once

#ifndef FROZEN_HPP
#define FROZEN_HPP

#include "TemporaryDamageModifier.hpp"

class Character;

class Frozen : public TemporaryDamageModifier {
	public:
	Frozen();
	Frozen(const Frozen& frozen);

	virtual std::unique_ptr<Effect> clone() override;
	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected);
};

#endif // !FROZEN_HPP