#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>

class testAssign
{
private:
public:
	testAssign();
	static void assign1(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void assign( size_type count, const T& value )\"\nresult: ";
		ftv.assign(4, 3);
		stdv.assign(4, 3);


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftv.get_allocator() != stdv.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m" << "\n";
		std::cout << "\n";
	};
	// static void assign2(){
	// 	// ft::vector<int> ftv(5);
	// 	// std::vector<int> stdv(5);

	// 	// std::stringstream ftbuff;
	// 	// std::stringstream stdbuff;
	// 	// std::cout << "Testing: \"template <class InputIt> 
	// 	// void assign(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)\"\nresult: ";
	// 	// ftv.assign(4, 3);
	// 	// stdv.assign(4, 3);


	// 	// if (ftv.size() != stdv.size())
	// 	// 	std::cout << "\033[1;31mInvalid size\033[0m";
	// 	// else
	// 	// 	std::cout << "\033[1;32mCorrect size\033[0m";
	// 	// if (ftv.get_allocator() != stdv.get_allocator())
	// 	// 	std::cout << " | \033[1;31mInvalid allocator\033[0m";
	// 	// else
	// 	// 	std::cout << " | \033[1;32mCorrect allocator" ;

	// 	// for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
	// 	// 	ftbuff << *fti;
	// 	// for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
	// 	// 	stdbuff << *stdi;

	// 	// if (ftbuff.str() != stdbuff.str())
	// 	// 	std::cout << " | \033[1;31mInvalid values inside vector\033[0m" << "\n";
	// 	// else
	// 	// 	std::cout << " | \033[1;32mCorrect values inside vector\033[0m" << "\n";
	// 	// std::cout << "\n";
	// };
	~testAssign();
};

