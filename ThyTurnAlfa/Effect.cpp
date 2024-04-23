#include "Character.hpp"
#include "Effect.hpp"

//bool Effect::isTypeOf(Effect& e)
//{
//    return this->name.compare(e.name) == 0;
//}
//
//bool Effect::addTo(std::vector<std::unique_ptr<Effect>>& applied_effects)
//{
//	for (auto it = applied_effects.begin(); it != applied_effects.end(); it++)
//	{
//		if ((*it)->isTypeOf(*this))
//		{
//			applied_effects.erase(it);
//		}
//	}
//	applied_effects.emplace_back(this);
//	return true;
//}
