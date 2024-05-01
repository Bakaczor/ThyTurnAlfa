#include "Player.hpp"

unsigned int Player::count = 0;

Player::Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds): id{ count++ } {
	for (int i = 0; i < curChrIds.size(); i++) {
		int& k = curChrIds.at(i);
		if (k == -1) { continue; }
		Character newCharacter(availibleCharacters[k]);
		newCharacter.id = id * static_cast<unsigned int>(curChrIds.size()) + i; 
		party.push_back(newCharacter);
	}
}