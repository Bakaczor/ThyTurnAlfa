#include "MagicAttack.hpp"
#include "Character.hpp"
#include "sstream"

bool MagicAttack::isExecutable(Character& who, Character& on_whom)
{
    return Attack::isExecutable(who, on_whom) && on_whom.mp >= this->cost;
}

std::string MagicAttack::getCost()
{
    return m_string_cost;
}

std::string MagicAttack::intToString(int x)
{
    std::stringstream sstream;
    sstream << x;
    std::string result;
    sstream >> result;
    return result;
}
