#pragma once

#ifndef MOVEMENT_FACTORY_H
#define MOVEMENT_FACTORY_H

#include <map>
#include <functional>
#include <string>
#include <memory>

#include "BleedingAttack.hpp"
#include "OrdinaryAttack.hpp"
#include "PiercingAttack.hpp"
#include "BoostMovement.hpp"
#include "Cure.hpp"
#include "Heal.hpp"
#include "Revive.hpp"
#include "ShieldMovement.hpp"
#include "FireAttack.hpp"
#include "IceAttack.hpp"
#include "LightningAttack.hpp"
#include "WaterAttack.hpp"

typedef std::map<std::string, std::function<std::unique_ptr<Movement>()>> factoryMap;

class MovementFactory
{
public:
	static std::unique_ptr<Movement> create(std::string movementName);
private:
	static const factoryMap m_factory;
};

#endif // MOVEMENT_FACTORY_H