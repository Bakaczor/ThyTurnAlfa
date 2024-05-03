#pragma once

#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Effect.hpp"
#include "Const.hpp"

class Character;

class Shield : public Effect {
	public:
	int hp = Const::Shield::SHIELD_DEFAULT_HP;

	Shield();
	Shield(const Shield& shield);

	virtual std::unique_ptr<Effect> clone() override;
	virtual bool nextRound(Character& affected) override;
	// cancelFrom is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !SHIELD_HPP