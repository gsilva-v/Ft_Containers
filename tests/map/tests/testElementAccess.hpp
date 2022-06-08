#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>

class testElementAccess
{
private:
public:
	testElementAccess();
	
	static void operator_keys(ft::map<int, int>::size_type pos){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::cout << "Testing: \"T& operator[](const Key& key)\"\nresult: \n";
		std::stringstream ftbuff;
		std::stringstream stdbuff;
		{
			std::cout << "In empty map: ";

			ftbuff << ftm[pos];
			stdbuff << stdm[pos];

			if (ftbuff.str() != stdbuff.str())
				std::cout << " \033[1;31mKO\033[0m" << "\n";
			else
				std::cout << " \033[1;32mOK\033[0m" << "\n";
		}
		{
			std::cout << "In fill map: ";
			ftm[1] = 2;
			ftm[2] = 2;
			ftm[3] = 2;
			ftm[44] = 2;
			ftm[5] = 2;
			stdm[1] = 2;
			stdm[2] = 2;
			stdm[3] = 2;
			stdm[44] = 2;
			stdm[5] = 2;

			std::stringstream ftbuff;
			std::stringstream stdbuff;

			ftbuff << ftm[pos];
			stdbuff << stdm[pos];

			if (ftbuff.str() != stdbuff.str())
				std::cout << " \033[1;31mKO\033[0m" << "\n";
			else
				std::cout << " \033[1;32mOK\033[0m" << "\n";
		}
		{
			std::cout << "In invalid position: ";
			ftm[1] = 2;
			ftm[2] = 2;
			ftm[3] = 2;
			ftm[44] = 2;
			ftm[5] = 2;
			stdm[1] = 2;
			stdm[2] = 2;
			stdm[3] = 2;
			stdm[44] = 2;
			stdm[5] = 2;

			std::stringstream ftbuff;
			std::stringstream stdbuff;

			ftbuff << ftm[10];
			stdbuff << stdm[10];

			if (ftbuff.str() != stdbuff.str())
				std::cout << " \033[1;31mKO\033[0m" << "\n";
			else
				std::cout << " \033[1;32mOK\033[0m" << "\n";
		}
		std::cout << "\n";
	};

	~testElementAccess();
};

