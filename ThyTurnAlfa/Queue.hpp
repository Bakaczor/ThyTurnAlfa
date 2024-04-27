#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <climits>
#include <queue>

#include "Player.hpp"

struct Tuple {
	Tuple(Character* t_character, int t_baseATV) :
		character{ t_character }, baseATV{ t_baseATV }, currentATV{ t_baseATV } {}
	bool operator < (const Tuple& rhs) const {
		return currentATV > rhs.currentATV;
	}

	Character* character;
	int baseATV;
	int currentATV;
};

class Queue : private std::priority_queue<Tuple> {
public:
	Queue();
	Queue(std::array<std::unique_ptr<Player>, 2>& players);
	Character& peek();
};

#endif
