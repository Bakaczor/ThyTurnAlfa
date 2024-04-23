#pragma once

#include "TemporaryDamageModifier.hpp"

#define EFFECT_NAME_BOOST "Boost"
#define BOOST_DEFAULT_ATK_BOOST 10
#define BOOST_DEFAULT_DEF_BOOST 10

class Boost : public TemporaryDamageModifier {
public:
	Boost(int duration, unsigned atk_boost = BOOST_DEFAULT_ATK_BOOST, unsigned def_boost = BOOST_DEFAULT_DEF_BOOST)
		: TemporaryDamageModifier(EFFECT_NAME_BOOST, duration, atk_boost, def_boost) { };
	
	static bool addTo(std::vector<std::unique_ptr<Effect>>& applied_effects, int duration, 
		unsigned atkBoost = BOOST_DEFAULT_ATK_BOOST, unsigned defBoost = BOOST_DEFAULT_DEF_BOOST);
};