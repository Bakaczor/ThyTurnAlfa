#include "Const.hpp"
#include "MovementFactory.hpp"

const factoryMap MovementFactory::m_factory {
	{Const::BleedingAttack::BLEEDING_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<BleedingAttack>(); }},
	{Const::OrdinaryAttack::ORDINARY_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<OrdinaryAttack>(); }},
	{Const::PiercingAttack::PIERCING_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<PiercingAttack>(); }},
	{Const::BoostMovement::BOOST_MOVEMENT_NAME, []() { return std::make_shared<BoostMovement>(); }},
	{Const::Cure::CURE_MOVEMENT_NAME, []() { return std::make_shared<Cure>(); }},
	{Const::Heal::HEAL_MOVEMENT_NAME, []() { return std::make_shared<Heal>(); }},
	{Const::Revive::REVIVE_MOVENT_NAME, []() { return std::make_shared<Revive>(); }},
	{Const::ShieldMovement::SHIELD_MOVEMENT_NAME, []() { return std::make_shared<ShieldMovement>(); }},
	{Const::FireAttack::FIRE_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<FireAttack>(); }},
	{Const::IceAttack::ICE_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<IceAttack>(); }},
	{Const::LightningAttack::LIGHTNING_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<LightningAttack>(); }},
	{Const::WaterAttack::WATER_ATTACK_MOVEMENT_NAME, []() { return std::make_shared<WaterAttack>(); }}
};

std::shared_ptr<Movement> MovementFactory::create(std::string movementName) {
	if (m_factory.contains(movementName)) {
		return m_factory.at(movementName)();
	}
	return nullptr;
}
