#pragma once

#ifndef BOOST_HPP
#define BOOST_HPP

#include "TemporaryDamageModifier.hpp"

class Boost : public TemporaryDamageModifier {
	public:
	Boost();

	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected);
};

#endif // !BOOST_HPP


