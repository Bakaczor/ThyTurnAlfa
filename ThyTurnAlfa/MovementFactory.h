#pragma once

#ifndef MOVEMENT_FACTORY_H
#define MOVEMENT_FACTORY_H

#include <map>
#include <functional>
#include <string>
#include <memory>

#include "Movement.hpp"

typedef std::map<std::string, std::function<std::unique_ptr<Movement>()>> factoryMap;

class MovementFactory
{
public:
	static std::unique_ptr<Movement> create(std::string movementName);
private:
	static const factoryMap m_factory;
};

#endif // MOVEMENT_FACTORY_H