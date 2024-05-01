#pragma once

#ifndef STATE_HPP
#define STATE_HPP

#include <unordered_map>
#include <string>

#include "Queue.hpp"

struct Node
{
	int lowerbound = INT_MIN;
	int upperbound = INT_MAX;
	std::vector<std::pair<int, int>> movements; // <movementID, characterID>
};

class State
{
public:
	State(Queue& t_queue, std::unordered_map<int, Character>& t_characters);
	bool extractNode(std::unordered_map<std::string, Node>& transpositionTable, std::string& key);
	bool makeMove(std::tuple<int, int, int>& move);

	Queue queue;
	std::unordered_map<int, Character> characters; // <characterId, character>
	Node* node;
};

#endif // STATE_HPP