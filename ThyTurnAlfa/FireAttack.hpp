#pragma once

#ifndef FIRE_ATTACK_HPP
#define FIRE_ATTACK_HPP

#include "MagicAttack.hpp"

class Character;

class FireAttack : public MagicAttack {
	public:
	FireAttack();

	private:
	virtual void addEffects(Character& on_whom) final;
};

#endif // !FIRE_ATTACK_HPP
