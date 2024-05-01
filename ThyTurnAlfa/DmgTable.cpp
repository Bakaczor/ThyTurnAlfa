#include "DmgTable.hpp"

#include "Attack.hpp"
#include "Utils.hpp"

DmgTable::DmgTable(std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players) {

}

int DmgTable::computeDmg(const Character& who, const int& what, const Character& onWhom) const {
    auto& move = who.movements.at(what);
    Attack* attack = dynamic_cast<Attack*>(move.get());
    if (attack == nullptr) {
        return 0;
    }
    float formula_prefix = attack->wMove * who.getAtk();
    float formula_suffix = 1.0f - (onWhom.getDef()  * (1.0f - attack->wPierce)) / Const::Calculations::NDEF;

    if (formula_suffix < 0 || formula_prefix < 0) { return 0; }
    return formula_prefix * formula_suffix;
}