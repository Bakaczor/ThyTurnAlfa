#ifndef UTILS_HPP
#define UTILS_HPP

#include <exception>
#include <iostream>

namespace Utils {
	inline static float percent(const float& x) {
		return x / 100.0f;
	}

	inline static void printError(const std::exception& e) {
		std::cerr << "Error occurred in " << __func__ << ": " << std::endl << e.what() << std::endl;
	}
}

#endif