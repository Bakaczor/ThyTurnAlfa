#include "Burning.hpp"

Burning::Burning(): TemporaryDamagePerRound(Const::Burning::BURNING_EFFECT_NAME, 
											Const::Burning::BURNING_DEFAULT_DURATION,
											Const::Burning::BURNING_DEFAULT_DAMAGE_PER_ROUND) {};

bool Burning::addTo(Character& affected) {
	bool apply = true;
	std::erase_if(affected.activeEffects, [&affected, &apply](auto& e) {
		if (dynamic_cast<Burning*>(e.get()))
		{
			e->cancelFrom(affected);
			return true;
		}
		else if (dynamic_cast<Wet*>(e.get())) {
			apply = false;
			return false;
		}
		return false;
		});

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Burning>());
	}
	return true;
}
