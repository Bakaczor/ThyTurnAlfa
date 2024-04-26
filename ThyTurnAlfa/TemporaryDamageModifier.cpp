#include "TemporaryDamageModifier.hpp"

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
	affected.atk -= atkModifier;
	affected.def -= defModifier;
	return true;
}