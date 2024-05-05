#pragma once

#ifndef STATE_HPP
#define STATE_HPP

#include <unordered_map>
#include <string>

#include "Queue.hpp"
#include "HeuristicList.hpp"

struct Node
{
	Node(HeuristicList& t_movements);

	int lowerbound = INT_MIN;
	int upperbound = INT_MAX;
	HeuristicList movements;
};

class State
{
public:
	State(Queue& t_queue, std::unordered_map<int, Character>& t_characters);
	State(const State& state);
	bool extractNode(int characterId, std::unordered_map<std::string, Node>& transpositionTable, std::string& key);
	bool makeMove(std::tuple<int, int, int>& move);
	double evaluate(int playerId);

	Queue queue;
	std::unordered_map<int, Character> characters; // <characterId, character>
	Node* node;

private:
	double evaluateHP(int playerId);
	double evaluateAttackPotential(int playerId);
	double evaluateHealingPotential(int playerId);
	double evaluateMagicAttackPotential(int playerId);
};

#endif // STATE_HPP