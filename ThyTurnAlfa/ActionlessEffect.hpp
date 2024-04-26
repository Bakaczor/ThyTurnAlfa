#pragma once

#ifndef ACTIONLESS_EFFECT_HPP
#define ACTIONLESS_EFFECT_HPP

#include "Character.hpp"
#include "Effect.hpp"

class ActionlessEffect : public Effect {
	public:
	ActionlessEffect(std::string name, int duration);

	virtual bool nextRound(Character& affected) override;
	// cancelFrom method is inherited from Effect
};

#endif // !ACTIONLESS_EFFECT_HPP