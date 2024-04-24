#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <vector>
#include <cstring>
#include <string>
#include <memory>
#include <utility>
#include <json/json.h>

class Effect;
class Movement;

#include "Effect.hpp"
#include "Movement.hpp"

class Character {
public:
	int id = 0;
	int hp = 0;
	int currentHp = 0;
	int atk = 0;
	int def = 0;
	int spd = 0;
	int mp = 0;
	int wDef = 0;
	int wAtk = 0;
	bool isAlive = true;
	std::string name;

	std::vector<std::unique_ptr<Effect>> activeEffects = std::vector<std::unique_ptr<Effect>>();
	std::vector<std::unique_ptr<Movement>> movements = std::vector<std::unique_ptr<Movement>>();

	// usage of std::move is explained here: https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
	Character(std::string& name, std::vector<std::unique_ptr<Movement>>& movements) : name{ name }, movements{ std::move(movements) } { }
	Character() = default;
	Character(Character&& c) = default;
	Character(Character& c): Character(std::move(c)) { }
	bool applyEffects();
	void detachEffects();
	void Deserialize(Json::Value& root) { };
	const std::string getName() const {
		return name;
	}
	const int getSpd() const {
		return spd;
	}
};

#endif // !CHARACTER_HPP


