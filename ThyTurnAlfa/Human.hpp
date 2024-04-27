#pragma once

#ifndef HUMAN_H
#define HUMAN_H

#include "Player.hpp"

class Human : public Player {
	Human(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	bool virtual move(Character& who) final;
};

#endif