#pragma once

#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "Movement.hpp"
#include "Shield.hpp"

class Attack : public Movement {
public:
	const float wMove;
	const float wPierce;

	Attack(int w_move, int w_pierce = 0)
		: Movement(TargetEnum::enemy), wMove{ percent(w_move) }, wPierce{ percent(w_pierce) } { }

	// invoke method is inherited from Movement
protected:
	int computeDMG(Character& who, Character& on_whom);
	virtual bool isInvokable(Character& who, Character& on_whom) override;
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !ATTACK_HPP


