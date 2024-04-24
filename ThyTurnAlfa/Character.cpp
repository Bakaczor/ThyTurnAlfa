#include "Character.hpp"

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		if (!(*it)->nextRound(*this))
		{
			(*it)->cancelFrom(*this);
			// activeEffects.erase(it);
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
	//std::for_each(activeEffects.begin(), activeEffects.end(), [this](std::unique_ptr<Effect>& e)
	//	{
	//		e->cancelFrom(*this);
	//	});
	activeEffects.clear();
}
