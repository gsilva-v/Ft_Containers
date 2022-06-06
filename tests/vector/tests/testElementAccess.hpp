#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>

class testElementAcces
{
private:
public:
	testElementAcces();
	static void at(ft::vector<int>::size_type pos){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"reference at( size_type pos )\"\nresult: ";

		ftbuff << ftv.at(pos);
		stdbuff << stdv.at(pos);

		if (ftbuff.str() != stdbuff.str())
			std::cout << " \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " \033[1;32mCorrect values inside vector\033[0m" << "\n";
		std::cout << "\n";
	};

	static void operator_keys(ft::vector<int>::size_type pos){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"reference operator[]( size_type pos )\"\nresult: ";

		ftbuff << ftv[pos];
		stdbuff << stdv[pos];

		if (ftbuff.str() != stdbuff.str())
			std::cout << " \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " \033[1;32mCorrect values inside vector\033[0m" << "\n";
		std::cout << "\n";
	};

	static void front(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"reference front()\"\nresult: ";

		ftbuff << ftv.front();
		stdbuff << stdv.front();

		if (ftbuff.str() != stdbuff.str())
			std::cout << " \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " \033[1;32mCorrect values inside vector\033[0m" << "\n";
		std::cout << "\n";
	};
	
	static void back(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"reference back()\"\nresult: ";

		ftbuff << ftv.back();
		stdbuff << stdv.back();

		if (ftbuff.str() != stdbuff.str())
			std::cout << " \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " \033[1;32mCorrect values inside vector\033[0m" << "\n";
		std::cout << "\n";
	};

	static void data(){
		ft::vector<int> ftv(5);

		std::cout << "Testing: \"T* data()\"\nresult: ";

		if (ftv.data() != (&(*ftv.begin())))
			std::cout << " \033[1;31mInvalid value of address\033[0m" << "\n";
		else
			std::cout << " \033[1;32mCorrect value of address\033[0m" << "\n";
		std::cout << "\n";
	};



	~testElementAcces();
};

