#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"

class Player {
public:
	unsigned int id;
	std::vector<Character*> party;

	Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	bool virtual move(Character& who) = 0;

	Player() = default;
	Player(std::vector<Character>& party);
	virtual bool move(Character& character, std::array<Player, 2>& players);
private:
	static unsigned int m_count;
};

#endif
