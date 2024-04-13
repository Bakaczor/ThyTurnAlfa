#pragma once

#include "Character.hpp"


enum EffectId {
	boost,
	blleding,
	burning,
	wet
};

class Effect {
private:
	int m_elapsedRounds = 0;
	int m_duration = 0;
	Character* m_affected = nullptr;
public:
	const EffectId id;

	Effect(EffectId id, Character* affected) : id{ id }, m_affected { affected } { }
	
	virtual bool nextRound() = 0;
};


