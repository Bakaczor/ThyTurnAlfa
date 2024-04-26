#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"

Cold::Cold(): ActionlessEffect(Const::Cold::COLD_EFFECT_NAME, Const::Cold::COLD_DEFAULT_DURATION) {}

bool Cold::addTo(Character& affected) {
	bool apply = true;
	bool apply_frozen = false;
	// TODO: implement adding to frozen
	std::erase_if(affected.activeEffects, [&affected, &apply, &apply_frozen](std::unique_ptr<Effect>& e) {
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
		affected.activeEffects.emplace_back(std::make_unique<Frozen>());
	}

	return true;
}
