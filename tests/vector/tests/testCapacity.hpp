#pragma once
#include "../../../include/vector.hpp"
#include <vector>
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
			ft::vector<int> ftv(5);

			std::cout << "For not empty vector: \nexpected: false.\nreturned: ";
			if (ftv.empty())
				std::cout << "\033[1;31mtrue\033[0m" << std::endl;
			else
				std::cout << "\033[1;32mfalse\033[0m" << std::endl;
			std::cout << "\n";
		}
		{
			ft::vector<int> ftv;

			std::cout << "For empty vector: \nexpected: true.\nreturned: ";
			if (ftv.empty())
				std::cout << "\033[1;32mtrue\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mfalse\033[0m" << std::endl;
			std::cout << "\n";
		}
	};


	static void size(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"size_type size() const \"\nresult: ";

		if (ftv.size() != stdv.size())
			std::cout << "\033[1;31mInvalid value of size\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value of size\033[0m" << std::endl;
		
		std::cout << "\n";
	};



	static void max_size(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"size_type max_size() const \"\nresult: ";

		if (ftv.max_size() != stdv.max_size())
			std::cout << "\033[1;31mInvalid value of max_size\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value of max_size\033[0m" << std::endl;
		
		std::cout << "\n";
	};

	static void reserve(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);
		std::cout << "Testing: \"void reserve( size_type new_cap )\"\nresult: ";

		{
			std::cout << "\nTesting reverve grather than capacity." << std::endl;

			std::cout << "Capacity before reserve: " << ftv.capacity() << std::endl;
			std::cout << "reserving 10..." << std::endl;

			ftv.reserve(10);
			std::cout << "Capacity after reserve: " << ftv.capacity() << std::endl;
		}
		{
			std::cout << "\nTesting reverve less than capacity." << std::endl;
			std::cout << "Capacity before reserve: " << ftv.capacity() << std::endl;
			std::cout << "reserving 3..." << std::endl;

			ftv.reserve(3);
			std::cout << "Capacity after reserve: " << ftv.capacity() << std::endl;
		}


		std::cout << "\n";
	};

	static void capacity(){
		ft::vector<int> ftv(5);
		std::vector<int> stdv(5);

		std::cout << "Testing: \"size_type capacity() const \"\nresult: ";

		if (ftv.capacity() != stdv.capacity())
			std::cout << "\033[1;31mInvalid value of capacity\033[0m" << std::endl;
		else
			std::cout << "\033[1;32mCorrect value of capacity\033[0m" << std::endl;
		
		std::cout << "\n";
	};

	~testCapacity();
};
