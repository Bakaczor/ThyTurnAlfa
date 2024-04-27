#include "MovementFactory.h"
#include "Const.hpp"

const factoryMap MovementFactory::m_factory {
	{Const::BleedingAttack::BLEEDING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<BleedingAttack>(); }},
	{Const::OrdinaryAttack::ORDINARY_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<OrdinaryAttack>(); }},
	{Const::PiercingAttack::PIERCING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<PiercingAttack>(); }},
	{Const::BoostMovement::BOOST_MOVEMENT_NAME, []() { return std::make_unique<BoostMovement>(); }},
	{Const::Cure::CURE_MOVEMENT_NAME, []() { return std::make_unique<Cure>(); }},
	{Const::Heal::HEAL_MOVEMENT_NAME, []() { return std::make_unique<Heal>(); }},
	{Const::Revive::REVIVE_MOVENT_NAME, []() { return std::make_unique<Revive>(); }},
	{Const::ShieldMovement::SHIELD_MOVEMENT_NAME, []() { return std::make_unique<ShieldMovement>(); }},
	{Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<FireAttack>(); }},
	{Const::IceAttack::ICE_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<IceAttack>(); }},
	{Const::LightningAttack::LIGHTNING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<LightningAttack>(); }},
	{Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<WaterAttack>(); }}
};

std::unique_ptr<Movement> MovementFactory::create(std::string movementName)
{
	if (m_factory.contains(movementName)) {
		return m_factory.at(movementName)();
	}
	return nullptr;
}
