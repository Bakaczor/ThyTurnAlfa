#pragma once

#ifndef ACTIONLESS_EFFECT_HPP
#define ACTIONLESS_EFFECT_HPP

#include "Effect.hpp"
#include "Character.hpp"

class ActionlessEffect : public Effect {
public:
	ActionlessEffect(std::string name, int duration)
		: Effect(name, duration) { };

	virtual bool nextRound(Character& affected) override { return elapsed(); }
	// cancelFrom method is inherited from Effect
};

#endif // !ACTIONLESS_EFFECT_HPP