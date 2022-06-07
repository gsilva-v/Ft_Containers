#include <map>
#include "../../include/map.hpp"
#include <ctime>
#include <sys/time.h>
#include <sstream>

int main(int argc, char const *argv[])
{
	{
		struct timeval time_now{};   
		gettimeofday(&time_now, nullptr);   
		time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
		std::stringstream buf;

		std::map<int, int> ftMap;

		std::srand(893360402);
		for (int i = 1; i < 10000000 ; i++){
			ftMap[i] = i * 3; 
		}
		// ftMap[1] = 3; 
		// ftMap[2] = 3; 
		// ftMap[3] = 3; 
		// ftMap[4] = 3; 
		// ftMap[5] = 3;

	// 	for (std::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
	// 		if (std_itMap != ftMap.end())
	// 			buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;
		ftMap.clear();
		gettimeofday(&time_now, nullptr);   
		time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

		std::cout <<"std: "<<  finish - start << " ms" << std::endl;
	}

	{
		struct timeval time_now{};   
		gettimeofday(&time_now, nullptr);   
		time_t start = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
		std::stringstream buf;

		ft::map<int, int> ftMap;

		std::srand(893360402);
		for (int i = 1; i < 10000000 ; i++){
			ftMap[i] = i * 3; 
		}
		// ftMap[1] = 3; 
		// ftMap[2] = 3; 
		// ftMap[3] = 3; 
		// ftMap[4] = 3; 
		// ftMap[5] = 3;

		ftMap.clear();
		// ft::map<int, int>::iterator std_itMap = ftMap.begin();

		// std_itMap++;
		// std_itMap++;
		// std_itMap++;
		// ftMap.erase(ftMap.begin(), std_itMap);
		// ftMap.erase(2);
		// ftMap.erase(3);
		// ftMap.erase(4);
		// ftMap.erase(5);
		
		// for (ft::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
		// 	if (std_itMap != ftMap.end())
		// 		buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;

		// ftMap.clear();
		// std::cout << &(*ftMap.begin()) <<"\n";
		// std::cout << &(*--ftMap.end()) <<"\n";
		gettimeofday(&time_now, nullptr);   
		time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

		std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
	}
	
	


	return 0;
}