#include "./tests/testConstructor.hpp"
#include "./tests/testElementAccess.hpp"
#include "./tests/testIterators.hpp"
#include "./tests/testCapacity.hpp"
#include "./tests/testModifiers.hpp"
#include "./tests/testLookup.hpp"
#include "./tests/testObserver.hpp"
#include <iostream>
#include <unistd.h>

int main()
{
	std::cout << "Testing Constructors" << std::endl;
	testConstructor::constructor1();
	sleep(1);
	testConstructor::constructor2();
	sleep(1);
	testConstructor::constructor3();
	sleep(1);
	testConstructor::constructor4();
	sleep(1);
	testConstructor::operator_equal();
	sleep(1);
	testConstructor::get_allocator();
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Element Access" << std::endl;
	testElementAccess::operator_keys(4);
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Iterators" << std::endl;
	testIterators::begin();
	sleep(1);
	testIterators::rbegin();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Capacity" << std::endl;
	testCapacity::empty();
	sleep(1);
	testCapacity::size();
	sleep(1);
	// testCapacity::max_size();
	// sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Modifiers" << std::endl;
	testModifiers::clear();
	sleep(1);
	testModifiers::erase1();
	sleep(1);
	testModifiers::erase2();
	sleep(1);
	testModifiers::erase3();
	sleep(1);
	testModifiers::erase4();
	sleep(1);
	testModifiers::swap();
	sleep(1);
	testModifiers::swap2();
	sleep(1);
	testModifiers::insert1();
	sleep(1);
	testModifiers::insert2();
	sleep(1);
	testModifiers::insert3();
	sleep(1);
	testModifiers::insert4();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Testing Lookup" << std::endl;
	testLookup::upper_bound();
	sleep(1);
	testLookup::lower_bound();
	sleep(1);
	testLookup::equal_range();
	sleep(1);
	std::cout << "------------------------------------" << std::endl;
	return 0;
}
// #include <ctime>
// #include <sys/time.h>
// #include <sstream>
	// {
	// 	struct timeval time_now;   
	// 	gettimeofday(&time_now, NULL);   
	// 	time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	// 	std::stringstream buf;

	// 	std::map<int, int> ftMap;

	// 	for (int i = 1; i < 10000000 ; i++){
	// 		ftMap[i] = i * 3; 
	// 	}
	// 	// ftMap[1] = 3;
	// 	// ftMap[2] = 3;
	// 	// ftMap[3] = 3;
	// 	// ftMap[4] = 3;
	// 	// ftMap[5] = 3;

	// 	// 	for (std::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
	// 	// 		if (std_itMap != ftMap.end())
	// 	// 			buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;
	// 	ftMap.clear();
	// 	gettimeofday(&time_now, NULL);   
	// 	time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

	// 	std::cout <<"std: "<<  finish - start << " ms" << std::endl;
	// }

	// {
	// 	struct timeval time_now;   
	// 	gettimeofday(&time_now, NULL);   
	// 	time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	// 	std::stringstream buf;

	// 	ft::map<int, int> ftMap;

	// 	for (int i = 1; i < 10000000 ; i++){
	// 		ftMap[i] = i * 3; 
	// 	}
	// 	// ftMap[1] = 3; 
	// 	// ftMap[2] = 3; 
	// 	// ftMap[3] = 3; 
	// 	// ftMap[4] = 3; 
	// 	// ftMap[5] = 3;

	// 	ftMap.clear();
	// 	// ft::map<int, int>::iterator std_itMap = ftMap.begin();

	// 	// std_itMap++;
	// 	// std_itMap++;
	// 	// std_itMap++;
	// 	// ftMap.erase(ftMap.begin(), std_itMap);
	// 	// ftMap.erase(2);
	// 	// ftMap.erase(3);
	// 	// ftMap.erase(4);
	// 	// ftMap.erase(5);
		
	// 	// for (ft::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
	// 	// 	if (std_itMap != ftMap.end())
	// 	// 		buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;

	// 	// ftMap.clear();
	// 	// std::cout << &(*ftMap.begin()) <<"\n";
	// 	// std::cout << &(*--ftMap.end()) <<"\n";
	// 	gettimeofday(&time_now, NULL);   
	// 	time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

	// 	std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
	// }