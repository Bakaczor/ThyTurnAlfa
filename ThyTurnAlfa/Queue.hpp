#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <climits>

#include "Player.h"

struct Tuple {
	Tuple(Character& t_character, int t_baseATV) :
		character{ &t_character }, baseATV{ t_baseATV }, currentATV{ t_baseATV } {}
	bool operator<(const Tuple& rhs) const {
		return currentATV > rhs.currentATV;
	}

	Character* character;
	int baseATV;
	int currentATV;
};

class Queue : private std::priority_queue<Tuple> {
public:
	Queue();
	Queue(std::vector<Player>& players);
	Character& peek();
};

#endif
