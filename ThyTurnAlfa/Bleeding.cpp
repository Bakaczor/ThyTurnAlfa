#include "Bleeding.hpp"
#include "Character.hpp"
#include "Const.hpp"

Bleeding::Bleeding(): TemporaryDamagePerRound(Const::Bleeding::BLEEDING_EFFECT_NAME,
											  Const::Bleeding::BLEEDING_DEFAULT_DURATION,
											  Const::Bleeding::BLEEDING_DEFAULT_DAMAGE_PER_ROUND) {}

Bleeding::Bleeding(const Bleeding& bleeding)
	: TemporaryDamagePerRound(bleeding.name, bleeding.duration, bleeding.dmgPerRound)
{
	elapsedRounds = bleeding.elapsedRounds;
}

std::unique_ptr<Effect> Bleeding::clone()
{
	return std::make_unique<Bleeding>(*this);
}

bool Bleeding::addTo(Character& affected) {
	std::erase_if(affected.activeEffects, [&affected](std::unique_ptr<Effect>& e) {
		if (dynamic_cast<Bleeding*>(e.get())) {
			e->cancelFrom(affected);
			return true;
		}
		return false; 
		});

	affected.activeEffects.emplace_back(std::make_unique<Bleeding>());
	return true;
}
