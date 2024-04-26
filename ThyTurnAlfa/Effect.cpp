#include "Effect.hpp"

bool Effect::cancelFrom(Character& affected) { return true; }

bool Effect::elapsed() { return elapsedRounds++ < duration; };