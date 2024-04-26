#include "Boost.hpp"

Boost::Boost(): TemporaryDamageModifier(Const::Boost::BOOST_EFFECT_NAME,
										Const::Boost::BOOST_DEFAULT_DURATION,
										Const::Boost::BOOST_DEFAULT_ATK_BOOST,
										Const::Boost::BOOST_DEFAULT_DEF_BOOST) {}

bool Boost::addTo(Character& affected, int duration, int atkBoost, int defBoost) {
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++) {
		if (dynamic_cast<Boost*>(it->get())) {
			it->get()->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}
	affected.activeEffects.emplace_back(std::make_unique<Boost>());
	return true;
}
