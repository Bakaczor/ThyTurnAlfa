#include "Burning.hpp"
#include "Frozen.hpp"

Frozen::Frozen():TemporaryDamageModifier(Const::Frozen::FROZEN_EFFECT_NAME,
										 Const::Frozen::FROZEN_DEFAULT_ATK_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DEF_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DURATION) {}

bool Frozen::addTo(Character& affected, int duration, int atk_drop, int def_drop)
{
	bool apply = true;
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Frozen*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
		else if (dynamic_cast<Burning*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
			apply = false;
		}
	}
	
	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Frozen>());
	}
	return true;
}
