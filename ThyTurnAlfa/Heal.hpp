#pragma once

#ifndef HEAL_HPP

#include "Movement.hpp"

#define HEAL_HP_BOOST_DEFAULT 50

class Heal : public Movement {
public:
	const int hpBoost;

	Heal(int hp_boost = HEAL_HP_BOOST_DEFAULT) : Movement(TargetEnum::ally), hpBoost{ hp_boost } { }

protected:
	virtual bool individualAction(Character& who, Character& on_whom) override;
};

#endif // !HEAL_HPP