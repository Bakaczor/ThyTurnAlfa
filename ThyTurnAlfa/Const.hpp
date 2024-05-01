#pragma once

#ifndef CONST_HPP
#define CONST_HPP

namespace Const {
	// ===== COMMON =====
	namespace Sizes {
		constexpr unsigned int MAX_PARTY_SIZE = 4;
		constexpr unsigned int PLAYER_NUMBER = 2;
		constexpr unsigned int MAX_NUM_OF_TRIES = 10;
	}

	namespace Calculations {
		constexpr float NDEF = 200.0f;
	}

	// ===== EFFECTS =====

	namespace Bleeding {
		constexpr const char* BLEEDING_EFFECT_NAME = "Bleeding";
		constexpr int BLEEDING_DEFAULT_DAMAGE_PER_ROUND = 5;
		constexpr int BLEEDING_DEFAULT_DURATION = 3;
	}

	namespace Boost {
		constexpr const char* BOOST_EFFECT_NAME = "Boost";
		constexpr int BOOST_DEFAULT_ATK_BOOST = 10;
		constexpr int BOOST_DEFAULT_DEF_BOOST = 10;
		constexpr int BOOST_DEFAULT_DURATION = 5;
	}

	namespace Burning {
		constexpr const char* BURNING_EFFECT_NAME = "Burning";
		constexpr int BURNING_DEFAULT_DAMAGE_PER_ROUND = 10;
		constexpr int BURNING_DEFAULT_DURATION = 3;
	}

	namespace Cold {
		constexpr const char* COLD_EFFECT_NAME = "Cold";
		constexpr int COLD_DEFAULT_DURATION = 4;
	}

	namespace Frozen {
		constexpr const char* FROZEN_EFFECT_NAME = "Frozen";
		constexpr int FROZEN_DEFAULT_ATK_DROP = -10;
		constexpr int FROZEN_DEFAULT_DEF_DROP = -10;
		constexpr int FROZEN_DEFAULT_DURATION = 5;
	}

	namespace Shield {
		constexpr const char* SHIELD_EFFECT_NAME = "Shield";
		constexpr int SHIELD_DEFAULT_DURATION = -1;
		constexpr int SHIELD_DEFAULT_HP = 50;
	}

	namespace Wet {
		constexpr const char* WET_EFFECT_NAME = "Wet";
		constexpr int WET_DEFAULT_DURATION = 4;
	}

	// ===== MOVEMENTS =====

	namespace BleedingAttack {
		constexpr const char* BLEEDING_ATTACK_MOVEMENT_NAME = "BleedingAttack";
		constexpr int BLEEDING_ATTACK_DEFAULT_WEIGHT = 60;
	}

	namespace OrdinaryAttack {
		constexpr const char* ORDINARY_ATTACK_MOVEMENT_NAME = "OrdinaryAttack";
		constexpr int ORDINARY_ATTACK_DEFAULT_WEIGHT = 100;
	}

	namespace PiercingAttack {
		constexpr const char* PIERCING_ATTACK_MOVEMENT_NAME = "PiercingAttack";
		constexpr int PIERCING_ATTACK_DEFAULT_WEIGHT = 50;
		constexpr int PIERCING_ATTACK_DEFAULT_PIERCING_WEIGHT = 50;
	}

	namespace BoostMovement {
		constexpr const char* BOOST_MOVEMENT_NAME = "BoostMovement";
		constexpr int BOOST_MOVEMENT_DEFAULT_COST = 20;
	}

	namespace Cure {
		constexpr const char* CURE_MOVEMENT_NAME = "Cure";
		constexpr int CURE_DEFAULT_COST = 10;
	}

	namespace Heal {
		constexpr const char* HEAL_MOVEMENT_NAME = "Heal";
		constexpr int HEAL_DEFAULT_HP_BOOST = 50;
		constexpr int HEAL_DEFAULT_COST = 20;
	}

	namespace Revive {
		constexpr const char* REVIVE_MOVENT_NAME = "Revive";
		constexpr int REVIVE_DEFAULT_COST = 70;
	}

	namespace ShieldMovement {
		constexpr const char* SHIELD_MOVEMENT_NAME = "ShieldMovement";
		constexpr int SHIELD_MOVEMENT_DEFAULT_HP = 40;
		constexpr int SHIELD_MOVEMENT_DEFAULT_COST = 50;
	}

	namespace FireAttack {
		constexpr const char* FIRE_ATTACK_MOVEMENT_NAME = "FireAttack";
		constexpr int FIRE_ATTACK_DEFAULT_WEIGHT = 60;
		constexpr int FIRE_ATTACK_DEFAULT_COST = 40;
	}

	namespace IceAttack {
		constexpr const char* ICE_ATTACK_MOVEMENT_NAME = "IceAttack";
		constexpr int ICE_ATTACK_DEFAULT_WEIGHT = 85;
		constexpr int ICE_ATTACK_DEFAULT_PIERCING_WEIGHT = 30;
		constexpr int ICE_ATTACK_DEFAULT_COST = 30;
	}

	namespace LightningAttack {
		constexpr const char* LIGHTNING_ATTACK_MOVEMENT_NAME = "LightningAttack";
		constexpr int LIGHTNING_ATTACK_DEFAULT_WEIGHT = 100;
		constexpr int LIGHTNING_ATTACK_DEFAULT_COST = static_cast<int>(0.5f * LIGHTNING_ATTACK_DEFAULT_WEIGHT);
	}

	namespace WaterAttack{
		constexpr const char* WATER_ATTACK_MOVEMENT_NAME = "WaterAttack";
		constexpr int WATER_ATTACK_DEFAULT_WEIGHT = 80;
		constexpr int WATER_ATTACK_DEFAULT_COST = 20;
	}
}

#endif // CONST_HPP