#pragma once

#include <list>

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
	bool isAlive;
	std::list<Effect*> activeEffects;
	std::list<Movement*> movements;

	Character(std::list<Movement*>& movements) : movements{movements} { }

	// in the documentation wrong argument is passed
	// to the method below
	bool addEffect(Effect& c);
	bool applyEffects();
private:
	
};

