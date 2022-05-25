#include <map>
#include "./include/map.hpp"


int main(int argc, char const *argv[])
{
		

	ft::map<int, int> ftMap;

	ftMap[1] = 10;
	ftMap[2] = 20;
	ftMap[3] = 30;
	ftMap[8] = 80;
	ftMap[9] = 90;
	ftMap[7] = 70;
	ftMap[4] = 40;
	ftMap[6] = 60;
	ftMap[0] = 0;
	ftMap[2] = 20;

	ft::map<int, int>::iterator itft = ftMap.begin();
	std::cout <<"----------------" << std::endl;
	std::cout <<"  initial list" << std::endl;
	std::cout <<"----------------" << std::endl;

	for(; itft != ftMap.end(); itft++){
		std::cout << itft->first << " "<< itft->second << std::endl;
	}

	std::cout <<"----------------" << std::endl;
	std::cout <<"   erase (key)" << std::endl;
	std::cout <<"----------------" << std::endl;

	ftMap.erase(7);
	std::cout <<"|   erase (7)  |" << std::endl;

	std::cout <<"----------------" << std::endl;
	std::cout <<"     result" << std::endl;
	std::cout <<"----------------" << std::endl;
	itft = ftMap.begin();
	for(; itft != ftMap.end(); itft++){
		std::cout << itft->first <<" "<< itft->second << std::endl;
	}		



	return 0;
}