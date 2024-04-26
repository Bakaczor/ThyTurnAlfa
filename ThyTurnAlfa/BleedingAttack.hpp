#pragma once

#ifndef BLEEDING_ATTACK_HPP
#define BLEEDING_ATTACK_HPP

#include "Attack.hpp"
#include "Bleeding.hpp"

class BleedingAttack : public Attack {
	public:
	BleedingAttack(int w_move = Const::BleedingAttack::BLEEDING_ATTACK_DEFAULT_WEIGHT):
		Attack(Const::BleedingAttack::BLEEDING_ATTACK_MOVEMENT_NAME, w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) final;
};

#endif // !BLEEDING_ATTACK_HPP