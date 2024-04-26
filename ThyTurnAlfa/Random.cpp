#include "Random.h"

Random::Random(std::vector<Character>& party) : Player(party)
{
}

bool Random::move(Character& character, std::vector<Player>& players)
{
	std::vector<std::pair<std::unique_ptr<Movement>*, Character*>> possibleMoves;
	for (auto& player : players) {
		for (auto& character : player.party) {
			for (auto& movement : character.movements) {
				possibleMoves.push_back(std::make_pair(&movement, &character));
			}
		}
	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(possibleMoves.begin(), possibleMoves.end(), g);
	for (auto& move : possibleMoves) {
		if (move.first->get()->invoke(character, *move.second)) {
			return true;
		}
	}
	return false;
}
