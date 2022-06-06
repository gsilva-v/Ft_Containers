#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>

class testIterators
{
private:
	/* data */
public:
	testIterators();

	static void begin(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"iterator begin()\"\nresult: ";

		if (*ftv.begin() != *stdv.begin())
			std::cout << "\033[1;31mInvalid value in begin\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in begin\033[0m" << std::endl;
		
		std::cout << "\n";
	};
	
	static void end(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"iterator end()\"\nresult: ";

		if (*ftv.end() != *stdv.end())
			std::cout << "\033[1;31mInvalid value in end\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in end\033[0m" << std::endl;
		
		std::cout << "\n";
	};

	static void rbegin(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"reverse_iterator rbegin()\"\nresult: ";

		if (*ftv.rbegin() != *stdv.rbegin())
			std::cout << "\033[1;31mInvalid value in rbegin\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in rbegin\033[0m" << std::endl;
		
		std::cout << "\n";
	};
	static void rend(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"reverse_iterator rend()\"\nresult: ";

		if (*ftv.rend() != *stdv.rend())
			std::cout << "\033[1;31mInvalid value in rend\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value in rend\033[0m" << std::endl;
		
		std::cout << "\n";
	};



	~testIterators();
};
