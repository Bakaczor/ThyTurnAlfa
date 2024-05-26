#include "Stoper.hpp"

long long Stoper::elapsed(const ch_sc::time_point& start, const ch_sc::time_point& end, const TimeType& type) {
	switch (type) {
		case TimeType::ns:
			return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		case TimeType::μs:
			return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		case TimeType::ms:
			return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		case TimeType::s:
			return std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
		default:
			return -1;
	}
}

void Stoper::start() {
	m_start = ch_hrs::now();
}

void Stoper::addPoint() {
	m_points.push_back(ch_hrs::now());
}

void Stoper::end() {
	m_end = ch_hrs::now();
}

long long Stoper::elapsed(const TimeType& type) const {
	switch (type) {
		case TimeType::ns:
			return std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start).count();
		case TimeType::μs:
			return std::chrono::duration_cast<std::chrono::microseconds>(m_end - m_start).count();
		case TimeType::ms:
			return std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
		case TimeType::s:
			return std::chrono::duration_cast<std::chrono::seconds>(m_end - m_start).count();
		default:
			return -1;
	}
}

double Stoper::average(const TimeType& type) const {
	long long sum = Stoper::elapsed(m_start, m_points.at(0), type);
	for (unsigned int i = 0; i < m_points.size() - 1; i++) {
		sum += Stoper::elapsed(m_points.at(i), m_points.at(i + 1), type);
	}
	return static_cast<double>(sum) / m_points.size();
}
