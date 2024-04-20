#pragma once

#include "MagicAttack.hpp"

#define LIGHTNING_ATTACK_DEFAULT_WEIGHT 100
#define LIGHTNING_ATTACK_DEFAULT_COST 0
#define LIGHTNING_ATTACK_DEFAULT 

class LightningAttack : public MagicAttack {
public:
	LightningAttack()
		: MagicAttack(LIGHTNING_ATTACK_DEFAULT_COST, LIGHTNING_ATTACK_DEFAULT_WEIGHT) { }

	virtual bool invoke(Character& who, Character& on_whom) override;
	virtual std::string getCost() override;
private:
	virtual void applyDamage(Character& who, Character& on_whom) override;
};