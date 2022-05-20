#include <map>
#include "./include/map.hpp"


int main(int argc, char const *argv[])
{

	std::map<int, int> stdMap;
	ft::map<std::string, int> ftMap;
	
	ftMap["ola"] = 10;

	std::cout << ftMap["ola"] << std::endl;





	return 0;
}
