#include <map>
#include "./include/map.hpp"


int main(int argc, char const *argv[])
{
	std::map<int, int> stdMap;

	stdMap[3] = 30;
	stdMap[1] = 10;
	stdMap[9] = 90;
	stdMap[7] = 70;
	stdMap[5] = 50;
	stdMap[8] = 80;
	stdMap[4] = 40;
	stdMap[6] = 60;
	stdMap[0] = 0;
	stdMap[2] = 20;

	std::cout << stdMap.max_size() << std::endl;

	// std::map<int, int>::iterator itStd = stdMap.end();
	// 	itStd--;
	// for(; itStd != stdMap.begin(); itStd--){
	// 	std::cout << itStd->first <<" "<< itStd->second << std::endl;
	// }		

	ft::map<int, int> ftMap;

	ftMap[3] = 30;
	ftMap[1] = 10;
	ftMap[9] = 90;
	ftMap[7] = 70;
	ftMap[5] = 50;
	ftMap[8] = 80;
	ftMap[4] = 40;
	ftMap[6] = 60;
	ftMap[0] = 0;
	ftMap[2] = 20;


	std::cout << ftMap.max_size() << std::endl;


	// ft::map<int, int>::iterator it = ftMap.begin();

	
	

	// for(; it != ftMap.begin(); it--){
	// }

	return 0;
}
