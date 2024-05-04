#pragma once

#ifndef DMG_TABLE_H
#define DMG_TABLE_H

#include <array>
#include <map>
#include <memory>
#include <utility>

#include "Const.hpp"


class Character;
class Movement;
class Player;

typedef short unsigned int suint;

class DmgTable {
	public:
	DmgTable() = default;
	DmgTable(const Character& who, std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players);
	int getDmgEstimation(const suint& onWhom, const suint& what) const;
	void reset();

	private:
	std::map<std::pair<suint, suint>, int> m_table;
	int computeDmg(const Character& who, const suint& what, const Character& onWhom) const;
};

#endif