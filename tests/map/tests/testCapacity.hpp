#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>


class testCapacity
{
private:
	/* data */
public:
	testCapacity(/* args */);

	static void empty(){
		std::cout << "Testing: \"bool empty() const\"\n\n";
		{
			ft::map<int, int> ftm;

			std::cout << "For empty map: \nexpected: true.\nreturned: ";
			if (ftm.empty())
				std::cout << "\033[1;32mtrue\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mfalse\033[0m" << std::endl;
			std::cout << "\n";
		}
		{
			ft::map<int,int> ftm;
			ftm[4] = 2;
			ftm[5] = 2;
			ftm[1] = 2;
			ftm[3] = 2;
			ftm[44] = 2;
			ftm[2] = 2;
			std::cout << "For non empty vector: \nexpected: false.\nreturned: ";
			if (ftm.empty())
				std::cout << "\033[1;31mtrue\033[0m" << std::endl;
			else
				std::cout << "\033[1;32mfalse\033[0m" << std::endl;
			std::cout << "\n";
		}
	};


	static void size(){
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
		std::cout << "Testing: \"size_type size() const \"\nresult: ";
		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid value of size\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value of size\033[0m" << std::endl;
		
		std::cout << "\n";
	};

	~testCapacity();
};
