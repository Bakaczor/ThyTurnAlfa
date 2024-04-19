#include "Character.hpp"
#include "Effect.hpp"
#include "Movement.hpp"

bool Character::addEffect(Effect& c) {
	return false;
}

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		if (!(*it)->nextRound(*this))
		{
			activeEffects.erase(it);
		}
	}
	return true;
}
