#pragma once

#ifndef AI_H
#define AI_H

#include "Player.hpp"

class AI : public Player {
	public:
	AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	virtual bool move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) final;
};

#endif
