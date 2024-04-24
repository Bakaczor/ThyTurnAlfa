#pragma once

#ifndef BOOST_HPP
#define BOOST_HPP

#include "TemporaryDamageModifier.hpp"

#define BOOST_EFFECT_NAME "Boost"
#define BOOST_DEFAULT_ATK_BOOST 10
#define BOOST_DEFAULT_DEF_BOOST 10

class Boost : public TemporaryDamageModifier {
public:
	Boost(int duration, unsigned atk_boost = BOOST_DEFAULT_ATK_BOOST, unsigned def_boost = BOOST_DEFAULT_DEF_BOOST)
		: TemporaryDamageModifier(BOOST_EFFECT_NAME, duration, atk_boost, def_boost) { };

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
		unsigned atkBoost = BOOST_DEFAULT_ATK_BOOST, unsigned defBoost = BOOST_DEFAULT_DEF_BOOST);
};

#endif // !BOOST_HPP


