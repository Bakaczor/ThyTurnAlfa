#include "AI.hpp"

AI::AI(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds):
	Player(availibleCharacters, curChrIds) {}

std::optional<Message> AI::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	// TODO
	return Message{ "Megumin", "what", "Aqua" };
}