#include "LightningAttack.hpp"
#include "Character.hpp"
#include "Wet.hpp"

void LightningAttack::applyDamage(Character& who, Character& on_whom)
{
    bool is_wet;
    for (auto& e : on_whom.activeEffects)
    {
        if (dynamic_cast<Wet*>(e.get()))
        {
            is_wet = true;
        }
    }
    if (is_wet)
    {
        int 
    }
}
