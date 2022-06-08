#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>

class testIterators
{
private:
	/* data */
public:
	testIterators();

	static void begin(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;
		ftm[4] = 2;
		ftm[5] = 2;
		ftm[1] = 2;
		ftm[3] = 2;
		ftm[44] = 2;
		ftm[2] = 2;
		stdm[4] = 2;
		stdm[5] = 2;
		stdm[1] = 2;
		stdm[3] = 2;
		stdm[44] = 2;
		stdm[2] = 2;


		std::cout << "Testing: \"iterator begin()\"\nresult: ";

		if (ftm.begin()->first != stdm.begin()->first)
			std::cout << "\033[1;31mInvalid value in begin\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in begin\033[0m" << std::endl;
		
		std::cout << "\n";
	};
	
	// static void end(){
	// 	ft::map<int, int> ftm;
	// 	std::map<int, int> stdm;
	// 	ftm[4] = 2;
	// 	ftm[5] = 2;
	// 	ftm[1] = 2;
	// 	ftm[3] = 2;
	// 	ftm[44] = 2;
	// 	ftm[2] = 2;
	// 	stdm[4] = 2;
	// 	stdm[5] = 2;
	// 	stdm[1] = 2;
	// 	stdm[3] = 2;
	// 	stdm[44] = 2;
	// 	stdm[2] = 2;
	// 	std::cout << "Testing: \"iterator end()\"\nresult: ";

	// 	std::cout << "\033[1;31mEND SHOULD BE NOT DEREFERENCED \033[0m"<< std::endl;
	// 	// if (ftm.end()->first != stdm.end()->first)
	// 	// 	std::cout << "\033[1;31mInvalid value in end\033[0m" << std::endl;
	// 	// else
	// 	// 	std::cout << "\033[1;32mCorrect value in end\033[0m" << std::endl;
		
	// 	std::cout << "\n";
	// };

	static void rbegin(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		ftm[4] = 2;
		ftm[5] = 2;
		ftm[1] = 2;
		ftm[3] = 2;
		ftm[44] = 2;
		ftm[2] = 2;
		stdm[4] = 2;
		stdm[5] = 2;
		stdm[1] = 2;
		stdm[3] = 2;
		stdm[44] = 2;
		stdm[2] = 2;
		std::cout << "Testing: \"reverse_iterator rbegin()\"\nresult: ";

		if (ftm.rbegin()->first != stdm.rbegin()->first)
			std::cout << "\033[1;31mInvalid value in rbegin\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in rbegin\033[0m" << std::endl;
		
		std::cout << "\n";
	};
	// static void rend(){
	// 	ft::map<int, int> ftm;
	// 	std::map<int, int> stdm;

	// 	ftm[4] = 2;
	// 	ftm[5] = 2;
	// 	ftm[1] = 2;
	// 	ftm[3] = 2;
	// 	ftm[44] = 2;
	// 	ftm[2] = 2;
	// 	stdm[4] = 2;
	// 	stdm[5] = 2;
	// 	stdm[1] = 2;
	// 	stdm[3] = 2;
	// 	stdm[44] = 2;
	// 	stdm[2] = 2;
	// 	std::cout << "Testing: \"reverse_iterator rend()\"\nresult: " << stdm.rend()->first;

	// 	if (ftm.rend()->first != stdm.rend()->first)
	// 		std::cout << "\033[1;31mInvalid value in rend\033[0m" << std::endl;
	// 	else
	// 		std::cout << "\033[1;32mCorrect value in rend\033[0m" << std::endl;
		
	// 	std::cout << "\n";
	// };



	~testIterators();
};
