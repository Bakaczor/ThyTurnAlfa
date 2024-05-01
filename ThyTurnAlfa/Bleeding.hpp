#pragma once

#ifndef BLEEDING_HPP
#define BLEEDING_HPP

#include "TemporaryDamagePerRound.hpp"

class Character;

class Bleeding : public TemporaryDamagePerRound {
	public:
	Bleeding();

	virtual std::unique_ptr<Effect> clone() override;

	// nextRound methods is inherited from ActionlessEffect
	// cancelFrom methods is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !BLEEDING_HPP