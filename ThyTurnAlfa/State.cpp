#include "State.hpp"

State::State(Queue& t_queue, std::vector<Character>& t_characters) :
	characters{ t_characters }, queue{ t_queue, characters }, node{ nullptr }, m_currentMove{ 0 } {}

bool State::extractNode(std::map<std::string, Node>& transpositionTable, std::string& key)
{
	bool nodeSearched = false;

	if (transpositionTable.contains(key)) {
		nodeSearched = true;
	}
	else {
		transpositionTable.emplace(key);
	}

	node = &transpositionTable[key];
	return nodeSearched;
}