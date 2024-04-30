#include "AI.hpp"
#include "State.hpp"

AI::AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds):
	Player(availibleCharacters, curChrIds) {}

std::optional<Message> AI::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	// TODO
	return Message{ "Megumin", "what", "Aqua" };
}

int AI::runAB_SSS(int firstEval, int treeHeight, State& state)
{
	int evaluation = firstEval;
	int upperbound = INT_MAX;
	int lowerbound = INT_MIN;

	while (lowerbound < upperbound) {
		int bound = evaluation;
		if (evaluation == lowerbound) {
			++bound;
		}

		std::string path;
		evaluation = runAlphaBeta(bound - 1, bound, treeHeight, path, state);
		if (evaluation < bound) {
			upperbound = evaluation;
		}
		else {
			lowerbound = evaluation;
		}
	}

	return evaluation;
}

int AI::runAlphaBeta(int alpha, int beta, int treeDepth, std::string& path, State& state)
{
	int evaluation;
	bool nodeSearched = state.extractNode(m_transpositionTable, path);
	if (nodeSearched) {
		if (state.node->lowerbound >= beta) {
			return state.node->lowerbound;
		}
		if (state.node->upperbound <= alpha) {
			return state.node->upperbound;
		}
		alpha = std::max(alpha, state.node->lowerbound);
		beta = std::min(beta, state.node->upperbound);
	}

	if (treeDepth == 0) {
		evaluation = 0; // TODO: evaluate(state)
	}
	else {
		// ...
	}

	if (evaluation <= alpha) {
		state.node->upperbound = evaluation;
	}
	else if (evaluation > alpha && evaluation < beta) {
		state.node->lowerbound = evaluation;
		state.node->upperbound = evaluation;
	}
	else {
		state.node->lowerbound = evaluation;
	}

	return evaluation;
}
