#include "DefensiveMovement.hpp"
#include "Character.hpp"

bool DefensiveMovement::invoke(Character& who, Character& on_whom)
{
    if (!isExecutable) return false;



    return true;
}

bool DefensiveMovement::isExecutable(Character& who, Character& on_whom)
{
    return who.mp >= cost;
}
