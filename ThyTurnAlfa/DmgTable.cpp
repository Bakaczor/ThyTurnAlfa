#include "DmgTable.hpp"

#include "Attack.hpp"
#include "Utils.hpp"

DmgTable::DmgTable(const Character& who, std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players) {
    for (suint i = 0; i < who.movements.size(); i++) {
        for (const auto& player : players) {
            for (const auto& character : player->party) {
                if (who.id == character.id) { continue; }
                m_table.emplace(std::make_pair(character.id, i), computeDmg(who, i, character));
            }
        }
    }
}

void DmgTable::reset() {
    m_table.clear();
}

int DmgTable::getDmgEstimation(const suint& onWhom, const suint& what) const {
    const auto& pair = std::make_pair(onWhom, what);
    if (!m_table.contains(pair)) {
        return 0;
    }
    return m_table.at(pair);
}

int DmgTable::computeDmg(const Character& who, const suint& what, const Character& onWhom) const {
    auto& move = who.movements.at(what);
    Attack* attack = dynamic_cast<Attack*>(move.get());
    // not an attack or not invokable
    if (attack == nullptr || !move->isInvokable(who, onWhom)) { return 0; }
    // attack, but they are allies
    if (who.getPlayerId() == onWhom.getPlayerId()) { return 0; }

    float formula_prefix = attack->wMove * who.getAtk();
    float formula_suffix = 1.0f - (onWhom.getDef()  * (1.0f - attack->wPierce)) / Const::Algorithmic::NDEF;

    if (formula_suffix < 0 || formula_prefix < 0) { return 0; }
    return static_cast<int>(formula_prefix * formula_suffix);
}