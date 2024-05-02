#pragma once

#ifndef SHIELD_MOVEMENT_HPP
#define SHIELD_MOVEMENT_HPP

#include "DefensiveMovement.hpp"
#include "Const.hpp"

class Character;

class ShieldMovement : public DefensiveMovement {
	public:
	const int shieldHp = Const::ShieldMovement::SHIELD_MOVEMENT_DEFAULT_HP;

	ShieldMovement();
	virtual bool isInvokable(const Character& who, const Character& on_whom) const final;

	private:
	virtual void addEffects(Character& on_whom) final;
};

#endif // !SHIELD_HPP
