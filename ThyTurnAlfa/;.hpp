#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstring>
#include <json/json.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "imgui.h"

#include "Effect.hpp";
#include "Movement.hpp";

class Character {
	public:
	int id = 0;
	int currentHp = 0;
	int currentMp = 0;
	int wAtk = 0;
	int wDef = 0;
	bool isAlive = true;

	std::vector<std::unique_ptr<Effect>> activeEffects = std::vector<std::unique_ptr<Effect>>();
	std::vector<std::unique_ptr<Movement>> movements = std::vector<std::unique_ptr<Movement>>();

	// usage of std::move is explained here: https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
	Character(std::string name, std::string imagePath, std::vector<std::unique_ptr<Movement>>& movements);
	Character() = default;
	Character(Character&& c) = default;

	bool applyDamage(int dmg);
	bool applyEffects();
	void detachEffects();
	void reset();

	void deserialize(Json::Value& root);
	bool loadImage();

	const std::string getName() const;
	const ImTextureID* getTextureID() const;
	const int getHp() const;
	const int getMp() const;
	const int getAtk() const;
	const int getDef() const;
	const int getSpd() const;

	private:
	std::string m_name;
	std::string m_imagePath;
	unsigned int m_textureID = 0;

	int m_hp = 0;
	int m_mp = 0;
	int m_atk = 0;
	int m_def = 0;
	int m_spd = 0;
};

#endif // !CHARACTER_HPP


