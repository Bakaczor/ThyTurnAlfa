#pragma once

#ifndef ATTACK_HPP
#define ATTACK_HPP

#include "Movement.hpp"

class Character;

class Attack : public Movement {
	public:
	const float wMove;
	const float wPierce;

	Attack(std::string&& name, int w_move, int w_pierce = 0);

	// invoke inherited from Movement

	protected:
	int computeDmg(const Character& who, const Character& on_whom) const;
	virtual bool isInvokable(Character& who, Character& on_whom) override;
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !ATTACK_HPP


