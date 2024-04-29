#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <climits>
#include <queue>

#include "Player.hpp"

struct Tuple {
	Tuple(Character* t_character, int t_baseATV);
	Tuple(Character* t_character, int t_baseATV, int t_currentATV);
	bool operator < (const Tuple& rhs) const;

	Character* character;
	int baseATV;
	int currentATV;
};

class Queue : private std::priority_queue<Tuple> {
public:
	Queue();
	Queue(std::array<std::unique_ptr<Player>, 2>& players);
	Queue(Queue& queue, std::vector<Character>& characters);
	Character& peek();
	const std::vector<Tuple>& getQueue() const;
};

#endif
