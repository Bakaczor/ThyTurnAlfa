#pragma once
#include <random>
#include "Player.h"

class Random : public Player {
public:
	Random(std::vector<Character>& party);
	virtual bool move(Character& character, std::vector<Player>& players) final;
};