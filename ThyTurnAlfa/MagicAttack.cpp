#include "MagicAttack.hpp"
#include "Character.hpp"
#include "sstream"

bool MagicAttack::isExecutable(Character& who, Character& on_whom)
{
    return Attack::isExecutable(who, on_whom) && on_whom.mp >= this->cost;
}

int MagicAttack::getCost()
{
    return this->cost;
}

