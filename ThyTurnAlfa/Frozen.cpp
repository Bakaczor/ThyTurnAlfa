#include "Frozen.hpp"
#include "Burning.hpp"
#include "Cold.hpp"
#include "Wet.hpp"
#include "Character.hpp"
#include "Const.hpp"

Frozen::Frozen():TemporaryDamageModifier(Const::Frozen::FROZEN_EFFECT_NAME,
										 Const::Frozen::FROZEN_DEFAULT_ATK_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DEF_DROP,
										 Const::Frozen::FROZEN_DEFAULT_DURATION) {}

std::unique_ptr<Effect> Frozen::clone()
{
	return std::move(std::make_unique<Frozen>());
}

bool Frozen::addTo(Character& affected) {
	bool apply = true;
	std::erase_if(affected.activeEffects, [&affected, &apply](auto& e) {
		if (dynamic_cast<Frozen*>(e.get()) ||
			dynamic_cast<Cold*>(e.get()) || 
			dynamic_cast<Wet*>(e.get())) {
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
