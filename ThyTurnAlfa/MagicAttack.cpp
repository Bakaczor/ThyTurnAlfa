#include "MagicAttack.hpp"
#include "Character.hpp"

MagicAttack::MagicAttack(std::string&& name, int cost, int w_move, int w_pierce):
    Attack(std::move(name), w_move, w_pierce), cost{ cost } {}

int MagicAttack::getCost() {
    return cost;
}

bool MagicAttack::isInvokable(const Character& who, const Character& on_whom) const {
    return Attack::isInvokable(who, on_whom) && who.currentMp >= cost;
}

bool MagicAttack::individualAction(Character& who, Character& on_whom)
{
    who.currentMp -= cost;
    return Attack::individualAction(who, on_whom);
}

