#include "Cure.hpp"

bool Cure::individualAction(Character& who, Character& on_whom)
{
    for (auto it = on_whom.activeEffects.begin(); it != on_whom.activeEffects.end(); it++)
    {
        if (dynamic_cast<Bleeding*>(it->get()))
        {
            it->get()->cancelFrom(on_whom);
            on_whom.activeEffects.erase(it);
        }
    }
    return true;
}
