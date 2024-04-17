#pragma once

#include "ActionlessEffect.hpp"

bool ActionlessEffect::nextRound(Character& affected)
{
	return elapsed();
}

bool ActionlessEffect::remove(Character& affected)
{
	return true;
}
