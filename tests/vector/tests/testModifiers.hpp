#pragma once
#include "../../../include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>

class testModifiers
{
private:
public:
	testModifiers();
	
	static void clear(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void clear()\"\nresult: ";
		ftv.clear();
		stdv.clear();


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void insert1(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"iterator insert(iterator pos, const T& value)\"\nresult: ";
		ftv.insert(ftv.begin(), 1);
		stdv.insert(stdv.begin(), 1);

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void insert2(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void insert(iterator pos, size_type count, const T& value)\"\nresult: ";
		ftv.insert(ftv.begin(), 5, 1);
		stdv.insert(stdv.begin(), 5, 1);


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void erase1(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"iterator erase( iterator pos )\"\nresult: ";
		
		ftv.erase(++ftv.begin());
		stdv.erase(++stdv.begin());


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void erase2(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"iterator erase( iterator first, iterator last )\"\nresult: ";
		
		ftv.erase(++ftv.begin(), ++(++(ftv.begin())));
		stdv.erase(++stdv.begin(), ++(++(stdv.begin())));


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void push_back(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void push_back( const T& value )\"\nresult: ";
		
		ftv.push_back(10);
		stdv.push_back(10);


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void pop_back(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void pop_back()\"\nresult: ";
		
		ftv.pop_back();
		stdv.pop_back();


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void swap(){
		ft::vector<int> ftv(5);
		ft::vector<int> ftv2(8);
		std::vector<int> stdv(5);
		std::vector<int> stdv2(8);

		std::stringstream ftbuff;
		std::stringstream stdbuff;
		std::cout << "Testing: \"void swap( vector& other )\"\nresult: ";
		
		ftv.swap(ftv2);
		stdv.swap(stdv2);


		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid size\033[0m";
		else
			std::cout << "\033[1;32mCorrect size\033[0m";


		for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			ftbuff << *fti;
		for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
			stdbuff << *stdi;

		if (ftbuff.str() != stdbuff.str())
			std::cout << " |\033[1;31mInvalid values inside vector\033[0m\n" << "\n";
		else
			std::cout << " | \033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		std::cout << "\n";
	};

	static void resize(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);
		std::cout << "Testing: \"void resize(size_type count, T value = T())\"\nresult: ";

		{
			std::stringstream ftbuff;
			std::stringstream stdbuff;
			std::cout << "\nTesting resize grather than capacity." << std::endl;

			std::cout << "Capacity before reserve: ft: " << ftv.capacity() << " std: " << stdv.capacity() << std::endl;
			std::cout << "resizing to 10 with value == 8..." << std::endl;

			ftv.resize(10, 8);
			stdv.resize(10, 8);

			std::cout << "Capacity after reserve: ft: " << ftv.capacity() << " std: " << stdv.capacity() << std::endl ;
			
			for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
				ftbuff << *fti;
			for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
				stdbuff << *stdi;

			std::cout << "Values: " << std::endl;

			if (ftbuff.str() != stdbuff.str())
				std::cout << "Invalid values inside vector" << "\n";
			else
				std::cout << "\033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		}
		{
			std::stringstream ftbuff;
			std::stringstream stdbuff;
			std::cout << "\nTesting resize less than capacity." << std::endl;

			std::cout << "Capacity before reserve: ft: " << ftv.capacity() << " std: " << stdv.capacity() << std::endl;
			std::cout << "resizing to 3 with value == 8..." << std::endl;

			ftv.resize(3, 8);
			stdv.resize(3, 8);

			std::cout << "Capacity after reserve: ft: " << ftv.capacity() << " std: " << stdv.capacity() << std::endl ;
			
			for(ft::vector<int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
				ftbuff << *fti;
			for(std::vector<int>::iterator stdi = stdv.begin(); stdi != stdv.end(); stdi++)
				stdbuff << *stdi;

			std::cout << "\nValues: " << std::endl;

			if (ftbuff.str() != stdbuff.str())
				std::cout << "Invalid values inside vector" << "\n";
			else
				std::cout << "\033[1;32mCorrect values inside vector\033[0m\n" << "\n";
		}


		std::cout << "\n";
	};

	~testModifiers();
};

