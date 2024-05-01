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
	int evaluation = 0;
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
		Character currentCharacter = state.queue.peek();
		if (id == currentCharacter.getPlayerId()) {
			evaluation = INT_MIN;
			int childAlpha = alpha;
			
			for (int i = 0; i < state.node->movements.size(); ++i) {
				std::pair<int, int> move = state.node->movements[i];
				std::tuple<int, int, int> moveWithInvoker(currentCharacter.id, move.first, move.second);

				State childState(state);
				std::string childPath = extendPath(path, moveWithInvoker);
				
				// TODO: probably should check if move is possible before making copy os state (on original state?)
				if (childState.makeMove(moveWithInvoker)) {
					int childAlphaBeta = runAlphaBeta(childAlpha, beta, treeDepth - 1, childPath, childState);
					evaluation = std::max(evaluation, childAlphaBeta);
					childAlpha = std::max(childAlpha, evaluation);
				}
			}
		}
		else {
			evaluation = INT_MAX;
			int childBeta = beta;

			for (int i = 0; i < state.node->movements.size(); ++i) {
				std::pair<int, int> move = state.node->movements[i];
				std::tuple<int, int, int> moveWithInvoker(currentCharacter.id, move.first, move.second);

				State childState(state);
				std::string childPath = extendPath(path, moveWithInvoker);

				// TODO: probably should check if move is possible before making copy os state (on original state?)
				if (childState.makeMove(moveWithInvoker)) {
					int childAlphaBeta = runAlphaBeta(alpha, childBeta, treeDepth - 1, childPath, childState);
					evaluation = std::min(evaluation, childAlphaBeta);
					childBeta = std::min(childBeta, evaluation);
				}
			}
		}
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

std::string AI::extendPath(std::string& path, std::tuple<int, int, int>& move)
{
	int invokerId = std::get<0>(move);
	int movementId = std::get<1>(move);
	int targetId = std::get<2>(move);

	// hashedMove (8 bits) = invokerId: 0-7 (3 bits) | movementId: 0-3 (2 bits) | targetId: 0-7 (3 bits)
	char hashedMove = invokerId << 5 | movementId << 3 | targetId;
	return path + hashedMove;
}
