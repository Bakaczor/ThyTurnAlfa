#pragma once

#ifndef ICE_ATTACK_HPP
#define ICE_ATTACK_HPP

#include "MagicAttack.hpp"

class Character;

class IceAttack : public MagicAttack {
	public:
	IceAttack();

	private:
	virtual void addEffects(Character& on_whom) final;
};

#endif // !ICE_ATTACK_HPP