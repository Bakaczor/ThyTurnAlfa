#pragma once

#ifndef MAGIC_ATTACK_HPP
#define MAGIC_ATTACK_HPP

#include "Attack.hpp"

class MagicAttack : public Attack {
	public:
	const unsigned cost;

	MagicAttack(std::string&& name, int cost, int w_move, int w_pierce = 0)
		: Attack(std::move(name), w_move, w_pierce), cost{ (unsigned)cost } { }

	virtual int getCost() override;
	protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override;
};

#endif // !#define MAGIC_ATTACK_HPP