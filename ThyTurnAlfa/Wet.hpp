#pragma once

#include "ActionlessEffect.hpp"

#define EFFECT_NAME_WET "Wet"

class Wet : public ActionlessEffect {
public:
	Wet(int duration) : ActionlessEffect(EFFECT_NAME_WET, duration) { };

	virtual bool addTo(std::vector<Effect>& applied_effects) override;
};