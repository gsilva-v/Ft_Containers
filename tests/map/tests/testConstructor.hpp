#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>

class testConstructor
{
private:

public:
	testConstructor();
	static void constructor1(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::cout << "Testing: \"map()\"\nresult: ";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << "\033[1;31mInvalid allocator\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect allocator\033[0m" << std::endl;
		std::cout << "\n";
	};

	static void constructor2(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"explicit map( const Compare& comp, const Allocator& alloc = Allocator() )\"\nresult: ";
		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::map<int, int>::iterator fti = ftm.begin(); fti != ftm.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdm.begin(); stdi != stdm.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside map\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m" << "\n";
		std::cout << "\n";
	};
	static void constructor3(){
		std::cout << "Testing: \"template< class InputIt >map ( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )\"\nresult: ";
		ft::map<int, int> ftm;
		std::map<int, int> stdm;
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

		ft::map<int, int> ftm2(ftm.begin(), ftm.end());
		std::map<int, int> stdm2(stdm.begin(), stdm.end());
		

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::map<int, int>::iterator fti = ftm2.begin(); fti != ftm2.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdm2.begin(); stdi != stdm2.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside map\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m" << "\n";
		std::cout << "\n";
	};
	static void constructor4(){
		std::cout << "Testing: \"map( const map& other )\"\nresult: ";
		ft::map<int, int> ftm;
		std::map<int, int> stdm;
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

		ft::map<int, int> ftm2(ftm);
		std::map<int, int> stdm2(stdm);
		

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::map<int, int>::iterator fti = ftm2.begin(); fti != ftm2.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdm2.begin(); stdi != stdm2.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside map\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m" << "\n";
		std::cout << "\n";
	};


	static void operator_equal(){
		ft::map<int, int> ftm;
		ft::map<int, int> ftm2;
		std::map<int, int> stdm;
		std::map<int, int> stdm2;

		ftm2[1] = 3;
		stdm2[1] = 3;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"map& operator=( const map& other )\"\nresult: ";
		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << " | \033[1;31mInvalid allocator\033[0m";
		else
			std::cout << " | \033[1;32mCorrect allocator\033[0m" ;

		for(ft::map<int, int>::iterator fti = ftm.begin(); fti != ftm.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdm.begin(); stdi != stdm.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside map\033[0m" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m" << "\n";
		std::cout << "\n";
	};


	static void get_allocator(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;


		std::cout << "Testing: \"allocator_type get_allocator() const\"\nresult: ";
		if (ftm.get_allocator() != stdm.get_allocator())
			std::cout << "\033[1;31mInvalid allocator\033[0m";
		else
			std::cout << "\033[1;32mCorrect allocator\033[0m" ;
		std::cout << "\n";
	}
	
	~testConstructor();
};

