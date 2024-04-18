#pragma once

#include <cstring>
#include <string>
#include <vector>

class Character;

class Effect {
protected:
	bool elapsed() { return elapsedRounds++ < duration; };

public:
	int duration = 0;
	int elapsedRounds = 0;
	std::string name;

	Effect(const std::string name, int duration) : name{ name }, duration{ duration } { }
	Effect(Effect&& e) = default;

	Effect& operator=(Effect&& e) noexcept = default;

	bool isTypeOf(Effect& e);
	virtual bool nextRound(Character& affected) = 0;
	virtual bool remove(Character& affected) = 0;
	virtual bool addTo(std::vector<Effect>& applied_effects) = 0;
};


