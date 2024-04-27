#include "LightningAttack.hpp"
#include "Wet.hpp"

LightningAttack::LightningAttack(): MagicAttack(Const::LightningAttack::LIGHTNING_ATTACK_MOVEMENT_NAME,
                                                Const::LightningAttack::LIGHTNING_ATTACK_DEFAULT_COST,
                                                Const::LightningAttack::LIGHTNING_ATTACK_DEFAULT_WEIGHT) {}

bool LightningAttack::individualAction(Character& who, Character& on_whom) {
    bool is_wet = false;
    for (auto& e : on_whom.activeEffects) {
        if (dynamic_cast<Wet*>(e.get())) {
            is_wet = true;
            break;
        }
    }

    int old_atk = 0;
    if (is_wet) {
        old_atk = who.wAtk;
        who.wAtk += 100;
    }

    Attack::individualAction(who, on_whom);
    if (is_wet) {
        who.wAtk = old_atk;
    }
    return true;
}
