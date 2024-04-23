#include "LightningAttack.hpp"
#include "Character.hpp"
#include "Wet.hpp"

bool LightningAttack::individualAction(Character& who, Character& on_whom)
{
    bool is_wet;
    for (auto& e : on_whom.activeEffects)
    {
        if (dynamic_cast<Wet*>(e.get()))
        {
            is_wet = true;
        }
    }

    int old_atk = 0;
    if (is_wet)
    {
        old_atk = who.wAtk;
        who.wAtk += 100;
    }
    Attack::individualAction(who, on_whom);
    if (is_wet)
    {
        who.wAtk = old_atk;
    }
    return true;
}
