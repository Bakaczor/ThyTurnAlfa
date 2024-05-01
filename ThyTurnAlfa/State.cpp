#include "State.hpp"
#include "Character.hpp"

State::State(Queue& t_queue, std::unordered_map<int, Character>& t_characters) :
	characters{t_characters}, queue{t_queue, t_characters}, node{nullptr} {}

bool State::extractNode(std::unordered_map<std::string, Node>& transpositionTable, std::string& key)
{
	bool nodeSearched = false;

	if (transpositionTable.contains(key)) {
		nodeSearched = true;
	}
	else {
		transpositionTable.emplace(key, Node());
		// TODO: sort movements
	}

	node = &transpositionTable[key];
	return nodeSearched;
}

bool State::makeMove(std::tuple<int, int, int>& move)
{
	int invokerId = std::get<0>(move);
	int movementId = std::get<1>(move);
	int targetId = std::get<2>(move);
	
	return characters[invokerId].movements[movementId]->invoke(characters[invokerId], characters[targetId]);
}
