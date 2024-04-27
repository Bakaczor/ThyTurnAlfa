#pragma once

#ifndef ICE_ATTACK_HPP
#define ICE_ATTACK_HPP

#include "MagicAttack.hpp"

class IceAttack : public MagicAttack {
	public:
	IceAttack();
	protected:
	virtual void addEffects(Character& on_whom) override;
};

#endif // !ICE_ATTACK_HPP