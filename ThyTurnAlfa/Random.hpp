#pragma once

#include <random>

#include "Player.hpp"

class Random : public Player {
	public:
	Random(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	virtual bool move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) final;
};