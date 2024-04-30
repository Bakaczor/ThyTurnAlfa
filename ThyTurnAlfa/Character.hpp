#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <json/json.h>
#include <memory>
#include <string>
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

	bool applyDamage(int dmg);
	bool applyEffects();
	void detachEffects();
	void reset();

	void deserialize(Json::Value& root);
	bool loadImage();

	std::string getName() const;
	unsigned int getTextureID() const;
	int getHp() const;
	int getMp() const;
	int getAtk() const;
	int getDef() const;
	int getSpd() const;

	unsigned int getPlayerId() const;

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


