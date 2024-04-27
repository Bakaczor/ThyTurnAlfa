#include "Player.hpp"

unsigned int Player::m_count = 0;

Player::Player(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds): id{ m_count++ } {
	for (const int& i : curChrIds) {
		party.push_back(&availibleCharacters[i]);
	}
}