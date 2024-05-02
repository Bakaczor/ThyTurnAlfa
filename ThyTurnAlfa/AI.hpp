#pragma once

#ifndef AI_H
#define AI_H

#include <unordered_map>

#include "Player.hpp"
#include "State.hpp"

class Queue;

class AI : public Player {
public:
	AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds, int treeHeight, Queue* pQueue);
	virtual std::optional<Message> move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) final;
private:
	int runAB_SSS(int characterId, int firstEval, int treeHeight, State& state);
	int runAlphaBeta(int characterId, int alpha, int beta, int treeDepth, std::string& path, State& state);
	std::string extendPath(std::string& path, std::tuple<int, int, int>& move);

	std::unordered_map<std::string, Node> m_transpositionTable;
	std::tuple<int, int, int> m_bestMove; // <invokerId, movementId, targetId>
	int m_treeHeight;
	Queue* m_pGlobalQueue;
};

#endif
