#pragma once

#ifndef AI_H
#define AI_H

#include <unordered_map>

#include "Player.hpp"

class Node;
class State;

class AI : public Player {
public:
	AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds);
	virtual std::optional<Message> move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) final;
private:
	int runAB_SSS(int firstEval, int treeHeight, State& state);
	int runAlphaBeta(int alpha, int beta, int treeDepth, std::string& path, State& state);
	std::string extendPath(std::string& path, std::tuple<int, int, int>& move);

	std::unordered_map<std::string, Node> m_transpositionTable;
};

#endif
