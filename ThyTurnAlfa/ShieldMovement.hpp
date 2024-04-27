#pragma once

#ifndef SHIELD_MOVEMENT_HPP
#define SHIELD_MOVEMENT_HPP

#include "DefensiveMovement.hpp"

class ShieldMovement : public DefensiveMovement {
	public:
	const int shieldHp = Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_HP;

	ShieldMovement();

	private:
	virtual bool isInvokable(Character& who, Character& on_whom) final;
	virtual void addEffects(Character& on_whom) final;
};

#endif // !SHIELD_HPP
