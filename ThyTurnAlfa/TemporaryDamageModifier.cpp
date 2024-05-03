#include "TemporaryDamageModifier.hpp"
#include "Character.hpp"

TemporaryDamageModifier::TemporaryDamageModifier(std::string name, int duration, int atkModifier, int defModifier):
	Effect(name, duration), atkModifier{ atkModifier }, defModifier{ defModifier } {};

bool TemporaryDamageModifier::nextRound(Character& affected) {
	if (elapsedRounds == 0) {
		affected.wAtk += atkModifier;
		affected.wDef += defModifier;
	}
	if (elapsedRounds == duration) {
		cancelFrom(affected);
	}
	return elapsed();
}

bool TemporaryDamageModifier::cancelFrom(Character& affected) {
	affected.wAtk -= atkModifier;
	affected.wDef -= defModifier;
	return true;
}