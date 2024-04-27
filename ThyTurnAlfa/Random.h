#pragma once
#include <random>
#include "Player.h"

class Random : public Player {
public:
	Random(std::vector<Character>& party);
	virtual bool move(Character& character, std::array<Player, 2>& players) override final;
};