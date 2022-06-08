#pragma once
#include "../../../include/map.hpp"
#include <map>
#include <iostream>
#include <sstream>

class testModifiers
{
private:
public:
	testModifiers();
	
	static void clear(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
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
		ftm.clear();
		stdm.clear();

		std::cout << "Testing: \"void clear()\"\nresult: ";

		if (ftm.size() != stdm.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::map<int, int>::iterator fti = ftm.begin(); fti != ftm.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdm.begin(); stdi != stdm.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " | \033[1;31mInvalid values inside map\033[0m\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m\n";
		std::cout << "\n";
	};

	static void erase1(){
		ft::map<int, int> ftv;
		std::map<int, int> stdv;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void erase(iterator pos)\"\nresult: ";

		ftv[1] = 2;
		ftv[2] = 2;
		ftv[3] = 2;
		ftv[44] = 2;
		ftv[5] = 2;
		stdv[1] = 2;
		stdv[2] = 2;
		stdv[3] = 2;
		stdv[44] = 2;
		stdv[5] = 2;
	

		ftv.erase(4);
		stdv.erase(4);

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside map\033[0m\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m\n";
		std::cout << "\n";
	};

	static void erase2(){
		ft::map<int, int> ftv;
		std::map<int, int> stdv;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void erase( iterator first, iterator last )\"\nresult: ";

		ftv[1] = 2;
		ftv[2] = 2;
		ftv[3] = 2;
		ftv[44] = 2;
		ftv[5] = 2;
		stdv[1] = 2;
		stdv[2] = 2;
		stdv[3] = 2;
		stdv[44] = 2;
		stdv[5] = 2;
		ft::map<int, int>::iterator ftit = ftv.begin();
		std::map<int, int>::iterator stdit = stdv.begin();
		ftit++;
		ftit++;
		ftit++;

		stdit++;
		stdit++;
		stdit++;

		ftv.erase(ftv.begin(), ftit);
		stdv.erase(stdv.begin(), stdit);

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside map\033[0m\n";
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m\n";
		std::cout << "\n";
	};

	static void erase3(){
		ft::map<int, int> ftv;
		std::map<int, int> stdv;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"size_type erase( const Key& key )\"\nresult: ";

		ftv[1] = 2;
		ftv[2] = 2;
		ftv[3] = 2;
		ftv[44] = 2;
		ftv[5] = 2;
		stdv[1] = 2;
		stdv[2] = 2;
		stdv[3] = 2;
		stdv[44] = 2;
		stdv[5] = 2;

		ftv.erase(ftv.begin()->first);
		stdv.erase(stdv.begin()->first);

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside map\033[0m\n" ;
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m\n" ;
		std::cout << "\n";
	};
	static void swap(){
		ft::map<int, int> ftv;
		ft::map<int, int> ftv2;
		std::map<int, int> stdv;
		std::map<int, int> stdv2;

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void swap( map& other )\"\nresult: ";

		ftv[1] = 2;
		ftv[2] = 2;
		ftv[3] = 2;
		ftv[44] = 2;
		ftv[5] = 2;
		stdv[1] = 2;
		stdv[2] = 2;
		stdv[3] = 2;
		stdv[44] = 2;
		stdv[5] = 2;

		ftv2.swap(ftv);
		stdv2.swap(stdv);

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << stdi->first;
		for(ft::map<int, int>::iterator fti = ftv2.begin(); fti != ftv2.end(); fti++)
			ftbuff << fti->first;
		for(std::map<int, int>::iterator stdi = stdv2.begin(); stdi != stdv2.end(); stdi++)
			stdbuff << stdi->first;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside map\033[0m\n" ;
		else
			std::cout << " | \033[1;32mCorrect values inside map\033[0m\n" ;
		std::cout << "\n";
	};

	// static void insert1(){
	// 	ft::map<int, int> ftv;
	// 	std::map<int, int> stdv;

	// 	std::stringstream ftbuff;
	// 	std::stringstream stdbuff;
	// 	std::cout << "Testing: \"ft::pair<iterator, bool> insert( const value_type& value)\"\nresult: ";

	// 	ftv[1] = 2;
	// 	ftv[2] = 2;
	// 	ftv[3] = 2;
	// 	ftv[44] = 2;
	// 	ftv[5] = 2;
	// 	stdv[1] = 2;
	// 	stdv[2] = 2;
	// 	stdv[3] = 2;
	// 	stdv[44] = 2;
	// 	stdv[5] = 2;

	// 	int key = 6;
	// 	int value = 6;
	// 	ftv.insert(ft::make_pair(key, value));
	// 	stdv.insert(std::make_pair(key, value));


	// 	if (ftv.size() != stdv.size())
	// 		std::cout << "\033[1;31mInvalid size\033[0m";
	// 	else
	// 		std::cout << "\033[1;32mCorrect size\033[0m";


	// 	for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
	// 		ftbuff << fti->first;
	// 	for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
	// 		stdbuff << stdi->first;

	// 	if (ftbuff.str() != stdbuff.str())
	// 		std::cout << " |\033[1;31mInvalid values inside map\033[0m\n" ;
	// 	else
	// 		std::cout << " | \033[1;32mCorrect values inside map\033[0m\n" ;
	// 	std::cout << "\n";
	// };

	// static void insert1(){
	// 	ft::map<int, int> ftv;
	// 	std::map<int, int> stdv;

	// 	std::stringstream ftbuff;
	// 	std::stringstream stdbuff;
	// 	std::cout << "Testing: \"iterator insert( iterator hint, const value_type& value )\"\nresult: ";

	// 	ftv[1] = 2;
	// 	ftv[2] = 2;
	// 	ftv[3] = 2;
	// 	ftv[44] = 2;
	// 	ftv[5] = 2;
	// 	stdv[1] = 2;
	// 	stdv[2] = 2;
	// 	stdv[3] = 2;
	// 	stdv[44] = 2;
	// 	stdv[5] = 2;

	// 	int key = 6;
	// 	int value = 6;
	// 	ft::map<int, int>::iterator ftit = ftv.begin();
	// 	std::map<int, int>::iterator stdit = stdv.begin();
	// 	ftit++;
	// 	ftit++;
	// 	ftit++;
	// 	stdit++;
	// 	stdit++;
	// 	stdit++;

	// 	ftv.insert(ftit, ft::make_pair(key, value));
	// 	stdv.insert(stdit, std::make_pair(key, value));


	// 	if (ftv.size() != stdv.size())
	// 		std::cout << "\033[1;31mInvalid size\033[0m";
	// 	else
	// 		std::cout << "\033[1;32mCorrect size\033[0m";


	// 	for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
	// 		ftbuff << fti->first;
	// 	for(std::map<int, int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
	// 		stdbuff << stdi->first;

	// 	if (ftbuff.str() != stdbuff.str())
	// 		std::cout << " |\033[1;31mInvalid values inside map\033[0m\n";
	// 	else
	// 		std::cout << " | \033[1;32mCorrect values inside map\033[0m\n";
	// 	std::cout << "\n";
	// };

	~testModifiers();
};

