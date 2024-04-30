#include "ActionlessEffect.hpp"
#include "Character.hpp"

ActionlessEffect::ActionlessEffect(std::string name, int duration): Effect(name, duration) {};

bool ActionlessEffect::nextRound(Character& affected) { return elapsed(); }