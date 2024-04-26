#include "DefensiveMovement.hpp"

DefensiveMovement::DefensiveMovement(std::string&& name, int cost):
	Movement(std::move(name), TargetType::Ally), cost{ cost } {}

int DefensiveMovement::getCost() {
	return cost;
}

bool DefensiveMovement::isInvokable(Character& who, Character& on_whom) {
	return Movement::isInvokable(who, on_whom) && who.mp >= cost;
}