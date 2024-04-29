#pragma once

#ifndef LIGHTNING_ATTACK_HPP
#define LIGHTNING_ATTACK_HPP

#include "MagicAttack.hpp"

class Character;

class LightningAttack : public MagicAttack {
	public:
	LightningAttack();

	private:
	virtual bool individualAction(Character& who, Character& on_whom) final;
};

#endif // !LIGHTNING_ATTACK_HPP