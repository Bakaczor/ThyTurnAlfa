#pragma once

#include "Movement.hpp"

class Attack : public Movement {
public:
	Attack(int w_move, int w_pierce = 0) : Movement(TargetEnum::enemy, w_move, w_pierce) { }

	virtual bool isExecutable(Character& who, Character& on_whom) override;
	virtual void applyDamage(Character& who, Character& on_whom);
};