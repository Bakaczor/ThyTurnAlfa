#pragma once

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <cstring>
#include <string>
#include <vector>
#include <memory>

#include "Character.hpp"

class Effect {
protected:
	bool elapsed() { return elapsedRounds++ < duration; };

public:
	int duration = 0;
	int elapsedRounds = 0;
	std::string name;

	Effect(const std::string& name, int duration) : name{ name }, duration{ duration } { }
	Effect(const Effect& e) = default;

	virtual bool nextRound(Character& affected) = 0;
	virtual bool cancelFrom(Character& affected) { return true; }
};

#endif // !EFFECT_HPP





