#include "Character.hpp"
#include "Movement.hpp"

bool Movement::invoke(Character& who, Character& on_whom)
{
	if (!isInvokable(who, on_whom)) return false;

	individualAction(who, on_whom);

	addEffects(who, on_whom);

	return true;
}
