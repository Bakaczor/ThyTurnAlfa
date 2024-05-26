#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <json/json.h>
#include <memory>
#include <string>
#include <string>
#include <vector>

#include "imgui.h"

#include "Const.hpp"
#include "DmgTable.hpp"
#include "Effect.hpp"
#include "Movement.hpp"
#include "Player.hpp"

class DmgTable;
class Effect;
class Movement;
class Player;

class Character {
	public:
	unsigned int id = 0;
	int currentHp = 0;
	int currentMp = 0;
	int wAtk = 0;
	int wDef = 0;
	bool isAlive = true;
	DmgTable dmgEstimationTable;

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
	void loadDmgEstimationTable(std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players);

	std::string getName() const;
	unsigned int getTextureID() const;
	int getHp() const;
	int getMp() const;
	int getAtk() const;
	int getDef() const;
	int getSpd() const;
	double getStrength() const;

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
	double m_strength = 0.0;
};

#endif


