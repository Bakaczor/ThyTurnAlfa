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

#include "Effect.hpp"
#include "Movement.hpp"

class Effect;
class Movement;

class Character {
	public:
	unsigned int id = 0;
	int currentHp = 0;
	int currentMp = 0;
	int wAtk = 0;
	int wDef = 0;
	bool isAlive = true;

	std::vector<std::unique_ptr<Effect>> activeEffects;
	std::vector<std::shared_ptr<Movement>> movements;

	Character() = default;
	Character(const Character& c);
	Character(Character&& c) = default;

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

	const unsigned int getPlayerId() const;

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


