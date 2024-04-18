#pragma once

#include "ActionlessEffect.hpp"

#define EFFECT_NAME_COLD "Cold"

class Cold : public ActionlessEffect {
public:
	Cold(int duration) : ActionlessEffect(EFFECT_NAME_COLD, duration) { };

	virtual bool addTo(std::vector<Effect>& applied_effects) override;
	static bool isTypeOf(Effect& e);
};