#include "Character.hpp"
#include "Effect.hpp"
#include "Movement.hpp"

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		if (!(*it)->nextRound(*this))
		{
			it->get()->cancelFrom(*this);
			activeEffects.erase(it);
		}
	}
	return true;
}

void Character::detachEffects()
{
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		it->get()->cancelFrom(*this);
		activeEffects.erase(it);
	}
}
