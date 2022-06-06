#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>

class testConstructor
{
private:

public:
	testConstructor();
	static void constructor1(){
		ft::vector<int> ftv;
		std::vector<int> stdv;

		std::cout << "Testing: \"explicit vector(const Allocator& alloc = Allocator())\"\nresult: ";
		if (ftv.get_allocator() != stdv.get_allocator())
			std::cout << "\033[1;31mInvalid allocator\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect allocator\033[0m" << std::endl;
		std::cout << "\n";
	};

	static void constructor2(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())\"\nresult: ";
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

	static void constructor3(){
		// ft::vector<int> ftv(5);
		// std::vector<int> stdv(5);

		// std::cout << "Testing: \"template <class InputIt> vector(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator())\"\nresult: ";
		// if (ftv.size() != stdv.size())
		// 	std::cout << "\033[1;31mInvalid size\033[0m";
		// else
		// 	std::cout << "\033[1;32mCorrect size\033[0m";
		// if (ftv.get_allocator() != stdv.get_allocator())
		// 	std::cout << " | \033[1;31mInvalid allocator\033[0m";
		// else
		// 	std::cout << " | \033[1;32mCorrect allocator\033[0m";


		// std::cout << "\n";
	};

	static void constructor4(){
		
		ft::vector<int> ftv(5);
		ft::vector<int> ftv2(ftv);
		
		std::vector<int> stdv(5);
		std::vector<int> stdv2(stdv);

		std::stringstream ftbuff;
		std::stringstream stdbuff;

		std::cout << "Testing: \"vector(const vector& other)\"\nresult: ";
		if (ftv2.size() != stdv2.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftv2.get_allocator() != stdv2.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::vector<int>::iterator fti = ftv2.begin(); fti != ftv2.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv2.begin(); stdi != stdv2.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside vector\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m" << "\n";

		std::cout << "\n";
	};

	~testConstructor();
};

