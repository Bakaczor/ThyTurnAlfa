#pragma once

#ifndef BLEEDING_ATTACK_HPP
#define BLEEDING_ATTACK_HPP

#include "Attack.hpp"
#include "Bleeding.hpp"

#define BLEEDING_ATTACK_DEFAULT_WEIGHT 60
#define BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION 3
#define BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND 5

class BleedingAttack : public Attack {
public:
	BleedingAttack(int w_move = BLEEDING_ATTACK_DEFAULT_WEIGHT) : Attack(w_move) { }

	virtual void addEffects(Character& who, Character& on_whom) override
	{
		Bleeding::addTo(on_whom, BLEEDING_ATTACK_DEFAULT_EFFECT_DURATION, BLEEDING_ATTACK_DEFAULT_DAMAGE_PER_ROUND);
	};
};

#endif // !BLEEDING_ATTACK_HPP