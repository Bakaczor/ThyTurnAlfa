#pragma once

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <cstring>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Character;

#include "Character.hpp"

#define INFINITE_DURATION -1

class Effect {
protected:
	// this should not be used for effects with infinite duration
	bool elapsed() { return elapsedRounds++ < duration; };

public:
	int duration = 0;
	int elapsedRounds = 0;
	std::string name;

	Effect(const std::string& name, int duration) : name{ name }, duration{ duration } { }
	Effect(const Effect& e) = default;

	virtual bool nextRound(Character& affected) {
		return true;
	};

	// cancelFrom should be executed after effect expiration
	// it holds the logic of detaching the effect from a Character
	virtual bool cancelFrom(Character& affected) { return true; }

	// each class inheriting from Effect should implement method 
	// addTo(Character& affected, Params...) which adds the effect with
	// specified parameters to activeEffects vector of Character.
	// The method should not invoke nextRound inside!
};

#endif // !EFFECT_HPP





