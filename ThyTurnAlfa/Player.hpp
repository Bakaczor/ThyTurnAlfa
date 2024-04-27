#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"

class Player {
	public:
	unsigned int id;
	std::vector<Character*> party;

	Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	Player() = default;

	virtual bool move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) = 0;

	private:
	static unsigned int m_count;
};

#endif
