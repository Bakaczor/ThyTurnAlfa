#include "Burning.hpp"
#include "Frozen.hpp"

Frozen::Frozen():TemporaryDamageModifier(Const::Frozen::FROZEN_EFFECT_NAME,
										 Const::Frozen::FROZEN_DEFAULT_ATK_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DEF_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DURATION) {}

bool Frozen::addTo(Character& affected) {
	bool apply = true;
	std::erase_if(affected.activeEffects, [&affected, &apply](auto& e) {
		if (dynamic_cast<Frozen*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		} else if (dynamic_cast<Burning*>(e.get())) {
			e->cancelFrom(affected);
			apply = false;
			return true;
		} 
		return false;
		});
	
	if (apply) {
		affected.activeEffects.emplace_back(std::make_unique<Frozen>());
	}
	return true;
}
