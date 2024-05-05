#pragma once

#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <iostream>

#define printError(exception) \
		std::cerr << "Error occurred in " << __func__ << ": " << \
		std::endl << exception.what() << std::endl

#endif // !ERROR_HPP
