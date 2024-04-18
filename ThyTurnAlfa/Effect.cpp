#include "Character.hpp"
#include "Effect.hpp"

bool Effect::isTypeOf(Effect& e)
{
    return this->name.compare(e.name) == 0;
}
