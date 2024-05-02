#include "Wet.hpp"
#include "Burning.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"
#include "Character.hpp"
#include "Const.hpp"

Wet::Wet(): ActionlessEffect(Const::Wet::WET_EFFECT_NAME, Const::Wet::WET_DEFAULT_DURATION) {}

std::unique_ptr<Effect> Wet::clone()
{
	return std::move(std::unique_ptr<Wet>());
}
;

bool Wet::addTo(Character& affected) {
	bool apply = true;
	bool apply_frozen = false;
	std::erase_if(affected.activeEffects, [&affected, &apply, &apply_frozen](auto& e) {
		if (dynamic_cast<Wet*>(e.get()) ||
			dynamic_cast<Burning*>(e.get())) {
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
	} else if (apply_frozen) {
		Frozen::addTo(affected);
	}
	return true;
}