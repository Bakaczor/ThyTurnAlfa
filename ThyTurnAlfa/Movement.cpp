#include "Character.hpp"
#include "Movement.hpp"

bool Movement::invoke(Character& who, Character& on_whom)
{
	if (!isInvokable(who, on_whom)) return false;

	if (!individualAction(who, on_whom)) return true;

	addEffects(who, on_whom);

	return true;
}

bool Movement::isInvokable(Character& who, Character& on_whom)
{
	// TODO: Check whether both Characters fit the target value
	return true;
}
