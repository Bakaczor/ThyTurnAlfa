#include "Burning.hpp"
#include "Cold.hpp"
#include "Wet.hpp"

Burning::Burning(): TemporaryDamagePerRound(Const::Buring::BURNING_EFFECT_NAME, 
											Const::Buring::BURNING_DEFAULT_DURATION,
											Const::Buring::BURNING_DEFAULT_DAMAGE_PER_ROUND) {};

bool Burning::addTo(Character& affected) {
	bool apply = true;
	std::erase_if(affected.activeEffects, [&affected, &apply](std::unique_ptr<Burning>& e) {
		if (dynamic_cast<Burning*>(e.get()))
		{
			e->cancelFrom(affected);
			return true;
		}
		else if (dynamic_cast<Wet*>(e.get())) {
			e->cancelFrom(affected);
			apply = false;
			return true;
		}
		return false;
		});

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Burning>());
	}
	return true;
}
