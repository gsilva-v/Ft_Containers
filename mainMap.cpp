#include <map>
#include "./include/map.hpp"
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
		for (int i = 1; i < 100000 ; i++){
			ftMap[i] = i * 3; 
		}

		for (ft::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
			if (std_itMap != ftMap.end())
				buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;
		// ftMap.clear();
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
		for (int i = 1; i < 100000 ; i++){
			ftMap[i] = i * 3; 
		}
		
		for (ft::map<int, int>::iterator std_itMap = ftMap.end(); std_itMap != ftMap.begin(); std_itMap--)
			if (std_itMap != ftMap.end())
				buf << "ft: " << std_itMap->first <<" "<< std_itMap->second << std::endl;

		// ftMap.clear();
		// std::cout << &(*ftMap.begin()) <<"\n";
		// std::cout << &(*--ftMap.end()) <<"\n";
		gettimeofday(&time_now, nullptr);   
		time_t finish = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

		std::cout <<"ft: "<<  finish - start << " ms" << std::endl;
	}
	
	
	// ft::map<int, int> ftMap;

    // ftMap[9] = 90;
  	// ftMap[8] = 80;
    // // ftMap[7] = 70;
    // // ftMap[5] = 20;
    // // ftMap[6] = 60;
    // // ftMap[1] = 10;
    // // ftMap[2] = 20;
    // // ftMap[3] = 30;
    // // ftMap[4] = 40;
    // // ftMap[0] = 0;


	// ft::map<int, int>::reverse_iterator ritMap = ftMap.rend();
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;
	// ritMap--;
	// std::cout << "ft: " << ritMap->first <<" "<< ritMap->second << std::endl;



	// ft::map<int, int>::iterator itft = ftMap.begin();
	// std::cout <<"----------------" << std::endl;
	// std::cout <<"  initial list" << std::endl;
	// std::cout <<"----------------" << std::endl;

	// for(; itft != ftMap.end(); itft++){
	// 	std::cout << itft->first << " "<< itft->second << std::endl;
	// }

	// std::cout <<"----------------" << std::endl;
	// std::cout <<" upper bound(5)" << std::endl;
	// std::cout <<"----------------" << std::endl;
	// std::cout << ftMap.upper_bound(5)->first << std::endl;

	// std::cout <<"----------------" << std::endl;
	// std::cout <<" lower bound(5)" << std::endl;
	// std::cout <<"----------------" << std::endl;
	// std::cout << ftMap.lower_bound(5)->first << std::endl;


	// std::cout <<"----------------" << std::endl;
	// std::cout <<"|  equal range |" << std::endl;
	// std::cout <<"----------------" << std::endl;
	// ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> pair = ftMap.equal_range(5);
	// ft::map<int, int>::iterator begPair = pair.first;
	// ft::map<int, int>::iterator endPair = pair.second;

	// for(; begPair != endPair; begPair++){
	// 	std::cout << begPair->first <<" "<< begPair->second << std::endl;
	// }		
	
	// // std::cout <<  << std::endl;
	

	// std::cout <<"----------------" << std::endl;
	// std::cout <<"     result" << std::endl;
	// std::cout <<"----------------" << std::endl;
	// ft::map<int, int>::reverse_iterator ritMap = ftMap.rbegin();
	// for(; ritMap != ftMap.rend(); ritMap--){
	// 	std::cout << ritMap->first <<" "<< ritMap->second << std::endl;
	// }		



	return 0;
}