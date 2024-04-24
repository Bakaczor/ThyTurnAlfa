#include "Character.hpp"

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		if (!(*it)->nextRound(*this))
		{
			(*it)->cancelFrom(*this);
			activeEffects.erase(it);
		}
	}
	return true;
}

void Character::detachEffects()
{
	for (auto& e : activeEffects)
	{
		e->cancelFrom(*this);
	}

	activeEffects.clear();
}
