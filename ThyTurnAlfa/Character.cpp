#include "Character.hpp"
#include "Effect.hpp"
#include "Movement.hpp"

bool Character::addEffect(Effect& c) {
	return false;
}

bool Character::applyEffects() {
	for (auto it = activeEffects.begin(); it != activeEffects.end(); it++)
	{
		if (!(*it)->nextRound(*this))
			activeEffects.erase(it);
	}
	return true;
}

//void Character::Deserialize(Json::Value& root)
//{
//	m_name = root["name"].asString();
//	m_SPD = root["SPD"].asInt();
//}