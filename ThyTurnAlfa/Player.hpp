#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Character.hpp"

class Player {
	public:
	unsigned int id;
	std::vector<Character*> party;

	Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	bool virtual move(Character& who) = 0;

	private:
	static unsigned int m_count;
};

#endif
