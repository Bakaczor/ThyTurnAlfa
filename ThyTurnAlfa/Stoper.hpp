#pragma once

#ifndef STOPER_H
#define STOPER_H

#include <chrono>
#include <vector>

#include "TimeType.hpp"

typedef std::chrono::high_resolution_clock ch_hrs;
typedef std::chrono::steady_clock ch_sc;

class Stoper {
	public:
	static long long elapsed(const ch_sc::time_point& start,
							 const ch_sc::time_point& end,
							 const TimeType& type = TimeType::μs);
	void start();
	void addPoint();
	void end();
	long long elapsed(const TimeType& type = TimeType::μs) const;
	double average(const TimeType& type = TimeType::μs) const;

	private:
	ch_sc::time_point m_start;
	ch_sc::time_point m_end;
	std::vector<ch_sc::time_point> m_points;
};

#endif
