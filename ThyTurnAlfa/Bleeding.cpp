#include "Bleeding.hpp"

Bleeding::Bleeding(int duration, int dmg_per_round):
	TemporaryDamagePerRound(Const::Bleeding::BLEEDING_EFFECT_NAME, duration, dmg_per_round) {};

bool Bleeding::addTo(Character& affected, int duration, int damage_per_round)
{
	for (auto it = affected.activeEffects.begin(); it != affected.activeEffects.end(); it++)
	{
		if (dynamic_cast<Bleeding*>(it->get()))
		{
			(*it)->cancelFrom(affected);
			affected.activeEffects.erase(it);
		}
	}

	affected.activeEffects.emplace_back(std::make_unique<Bleeding>(duration, damage_per_round));

	return true;
}
