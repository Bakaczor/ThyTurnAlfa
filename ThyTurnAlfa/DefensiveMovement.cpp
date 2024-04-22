#include "DefensiveMovement.hpp"
#include "Character.hpp"

bool DefensiveMovement::isInvokable(Character& who, Character& on_whom)
{
    return who.mp >= cost;
}
