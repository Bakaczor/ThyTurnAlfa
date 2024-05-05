#include "Cure.hpp"
#include "Bleeding.hpp"
#include "Character.hpp"
#include "Const.hpp"

Cure::Cure(): DefensiveMovement(Const::Cure::CURE_MOVEMENT_NAME,
                                        Const::Cure::CURE_DEFAULT_COST) {}

bool Cure::individualAction(Character& who, Character& on_whom) {
    DefensiveMovement::individualAction(who, on_whom);

    std::erase_if(on_whom.activeEffects, [&on_whom](std::unique_ptr<Effect>& e) {
        if (dynamic_cast<Bleeding*>(e.get())) {
            e->cancelFrom(on_whom);
            return true;
        }
        return false; });
    return true;
}
