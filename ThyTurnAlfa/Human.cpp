#include "Const.hpp"
#include "Human.hpp"

Human::Human(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds, SceneManager* context):
	Player(availibleCharacters, curChrIds), m_context{ context } {}

std::optional<Message> Human::move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) {
	// TODO : add for loop (number of tries)
	// {
	auto move = m_context->chooseMove(who);
	if (!std::get<2>(move)) {
		auto what = std::find_if(who.movements.begin(), who.movements.end(),
								 [&move](const std::shared_ptr<Movement>& m) {
			return  std::get<0>(move) == m->name;
		});
		auto& party = players.at(std::get<1>(move) / Const::Sizes::MAX_PARTY_SIZE)->party;
		int i;
		for (i = 0; i < party.size(); i++) {
			if (std::get<1>(move) == party[i].id) { break; }
		}
		if ((*what)->invoke(who, party[i])) {
			return Message{ who.getName(), std::get<0>(move), party[i].getName() };
		}
	}
	// }
	return std::nullopt;
}