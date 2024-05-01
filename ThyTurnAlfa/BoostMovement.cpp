#include "BoostMovement.hpp"
#include "Boost.hpp"
#include "Character.hpp"
#include "Const.hpp"

BoostMovement::BoostMovement():
	DefensiveMovement(Const::BoostMovement::BOOST_MOVEMENT_NAME,
					  Const::BoostMovement::BOOST_MOVEMENT_DEFAULT_COST) {}

bool BoostMovement::isInvokable(const Character& who, const Character& on_whom) const {
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

void BoostMovement::addEffects(Character& on_whom) {
	Boost::addTo(on_whom);
}