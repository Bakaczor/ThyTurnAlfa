#include "TemporaryDamagePerRound.hpp"
#include "Character.hpp"

TemporaryDamagePerRound::TemporaryDamagePerRound(std::string name, int duration, int dmgPerRound):
	Effect(name, duration), dmgPerRound{ dmgPerRound } {};

bool TemporaryDamagePerRound::nextRound(Character& affected) {
	if (affected.currentHp <= dmgPerRound) {
		affected.currentHp = 0;
		affected.isAlive = 0;
	}
	else {
		affected.currentHp -= dmgPerRound;
	}
	return elapsed();
}
