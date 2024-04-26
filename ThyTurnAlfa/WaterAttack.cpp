#include "WaterAttack.hpp"

WaterAttack::WaterAttack(): MagicAttack(Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME,
										Const::WaterAttack::WATER_ATTACK_DEFAULT_COST,
										Const::WaterAttack::WATER_ATTACK_DEFAULT_WEIGHT) {}

void WaterAttack::addEffects(Character& who, Character& on_whom) {
	Wet::addTo(on_whom,
			   Const::WaterAttack::WATER_ATTACK_DEFAULT_EFFECT_DURATION,
			   Const::WaterAttack::WATER_ATTACK_DEFAULT_FROZEN_EFFECT_DURATION);
}