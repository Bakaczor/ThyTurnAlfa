#include "AI.hpp"
#include "Queue.hpp"
#include "Const.hpp"

AI::AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds, int treeHeight, Queue* pQueue):
	Player(availibleCharacters, curChrIds), m_treeHeight{ treeHeight }, m_pGlobalQueue{ pQueue } {}

std::optional<Message> AI::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	// arrange
	m_transpositionTable.clear();
	m_bestMove = std::tuple(-1, -1, -1);
	std::unordered_map<int, Character> characters;
	for (std::unique_ptr<Player>& p : players) {
		for (Character& c : p->party) {
			characters.insert({ c.id, c });
		}
	}
	State state(*m_pGlobalQueue, characters);

	// algorithm evaluation
	int evaluation = state.evaluate(id);
	evaluation = runAB_SSS(who.id, evaluation, m_treeHeight, state);
	
	// invoke movement
	int invokerId = std::get<0>(m_bestMove);
	int movementId = std::get<1>(m_bestMove);
	int targetId = std::get<2>(m_bestMove);
	if (invokerId != -1) {
		int targetPlayerId = characters[targetId].getPlayerId();
		int targetCharacterId = targetId % Const::Sizes::MAX_PARTY_SIZE;
		who.movements[movementId]->invoke(who, players[targetPlayerId].get()->party[targetCharacterId]);
		return Message(who.getName(), who.movements[movementId]->name, players[targetPlayerId].get()->party[targetCharacterId].getName());
	}
	return std::nullopt;
}

int AI::runAB_SSS(int characterId, int firstEval, int treeHeight, State& state)
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
		evaluation = runAlphaBeta(characterId, bound - 1, bound, treeHeight, path, state);
		if (evaluation < bound) {
			upperbound = evaluation;
		}
		else {
			lowerbound = evaluation;
		}
	}

	return evaluation;
}

int AI::runAlphaBeta(int characterId, int alpha, int beta, int treeDepth, std::string& path, State& state)
{
	int evaluation = INT_MIN;

	// node extraction
	bool nodeSearched = state.extractNode(characterId, m_transpositionTable, path);
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
		evaluation = state.evaluate(id);
	}
	else {
		// MAX_NODE
		if (id == state.characters[characterId].getPlayerId()) {
			evaluation = INT_MIN;
			int childAlpha = alpha;
			
			for (int i = 0; i < state.node->movements.list.size(); ++i) {
				std::pair<int, int> move = state.node->movements.list[i];
				std::tuple<int, int, int> moveWithInvoker(characterId, move.first, move.second);

				State childState(state);
				std::string childPath = extendPath(path, moveWithInvoker);
				
				// TODO: probably should check if move is possible before making copy os state (on original state?)
				if (childState.makeMove(moveWithInvoker)) {
					int childAlphaBeta = runAlphaBeta(childState.queue.peek().id, childAlpha, beta, treeDepth - 1, childPath, childState);

					// store best move
					if (treeDepth == m_treeHeight && childAlphaBeta > evaluation) {
						m_bestMove = moveWithInvoker;
					}

					evaluation = std::max(evaluation, childAlphaBeta);
					childAlpha = std::max(childAlpha, evaluation);
				}
			}
		}
		// MIN_NODE
		else {
			evaluation = INT_MAX;
			int childBeta = beta;

			for (int i = 0; i < state.node->movements.list.size(); ++i) {
				std::pair<int, int> move = state.node->movements.list[i];
				std::tuple<int, int, int> moveWithInvoker(characterId, move.first, move.second);

				State childState(state);
				std::string childPath = extendPath(path, moveWithInvoker);

				// TODO: probably should check if move is possible before making copy os state (on original state?)
				if (childState.makeMove(moveWithInvoker)) {
					int childAlphaBeta = runAlphaBeta(childState.queue.peek().id, alpha, childBeta, treeDepth - 1, childPath, childState);
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
