#pragma once

#ifndef DMG_TABLE_H
#define DMG_TABLE_H

#include <array>
#include <map>
#include <memory>
#include <utility>

#include "Const.hpp"
#include "Movement.hpp"
#include "Player.hpp"

class DmgTable {
	public:
	DmgTable(std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players);

	private:
	std::map <std::pair<int, int>, int> m_table;
	int computeDmg(const Character& who, const int& what, const Character& onWhom) const;
};

#endif