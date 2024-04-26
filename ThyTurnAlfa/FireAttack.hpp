#pragma once

#ifndef FIRE_ATTACK_HPP
#define FIRE_ATTACK_HPP

#include "Burning.hpp"
#include "MagicAttack.hpp"

class FireAttack : public MagicAttack {
	public:
	FireAttack();

	virtual void addEffects(Character& on_whom) final;
};

#endif // !FIRE_ATTACK_HPP
