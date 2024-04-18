#pragma once

#include "Effect.hpp"
#include "Character.hpp"

class ActionlessEffect : public Effect {
public:
	ActionlessEffect(std::string name, int duration) 
		: Effect(name, duration) { };

	virtual bool nextRound(Character& affected) override;
	virtual bool remove(Character& affected) override;
};