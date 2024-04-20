#pragma once

#include <vector>
#include <cstring>
#include <string>
#include <memory>
#include <utility>

#include "Effect.hpp"
#include "Movement.hpp"

class Character {
public:
	int id = 0;
	int hp = 0;
	int atk = 0;
	int def = 0;
	int spd = 0;
	int mp = 0;
	int wDef = 0;
	int wAtk = 0;
	bool isAlive = true;
	const std::string name;
	
	std::vector<std::unique_ptr<Effect>> activeEffects = std::vector<std::unique_ptr<Effect>>();
	std::vector<std::unique_ptr<Movement>> movements = std::vector<std::unique_ptr<Movement>>();

	// usage of std::move is explained here: https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
	Character(std::string& name, std::vector<std::unique_ptr<Movement>> movements) : name{ name }, movements{ std::move(movements) } { }

	// in the documentation wrong argument is passed
	// to the method below
	bool addEffect(Effect& c);
	bool applyEffects();
};

