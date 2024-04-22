#pragma once

#ifndef ATTACK_HPP
#define ATTACK_HPP

#endif // !ATTACK_HPP


#include "Movement.hpp"

class Attack : public Movement {
public:
	const float wMove;
	const float wPierce;

	Attack(int w_move, int w_pierce = 0) 
		: Movement(TargetEnum::enemy), wMove{ percent(w_move) }, wPierce{ percent(w_pierce)} { }

	virtual bool invoke(Character& who, Character& on_whom) override;
protected:
	int computeDMG(Character& who, Character& on_whom);
	virtual bool isExecutable(Character& who, Character& on_whom) override;
	virtual void applyDamage(Character& who, Character& on_whom);
};