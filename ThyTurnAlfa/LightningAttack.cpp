#include "LightningAttack.hpp"
#include "Character.hpp"
#include "Wet.hpp"

bool LightningAttack::invoke(Character& who, Character& on_whom)
{
    if (!isExecutable(who, on_whom)) return false;
    
    applyDamage(who, on_whom);

    
}

std::string LightningAttack::getCost()
{
    return std::string();
}

void LightningAttack::applyDamage(Character& who, Character& on_whom)
{
    bool is_wet = false;
    for (auto& e : on_whom.activeEffects)
    {
        if (dynamic_cast<Wet*>(e.get()))
        {
            is_wet = true;
            break;
        }
    }

    
}