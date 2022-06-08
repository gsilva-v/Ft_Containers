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



	static void max_size(){
		ft::map<int, int> ftm;
		std::map<int, int> stdm;

		std::cout << "Testing: \"size_type max_size() const \"\nresult: " << ftm.max_size() << " "<< stdm.max_size();

		if (ftm.max_size() != stdm.max_size())
			std::cout << "\033[1;31mInvalid value of max_size\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value of max_size\033[0m" << std::endl;
		
		std::cout << "\n";
	};

	// static void reserve(){
	// 	ft::vector<int> ftv(5);
	// 	std::vector<int> stdv(5);
	// 	std::cout << "Testing: \"void reserve( size_type new_cap )\"\nresult: ";

	// 	{
	// 		std::cout << "\nTesting reverve grather than capacity." << std::endl;

	// 		std::cout << "Capacity before reserve: " << ftv.capacity() << std::endl;
	// 		std::cout << "reserving 10..." << std::endl;

	// 		ftv.reserve(10);
	// 		std::cout << "Capacity after reserve: " << ftv.capacity() << std::endl;
	// 	}
	// 	{
	// 		std::cout << "\nTesting reverve less than capacity." << std::endl;
	// 		std::cout << "Capacity before reserve: " << ftv.capacity() << std::endl;
	// 		std::cout << "reserving 3..." << std::endl;

	// 		ftv.reserve(3);
	// 		std::cout << "Capacity after reserve: " << ftv.capacity() << std::endl;
	// 	}


	// 	std::cout << "\n";
	// };

	// static void capacity(){
	// 	ft::vector<int> ftv(5);
	// 	std::vector<int> stdv(5);

	// 	std::cout << "Testing: \"size_type capacity() const \"\nresult: ";

	// 	if (ftv.capacity() != stdv.capacity())
	// 		std::cout << "\033[1;31mInvalid value of capacity\033[0m" << std::endl;
	// 	else
	// 		std::cout << "\033[1;32mCorrect value of capacity\033[0m" << std::endl;
		
	// 	std::cout << "\n";
	// };

	~testCapacity();
};
