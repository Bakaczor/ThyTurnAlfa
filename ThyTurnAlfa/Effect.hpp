#pragma once

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <string>
#include <memory>

class Character;

class Effect {
	public:
	int duration = 0;
	int elapsedRounds = 0;
	std::string name;

	Effect(const std::string& name, int duration) : name{ name }, duration{ duration } { }
	Effect(const Effect& e) = default;

	virtual std::unique_ptr<Effect> clone() = 0;

	virtual bool nextRound(Character& affected) = 0;

	// cancelFrom should be executed after effect expiration
	// it holds the logic of detaching the effect from a Character
	virtual bool cancelFrom(Character& affected);

	// each class inheriting from Effect should implement method 
	// addTo(Character& affected, Params...) which adds the effect with
	// specified parameters to activeEffects vector of Character.
	// The method should not invoke nextRound inside!

	protected:
	// this should not be used for effects with infinite duration
	bool elapsed();
};

#endif





