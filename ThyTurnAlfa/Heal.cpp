#include "Heal.hpp"

bool Heal::isInvokable(Character& who, Character& on_whom)
{
	return DefensiveMovement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

bool Heal::individualAction(Character& who, Character& on_whom)
{
	who.mp -= this->cost;
	on_whom.currentHp += hpBoost;
	if (on_whom.currentHp > on_whom.hp)
	{
		on_whom.currentHp = on_whom.hp;
	}
}
