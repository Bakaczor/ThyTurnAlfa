#pragma once

#ifndef WET_HPP
#define WET_HPP

#include "ActionlessEffect.hpp"

class Character;

class Wet : public ActionlessEffect {
	public:
	Wet();
	Wet(const Wet& wet);

	virtual std::unique_ptr<Effect> clone() override;
	// nextRound and remove methods are inherited from ActionlessEffect
	// cancelFrom method is inherited from Effect
	static bool addTo(Character& affected);
};

#endif // !WET_HPP