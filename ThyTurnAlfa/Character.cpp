#pragma once
#include "Character.h"

void Character::Deserialize(Json::Value& root)
{
	m_name = root["name"].asString();
	m_SPD = root["SPD"].asInt();
}