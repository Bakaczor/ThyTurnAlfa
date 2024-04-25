#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Character.hpp"

class Player {
	public:
	unsigned int id;
	std::vector<Character> party;

	private:
	static unsigned int m_count;
};

#endif
