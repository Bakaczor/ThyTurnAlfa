#include "TemporaryDamagePerRound.hpp"
#include "Character.hpp"

TemporaryDamagePerRound::TemporaryDamagePerRound(std::string name, int duration, int dmgPerRound):
	Effect(name, duration), dmgPerRound{ dmgPerRound } {};

bool TemporaryDamagePerRound::nextRound(Character& affected) {
	affected.applyDamage(dmgPerRound);
	return elapsed();
}
