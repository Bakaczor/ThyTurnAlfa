#include "Cold.hpp"
#include "Burning.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"
#include "Const.hpp"
#include "Character.hpp"

Cold::Cold(): ActionlessEffect(Const::Cold::COLD_EFFECT_NAME, Const::Cold::COLD_DEFAULT_DURATION) {}

std::unique_ptr<Effect> Cold::clone()
{
	return std::make_unique<Cold>(*this);
}

bool Cold::addTo(Character& affected) {
	bool apply = true;
	bool apply_frozen = false;
	// TODO: implement adding to frozen
	std::erase_if(affected.activeEffects, [&affected, &apply, &apply_frozen](auto& e) {
		if (dynamic_cast<Cold*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		} else if (dynamic_cast<Wet*>(e.get())) {
			e->cancelFrom(affected);
			apply = false;
			apply_frozen = true;
			return true;
		} else if (dynamic_cast<Burning*>(e.get())) {
			apply = false;
			return true;
		}
		return false;
		});

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Cold>());
	} else if (apply_frozen) {
		Frozen::addTo(affected);
	}

	return true;
}
