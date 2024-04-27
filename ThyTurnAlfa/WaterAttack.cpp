#include "WaterAttack.hpp"
#include "Wet.hpp"

WaterAttack::WaterAttack(): MagicAttack(Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME,
										Const::WaterAttack::WATER_ATTACK_DEFAULT_COST,
										Const::WaterAttack::WATER_ATTACK_DEFAULT_WEIGHT) {}

void WaterAttack::addEffects(Character& on_whom) {
	Wet::addTo(on_whom);
}