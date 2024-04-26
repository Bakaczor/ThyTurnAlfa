#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"
#include "Wet.hpp"

Wet::Wet(): ActionlessEffect(Const::Wet::WET_EFFECT_NAME, Const::Wet::WET_DEFAULT_DURATION) {};

bool Wet::addTo(Character& affected) {
	bool apply = true;
	bool apply_frozen = false;
	std::erase_if(affected.activeEffects, [&affected, &apply, &apply_frozen](auto& e) {
		if (dynamic_cast<Wet*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		} else if (dynamic_cast<Cold*>(e.get())) {
			e->cancelFrom(affected);
			apply = false;
			apply_frozen = true;
			return true;
		}
		return false; });

	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Wet>());
	}
	return true;
}