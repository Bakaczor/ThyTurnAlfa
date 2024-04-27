#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"

class Player {
public:
	unsigned int id;
	std::vector<Character>* party;

	Player() = default;
	Player(std::vector<Character>& party);
	virtual bool move(Character& character, std::array<Player, 2>& players);
private:
	static unsigned int m_count;
};

#endif
