#include "MovementFactory.h"

const factoryMap MovementFactory::m_factory {
	{BLEEDING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<BleedingAttack>(); }},
	{ORDINARY_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<OrdinaryAttack>(); }},
	{PIERCING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<PiercingAttack>(); }},
	{BOOST_MOVEMENT_NAME, []() { return std::make_unique<BoostMovement>(); }},
	{CURE_MOVEMENT_NAME, []() { return std::make_unique<Cure>(); }},
	{HEAL_MOVEMENT_NAME, []() { return std::make_unique<Heal>(); }},
	{REVIVE_MOVENT_NAME, []() { return std::make_unique<Revive>(); }},
	{SHIELD_MOVEMENT_NAME, []() { return std::make_unique<ShieldMovement>(); }},
	{FIRE_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<FireAttack>(); }},
	{ICE_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<IceAttack>(); }},
	{LIGHTNING_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<LightningAttack>(); }},
	{WATER_ATTACK_MOVEMENT_NAME, []() { return std::make_unique<WaterAttack>(); }}
};

std::unique_ptr<Movement> MovementFactory::create(std::string movementName)
{
	if (m_factory.contains(movementName)) {
		return m_factory.at(movementName)();
	}
	return nullptr;
}
