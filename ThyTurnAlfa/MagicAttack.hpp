#pragma once

#ifndef MAGIC_ATTACK_HPP
#define MAGIC_ATTACK_HPP

#include "Attack.hpp"

class Character;

class MagicAttack : public Attack {
	public:
	const int cost;

	MagicAttack(std::string&& name, int cost, int w_move, int w_pierce = 0);

	virtual int getCost() override;
	protected:
	virtual bool isInvokable(Character& who, Character& on_whom) override;
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !#define MAGIC_ATTACK_HPP