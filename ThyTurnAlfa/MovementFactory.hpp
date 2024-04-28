#pragma once

#ifndef MOVEMENT_FACTORY_H
#define MOVEMENT_FACTORY_H

#include <functional>
#include <map>
#include <string>

#include "BleedingAttack.hpp"
#include "BoostMovement.hpp"
#include "Cure.hpp"
#include "FireAttack.hpp"
#include "Heal.hpp"
#include "IceAttack.hpp"
#include "LightningAttack.hpp"
#include "OrdinaryAttack.hpp"
#include "PiercingAttack.hpp"
#include "Revive.hpp"
#include "ShieldMovement.hpp"
#include "WaterAttack.hpp"

typedef std::map<std::string, std::function<std::shared_ptr<Movement>()>> factoryMap;

class MovementFactory
{
public:
	static std::shared_ptr<Movement> create(std::string movementName);
private:
	static const factoryMap m_factory;
};

#endif // MOVEMENT_FACTORY_H