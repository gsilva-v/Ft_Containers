#include "./tests/testConstructor.hpp"
#include "./tests/testElementAccess.hpp"
#include "./tests/testIterators.hpp"
#include "./tests/testCapacity.hpp"
#include "./tests/testModifiers.hpp"
#include "./tests/testLookup.hpp"
#include "./tests/testObserver.hpp"
#include "./tests/testBenchmark.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
	// std::cout << "Testing Constructors" << std::endl;
	// testConstructor::constructor1();
	// sleep(1);
	// testConstructor::constructor2();
	// sleep(1);
	// testConstructor::constructor3();
	// sleep(1);
	// testConstructor::constructor4();
	// sleep(1);
	// testConstructor::operator_equal();
	// sleep(1);
	// testConstructor::get_allocator();
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Testing Element Access" << std::endl;
	// testElementAccess::operator_keys(4);
	// sleep(1);
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Testing Iterators" << std::endl;
	// testIterators::begin();
	// sleep(1);
	// testIterators::rbegin();
	// sleep(1);
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Testing Capacity" << std::endl;
	// testCapacity::empty();
	// sleep(1);
	// testCapacity::size();
	// sleep(1);
	// // testCapacity::max_size();
	// // sleep(1);
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Testing Modifiers" << std::endl;
	// testModifiers::clear();
	// sleep(1);
	// testModifiers::erase1();
	// sleep(1);
	// testModifiers::erase2();
	// sleep(1);
	// testModifiers::erase3();
	// sleep(1);
	testModifiers::erase4();
	// sleep(1);
	// testModifiers::swap();
	// sleep(1);
	// testModifiers::swap2();
	// sleep(1);
	// testModifiers::insert1();
	// sleep(1);
	// testModifiers::insert2();
	// sleep(1);
	// testModifiers::insert3();
	// sleep(1);
	// testModifiers::insert4();
	// sleep(1);
	// std::cout << "------------------------------------" << std::endl;
	// std::cout << "Testing Lookup" << std::endl;
	// testLookup::upper_bound();
	// sleep(1);
	// testLookup::lower_bound();
	// sleep(1);
	// testLookup::equal_range();
	// sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Benchmark" << std::endl;
	testBenchmark::testTime();
	sleep(1);
	testBenchmark::testTime2();
	sleep(1);
	testBenchmark::testTime3();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	return 0;
}
