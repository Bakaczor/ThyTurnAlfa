#include "IceAttack.hpp"

IceAttack::IceAttack(): MagicAttack(Const::IceAttack::ICE_ATTACK_MOVEMENT_NAME,
									Const::IceAttack::ICE_ATTACK_DEFAULT_COST,
									Const::IceAttack::ICE_ATTACK_DEFAULT_WEIGHT,
									Const::IceAttack::ICE_ATTACK_DEFAULT_PIERCING_WEIGHT) {}

void IceAttack::addEffects(Character& on_whom)
{
	Cold::addTo(on_whom);
}
