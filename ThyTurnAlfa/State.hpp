#pragma once

#ifndef STATE_HPP
#define STATE_HPP

#include <map>
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
	State(Queue& t_queue, std::vector<Character>& t_characters);
	bool extractNode(std::map<std::string, Node>& transpositionTable, std::string& key);

	Queue queue;
	std::vector<Character> characters;
	Node* node;
private:
	int m_currentMove;
};

#endif // STATE_HPP