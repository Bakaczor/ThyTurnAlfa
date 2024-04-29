#include "Const.hpp"
#include "Human.hpp"

Human::Human(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds, SceneManager* context):
	Player(availibleCharacters, curChrIds), m_context{ context } {}

std::optional<Message> Human::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	auto move = m_context->chooseMove(who.getPlayerId());
	auto& party = players.at(move.second / Const::Sizes::MAX_PARTY_SIZE)->party;
	auto it = std::find_if(party.begin(), party.end(), [&move](const Character& c) {
		return move.second == c.id;
	});
	return Message{ who.getName(), move.first ,  it->getName() };
}