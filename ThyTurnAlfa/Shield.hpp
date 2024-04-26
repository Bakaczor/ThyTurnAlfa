#pragma once

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Effect.hpp"

class Shield : public Effect {
	public:
	int hp = Const::Shield::SHIELD_DEFAULT_HP;

	Shield();

	virtual bool nextRound(Character& affected) override;
	// cancelFrom is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !SHIELD_HPP