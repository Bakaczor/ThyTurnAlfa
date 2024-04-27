#pragma once

#ifndef BLEEDING_HPP
#define BLEEDING_HPP

#include "Character.hpp"
#include "TemporaryDamagePerRound.hpp"

class Bleeding : public TemporaryDamagePerRound {
	public:
	Bleeding();

	// nextRound methods is inherited from ActionlessEffect
	// cancelFrom methods is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !BLEEDING_HPP