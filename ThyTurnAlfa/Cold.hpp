#pragma once

#ifndef COLD_HPP
#define COLD_HPP

#include "ActionlessEffect.hpp"

class Character;

class Cold : public ActionlessEffect {
	public:
	Cold();
	Cold(const Cold& cold);

	virtual std::unique_ptr<Effect> clone() override;
	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !COLD_HPP