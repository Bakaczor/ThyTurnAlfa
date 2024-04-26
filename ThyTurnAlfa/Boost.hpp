#pragma once

#ifndef BOOST_HPP
#define BOOST_HPP

#include "TemporaryDamageModifier.hpp"

class Boost : public TemporaryDamageModifier {
	public:
	Boost();

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected, int duration,
					  int atkBoost = Const::Boost::BOOST_DEFAULT_ATK_BOOST, 
					  int defBoost = Const::Boost::BOOST_DEFAULT_DEF_BOOST);
};

#endif // !BOOST_HPP


