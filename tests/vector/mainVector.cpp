#include "./tests/testConstructor.hpp"
#include "./tests/testAssign.hpp"
#include "./tests/testElementAccess.hpp"
#include "./tests/testIterators.hpp"
#include "./tests/testCapacity.hpp"
#include "./tests/testModifiers.hpp"
#include "./tests/testBenchmark.hpp"
#include <unistd.h>

int main(void)
{
	std::cout << "Testing Constructors" << std::endl;
	testConstructor::constructor1();
	sleep(1);
	testConstructor::constructor2();
	sleep(1);
	testConstructor::constructor4();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Assign" << std::endl;
	testAssign::assign1();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Element Access" << std::endl;
	std::cout << "at()" << std::endl;
	testElementAcces::at(3);
	sleep(1);
	std::cout << "operator []" << std::endl;
	testElementAcces::operator_keys(4);
	sleep(1);
	std::cout << "front()" << std::endl;
	testElementAcces::front();
	sleep(1);
	std::cout << "back()" << std::endl;
	testElementAcces::back();
	sleep(1);
	std::cout << "data()" << std::endl;
	testElementAcces::data();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Iterators" << std::endl;
	std::cout << "begin()" << std::endl;
	testIterators::begin();
	sleep(1);
	std::cout << "end()" << std::endl;
	testIterators::end();
	sleep(1);
	std::cout << "rbegin()" << std::endl;
	testIterators::rbegin();
	sleep(1);
	std::cout << "rend()" << std::endl;
	testIterators::rend();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Capacity" << std::endl;
	std::cout << "empty()" << std::endl;
	testCapacity::empty();
	sleep(1);
	std::cout << "size()" << std::endl;
	testCapacity::size();
	sleep(1);
	std::cout << "max_size()" << std::endl;
	testCapacity::max_size();
	sleep(1);
	std::cout << "reserve()" << std::endl;
	testCapacity::reserve();
	sleep(1);
	std::cout << "capacity()" << std::endl;
	testCapacity::capacity();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Modifiers" << std::endl;
	std::cout << "clear()" << std::endl;
	testModifiers::clear();
	sleep(1);
	std::cout << "insert()" << std::endl;
	testModifiers::insert1();
	sleep(1);
	testModifiers::insert2();
	sleep(1);
	testModifiers::insert3();
	sleep(1);
	std::cout << "erase()" << std::endl;
	testModifiers::erase1();
	sleep(1);
	testModifiers::erase2();
	sleep(1);
	std::cout << "push_back()" << std::endl;
	testModifiers::push_back();
	sleep(1);
	std::cout << "pop_back()" << std::endl;
	testModifiers::pop_back();
	sleep(1);
	std::cout << "resize()" << std::endl;
	testModifiers::resize();
	sleep(1);
	std::cout << "swap()" << std::endl;
	testModifiers::swap();
	sleep(1);
	testModifiers::swap2();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Benchmark" << std::endl;
	testBenchmark::testTime();
	sleep(1);
	testBenchmark::testTime2();
	sleep(1);
	testBenchmark::testTime3();
	sleep(1);
	testBenchmark::testTime4();
	sleep(1);
	testBenchmark::testTime5();
	sleep(1);
	return 0;
}
