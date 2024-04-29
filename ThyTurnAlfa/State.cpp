#include "State.hpp"

State::State(Queue& t_queue, std::vector<Character>& t_characters) :
	characters{ t_characters }, queue{ t_queue, characters }, node{ nullptr }, m_currentMove{ 0 } {}

void State::extractNode(std::map<std::string, Node>& transpositionTable, std::string& key)
{
	transpositionTable.try_emplace(key);
	node = &transpositionTable[key];
}