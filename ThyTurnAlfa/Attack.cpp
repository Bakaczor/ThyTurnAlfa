#include "Attack.hpp"
#include "Shield.hpp"
#include "Character.hpp"
#include "Utils.hpp"

Attack::Attack(std::string&& name, int w_move, int w_pierce): 
    Movement(std::move(name), TargetType::Enemy), 
    wMove{ Utils::percent(w_move) }, 
    wPierce{ Utils::percent(w_pierce) } {}

int Attack::computeDmg(Character& who, Character& on_whom) {
    float formula_prefix = wMove * who.getAtk() * (1.0f + Utils::percent(who.wAtk));
    float formula_suffix = 1.0f - Utils::percent(on_whom.getDef()) *
        (1.0f + Utils::percent(on_whom.wDef)) * (1.0f - wPierce);
    if (formula_suffix < 0 || formula_prefix < 0) {
        return 0;
    }
    return formula_prefix * formula_suffix;
}

bool Attack::isInvokable(Character& who, Character& on_whom) {
    return Movement::isInvokable(who, on_whom) && on_whom.currentHp > 0;
}

bool Attack::individualAction(Character& who, Character& on_whom) {
    int dmg = computeDmg(who, on_whom);
    on_whom.applyDamage(dmg);
    return true;
}
