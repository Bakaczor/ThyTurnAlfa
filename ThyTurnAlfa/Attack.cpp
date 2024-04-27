#include "Attack.hpp"
#include "Shield.hpp"

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
    for (auto it = on_whom.activeEffects.begin(); it != on_whom.activeEffects.end(); it++) {
        Shield* ptr = dynamic_cast<Shield*>(it->get());
        if (ptr) {
            if (dmg > ptr->hp) {
                dmg -= ptr->hp;
                ptr->hp = 0;
            } else {
                ptr->hp -= dmg;
                dmg = 0;
                return true;
            }
        }
    }
    if (dmg > 0) {
        if (dmg >= on_whom.currentHp) {
            on_whom.currentHp = 0;
            on_whom.detachEffects(); // on_whom died so all effects must be detached
            on_whom.isAlive = false;
            return false;
        } else {
            on_whom.currentHp -= dmg;
        }
    }
    return true;
}
