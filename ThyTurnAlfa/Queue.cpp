#include "Queue.hpp"
#include "Player.h"

#include <climits>

Tuple::Tuple(Character* t_character, int t_baseATV):
	character{ t_character }, baseATV{ t_baseATV }, currentATV{ t_baseATV } {}

bool Tuple::operator < (const Tuple& rhs) const {
	return currentATV > rhs.currentATV;
}

Queue::Queue() { }

Queue::Queue(std::array<std::unique_ptr<Player>, 2>& players) {
	for (std::unique_ptr<Player>& player : players) {
		for (Character& character : player->party) {
			int atv = INT_MAX / character.getSpd();
			emplace(&character, atv);
		}
	}
}

Character& Queue::peek() {
	for (int i = 0; i < c.size(); ++i) {
		Tuple currentCharacter = top();

		if (currentCharacter.currentATV != 0) {
			for (int j = 1; j < c.size(); ++j) {
				c[j].currentATV -= currentCharacter.currentATV;
			}
		}

		pop();
		emplace(currentCharacter.character, currentCharacter.baseATV);

		if (currentCharacter.character->isAlive) {
			return *currentCharacter.character;
		}
	}

	throw std::exception("Everyone has died");
}
