#include "Character.hpp"
#include "MagicAttack.hpp"

MagicAttack::MagicAttack(std::string&& name, int cost, int w_move, int w_pierce):
    Attack(std::move(name), w_move, w_pierce), cost{ cost } {}

int MagicAttack::getCost() {
    return cost;
}

bool MagicAttack::isInvokable(Character& who, Character& on_whom) {
    return Attack::isInvokable(who, on_whom) && on_whom.mp >= cost;
}

