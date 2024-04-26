#include "Boost.hpp"

Boost::Boost(): TemporaryDamageModifier(Const::Boost::BOOST_EFFECT_NAME,
										Const::Boost::BOOST_DEFAULT_DURATION,
										Const::Boost::BOOST_DEFAULT_ATK_BOOST,
										Const::Boost::BOOST_DEFAULT_DEF_BOOST) {}

bool Boost::addTo(Character& affected) {
	std::erase_if(affected.activeEffects, [&affected](std::unique_ptr<Boost>& e) {
		if (dynamic_cast<Boost*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		}
		return false;
		});

	affected.activeEffects.emplace_back(std::make_unique<Boost>());
	return true;
}
