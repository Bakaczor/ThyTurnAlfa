#pragma once

#include <iostream>
#include <cstdlib>

#include "Boost.hpp"
#include "Bleeding.hpp"
#include "Burning.hpp"
#include "Wet.hpp"
#include "Cold.hpp"
#include "Frozen.hpp"

#define test_failed(test_number) std::cout << "Test " << test_number++ << "failed in line " << __LINE__ << std::endl;
#define isTypeOf_test(type, instance) type::isTypeOf(instance)
#define isTypeOf_test_same(type, instance, test_number) if(!isTypeOf_test(type, instance)) test_failed(test_number)
#define isTypeOf_test_different(type, instance, test_number) if(isTypeOf_test(type, instance)) test_failed(test_number)

class EffectsTest {
private:
	bool Test1();
public:
	void Run();
};