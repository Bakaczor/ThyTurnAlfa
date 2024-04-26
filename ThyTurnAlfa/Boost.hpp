#pragma once

#ifndef BOOST_HPP
#define BOOST_HPP

#include "TemporaryDamageModifier.hpp"

class Boost : public TemporaryDamageModifier {
	public:
	Boost(
		int duration, 
		unsigned atk_boost = Const::Boost::BOOST_DEFAULT_ATK_BOOST, 
		unsigned def_boost = Const::Boost::BOOST_DEFAULT_DEF_BOOST
	): TemporaryDamageModifier(Const::Boost::BOOST_EFFECT_NAME, duration, atk_boost, def_boost) { };

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
					  unsigned atkBoost = Const::Boost::BOOST_DEFAULT_ATK_BOOST, 
					  unsigned defBoost = Const::Boost::BOOST_DEFAULT_DEF_BOOST);
};

#endif // !BOOST_HPP


