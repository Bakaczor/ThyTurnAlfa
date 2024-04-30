#include "Random.hpp"
#include <random>

Random::Random(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds):
	Player(availibleCharacters, curChrIds) {}

std::optional<Message> Random::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	std::vector<std::pair<std::shared_ptr<Movement>*, Character*>> possibleMoves;
	for (auto& player : players) {
		for (Character& character : player->party) {
			for (auto& movement : character.movements) {
				possibleMoves.push_back(std::make_pair(&movement, &character));
			}
		}
	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(possibleMoves.begin(), possibleMoves.end(), g);
	for (auto& move : possibleMoves) {
		if (move.first->get()->invoke(who, *move.second)) {
			return Message{ "Megumin", "what", "Aqua" };
		}
	}
	return std::nullopt;
}
