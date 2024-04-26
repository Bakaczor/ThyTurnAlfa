#include "BoostMovement.hpp"

bool BoostMovement::isInvokable(Character& who, Character& on_whom) {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

void BoostMovement::addEffects(Character& who, Character& on_whom) {
	Boost::addTo(on_whom,
				 Const::BoostMovement::BOOST_MOVEMENT_DEFAULT_EFFECT_DURATION,
				 Const::BoostMovement::BOOST_MOVEMENT_DEFAULT_ATK_BOOST_VALUE,
				 Const::BoostMovement::BOOST_MOVEMENT_DEFAULT_DEF_BOOST_VALUE);
}