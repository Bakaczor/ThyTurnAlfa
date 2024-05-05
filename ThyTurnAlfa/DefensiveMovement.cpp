#include "DefensiveMovement.hpp"
#include "Character.hpp"

DefensiveMovement::DefensiveMovement(std::string&& name, int cost):
	Movement(std::move(name), TargetType::Ally), cost{ cost } {}

int DefensiveMovement::getCost() {
	return cost;
}

bool DefensiveMovement::isInvokable(const Character& who, const Character& on_whom) const {
	return Movement::isInvokable(who, on_whom) && who.currentMp >= cost;
}

bool DefensiveMovement::individualAction(Character& who, Character& on_whom)
{
	who.currentMp -= cost;
	return true;
}
