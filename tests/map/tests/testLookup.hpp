#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>

class testLookup
{
private:
	
public:
	testLookup();
	static void count(){
		// ft::map<int, int> ftm;
		// std::map<int, int> stdm;

		// std::stringstream ftbuff;
		// std::stringstream stdbuff;
		// ftm[1] = 2;
		// ftm[2] = 2;
		// ftm[3] = 2;
		// ftm[44] = 2;
		// ftm[5] = 2;
		// stdm[1] = 2;
		// stdm[2] = 2;
		// stdm[3] = 2;
		// stdm[44] = 2;
		// stdm[5] = 2;

		// std::cout << "Testing: \"size_type count( const Key& key ) const\"\nresult: ";
		// std::cout << "\nIn valid key: ";
		
		// if (ftm.count(5) != stdm.count(5))
		// 	std::cout << "\033[1;31mKO\033[0m";
		// else
		// 	std::cout << "\033[1;32mOK\033[0m";
		// std::cout << "\nIn invalid key: ";

		// if (ftm.count(9) != stdm.count(9))
		// 	std::cout << "\033[1;31mKO\033[0m";
		// else
		// 	std::cout << "\033[1;32mOK\033[0m";


		// for(ft::map<int, int>::iterator fti = ftm.begin(); fti != ftm.end(); fti++)
		// 	ftbuff << fti->first;
		// for(std::map<int, int>::iterator stdi = stdm.begin(); stdi != stdm.end(); stdi++)
		// 	stdbuff << stdi->first;

		// if (ftbuff.str() != stdbuff.str())
		// 	std::cout << " | \033[1;31mInvalid values inside map\033[0m\n";
		// else
		// 	std::cout << " | \033[1;32mCorrect values inside map\033[0m\n";
		std::cout << "\n";
	};

	static void upper_bound(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		ftm[1] = 5;
		ftm[2] = 1;
		ftm[3] =92;
		ftm[44] = 2;
		ftm[5] = 3;
		stdm[1] = 5;
		stdm[2] = 1;
		stdm[3] =92;
		stdm[44] = 2;
		stdm[5] = 3;


		std::cout << "Testing: \"iterator upper_bound( const Key& key )\"\nresult: ";
		std::cout << "\nIn valid key: ";
		
		if (ftm.upper_bound(5)->first != stdm.upper_bound(5)->first)
			std::cout << "first: \033[1;31mKO\033[0m";
		else
			std::cout << "first: \033[1;32mOK\033[0m";
		if (ftm.upper_bound(5)->second != stdm.upper_bound(5)->second)
			std::cout << " second: \033[1;31mKO\033[0m";
		else
			std::cout << " second: \033[1;32mOK\033[0m";
		std::cout << "\nIn invalid key: ";
		if (ftm.upper_bound(9)->first != stdm.upper_bound(9)->first)
			std::cout << "first: \033[1;31mKO\033[0m";
		else
			std::cout << "first: \033[1;32mOK\033[0m";
		if (ftm.upper_bound(9)->second != stdm.upper_bound(9)->second)
			std::cout << " second: \033[1;31mKO\033[0m";
		else
			std::cout << " second: \033[1;32mOK\033[0m";
		std::cout << "\n\n";
	}
	
	static void lower_bound(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		ftm[1] = 5;
		ftm[2] = 1;
		ftm[3] =92;
		ftm[44] = 2;
		ftm[5] = 3;
		stdm[1] = 5;
		stdm[2] = 1;
		stdm[3] =92;
		stdm[44] = 2;
		stdm[5] = 3;
	

		std::cout << "Testing: \"iterator  lower_bound( const Key& key )\"\nresult: ";
		std::cout << "\nIn valid key: ";
		
	if (ftm.lower_bound(5)->first != stdm.lower_bound(5)->first)
			std::cout << "first: \033[1;31mKO\033[0m";
		else
			std::cout << "first: \033[1;32mOK\033[0m";
		if (ftm.lower_bound(5)->second != stdm.lower_bound(5)->second)
			std::cout << " second: \033[1;31mKO\033[0m";
		else
			std::cout << " second: \033[1;32mOK\033[0m";
		std::cout << "\nIn invalid key: ";
		if (ftm.lower_bound(9)->first != stdm.lower_bound(9)->first)
			std::cout << "first: \033[1;31mKO\033[0m";
		else
			std::cout << "first: \033[1;32mOK\033[0m";
		if (ftm.lower_bound(9)->second != stdm.lower_bound(9)->second)
			std::cout << " second: \033[1;31mKO\033[0m";
		else
			std::cout << " second: \033[1;32mOK\033[0m";
		std::cout << "\n\n";
	}
	static void equal_range(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		ftm[1] = 5;
		ftm[2] = 1;
		ftm[3] =92;
		ftm[44] = 2;
		ftm[5] = 3;
		stdm[1] = 5;
		stdm[2] = 1;
		stdm[3] =92;
		stdm[44] = 2;
		stdm[5] = 3;
	
		std::cout << "Testing: \"ft::pair<iterator,iterator> equal_range(const Key& key){\"\nresult: ";
	
		std::cout << "\nIn valid key: ";
		if ((ftm.equal_range(5).second)->first != (stdm.equal_range(5).second)->first)
			std::cout << " first->first: \033[1;31mKO\033[0m";
		else
			std::cout << " first->first: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(5).second)->second !=(stdm.equal_range(5).second)->second)
			std::cout << " first->second: \033[1;31mKO\033[0m";
		else
			std::cout << " first->second: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(5).second)->first != (stdm.equal_range(5).second)->first)
			std::cout << " second->first: \033[1;31mKO\033[0m";
		else
			std::cout << " second->first: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(5).second)->second !=(stdm.equal_range(5).second)->second)
			std::cout << " second->second: \033[1;31mKO\033[0m";
		else
			std::cout << " second->second: \033[1;32mOK\033[0m";
	
		std::cout << "\nIn invalid key: ";
		if ((ftm.equal_range(9).second)->first != (stdm.equal_range(9).second)->first)
			std::cout << " first->first: \033[1;31mKO\033[0m";
		else
			std::cout << " first->first: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(9).second)->second !=(stdm.equal_range(9).second)->second)
			std::cout << " first->second: \033[1;31mKO\033[0m";
		else
			std::cout << " first->second: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(9).second)->first != (stdm.equal_range(9).second)->first)
			std::cout << " second->first: \033[1;31mKO\033[0m";
		else
			std::cout << " second->first: \033[1;32mOK\033[0m";
		if ((ftm.equal_range(9).second)->second !=(stdm.equal_range(9).second)->second)
			std::cout << " second->second: \033[1;31mKO\033[0m";
		else
			std::cout << " second->second: \033[1;32mOK\033[0m";
		std::cout << "\n";
	}

	~testLookup();
};
 

 