#pragma once

#ifndef BLEEDING_ATTACK_HPP
#define BLEEDING_ATTACK_HPP

#include "Attack.hpp"
#include "Bleeding.hpp"

class BleedingAttack : public Attack {
	public:
	BleedingAttack();

	virtual void addEffects(Character& on_whom) final;
};

#endif // !BLEEDING_ATTACK_HPP