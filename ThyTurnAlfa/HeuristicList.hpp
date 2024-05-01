#pragma once

#ifndef HEURISTIC_LIST_H
#define HEURISTIC_LIST_H

#include <utility>
#include <vector>

#include "Character.hpp"
#include "Const.hpp"

typedef short unsigned int suint;

class HeuristicList {
	public:
	std::vector <std::pair<suint, suint>> list;
	HeuristicList(const Character& who, std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER>& players);

	private:
	int killHeuristic(const Character& who, const suint& what, const Character& onWhom) const;
	int getWeight(const Character& who, const Movement* what, const Character& onWhom) const;
	int reviveHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int cureHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int healHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int wetHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int coldHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int burningHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int frozenHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
	int attackHeuristic(const Character& who, const Movement* what, const Character& onWhom) const;
};

#endif