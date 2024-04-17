#pragma once

#include <vector>
#include <cstring>
#include <string>

#include "Effect.hpp"
#include "Movement.hpp"


class Character {
public:
	int id;
	int hp;
	int atk;
	int def;
	int spd;
	int mp;
	int wDef;
	int wAtk;
	bool isAlive;
	const std::string name;

	std::vector<Effect> activeEffects;
	std::vector<Movement> movements;

	Character(std::string name, std::vector<Movement>& movements) : name{ name }, movements{ movements } { }

	// in the documentation wrong argument is passed
	// to the method below
	bool addEffect(Effect& c);
	bool applyEffects();
private:
	
};

