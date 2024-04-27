#include "Player.h"

unsigned int Player::m_count = 0;

Player::Player(std::vector<Character>& party) : party(&party) {
	++m_count;
	id = 0; // ???
}

bool Player::move(Character& character, std::array<Player, 2>& players)
{
	return true;
}