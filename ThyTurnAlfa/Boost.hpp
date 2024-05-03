#pragma once

#ifndef BOOST_HPP
#define BOOST_HPP

#include "TemporaryDamageModifier.hpp"

class Character;

class Boost : public TemporaryDamageModifier {
	public:
	Boost();
	Boost(const Boost& boost);

	virtual std::unique_ptr<Effect> clone() override;
	// nextRound and cancelFrom methods are inherited from TemporaryDamageModifier
	static bool addTo(Character& affected);
};

#endif // !BOOST_HPP


