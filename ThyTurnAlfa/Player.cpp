#include "Player.hpp"

unsigned int Player::m_count = 0;

Player::Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds): id{ m_count++ } {
	for (int i = 0; i < curChrIds.size(); i++) {
		int& k = curChrIds.at(i);
		if (k == -1) { continue; }
		Character newCharacter(availibleCharacters[k]);
		newCharacter.id = id * curChrIds.size() + i;
		if (!newCharacter.loadImage()) {
			throw std::exception("Image loading exception");
		}
		party.push_back(newCharacter);
	}
}