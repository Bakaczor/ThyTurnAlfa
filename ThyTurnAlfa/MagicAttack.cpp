#include "MagicAttack.hpp"
#include "Character.hpp"
#include "sstream"

bool MagicAttack::isInvokable(Character& who, Character& on_whom)
{
    return Attack::isInvokable(who, on_whom) && on_whom.mp >= this->cost;
}

int MagicAttack::getCost()
{
    return this->cost;
}

