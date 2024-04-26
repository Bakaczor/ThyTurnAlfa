#include "Queue.h"

Queue::Queue()
{
}

Queue::Queue(std::vector<Player>& players)
{
	for (Player& player : players) {
		for (Character& character : player.party) {
			int atv = INT_MAX / character.spd;
			emplace(character, atv);
		}
	}
}

Character& Queue::peek()
{
	for (int i = 0; i < c.size(); ++i) {
		Tuple currentCharacter = top();

		if (currentCharacter.currentATV != 0) {
			for (int j = 1; j < c.size(); ++j) {
				c[j].currentATV -= currentCharacter.currentATV;
			}
		}

		pop();
		emplace(*currentCharacter.character, currentCharacter.baseATV);

		if (currentCharacter.character->isAlive) {
			return *currentCharacter.character;
		}
	}

	throw std::exception("Everyone has died");
}
