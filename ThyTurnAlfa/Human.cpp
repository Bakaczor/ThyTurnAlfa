#include "Human.hpp"

Human::Human(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds):
	Player(availibleCharacters, curChrIds) {}

bool Human::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	// TODO
	return false;
}