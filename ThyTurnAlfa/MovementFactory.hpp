#pragma once

#ifndef MOVEMENT_FACTORY_HPP
#define MOVEMENT_FACTORY_HPP

#include <functional>
#include <map>
#include <string>
#include <memory>

#include "Movement.hpp"

typedef std::map<std::string, std::function<std::shared_ptr<Movement>()>> factoryMap;

class MovementFactory
{
public:
	static std::shared_ptr<Movement> create(std::string movementName);
private:
	static const factoryMap m_factory;
};

#endif // MOVEMENT_FACTORY_H