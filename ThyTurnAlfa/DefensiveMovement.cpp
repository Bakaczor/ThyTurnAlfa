#include "DefensiveMovement.hpp"

int DefensiveMovement::getCost()
{
    return this->cost;
}

bool DefensiveMovement::isInvokable(Character& who, Character& on_whom)
{
    return Movement::isInvokable(who, on_whom) && who.mp >= cost;
}
