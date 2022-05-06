#include "include/vector.hpp"
#include <vector>


int main(void)
{
	ft::vector<int> ft(4, 7);
	ft::vector<int> ft2(4, 9);
	std::vector<int> og(6, 1);
	std::vector<int> og1(10, 1);

	std::cout << "------------ Ft ---------" << std::endl ;
	for (ft::vector<int>::iterator it = ft.begin(); it != ft.end(); it++){
		std::cout << *it << std::endl ;
	}
	std::cout << "------------ Og ---------" << std::endl ;
	for (std::vector<int>::iterator it = og.begin(); it != og.end(); it++){
		std::cout << *it << std::endl ;
	}
	ft.push_back(8);

	og.push_back(8);


	std::cout << "------------ result ---------" << std::endl ;
	std::cout << "------------ Ft ---------" << std::endl ;
	
	for (ft::vector<int>::iterator it = ft.begin(); it != ft.end(); it++){
		std::cout << *it << std::endl ;
	}

	std::cout << "------------ Og ---------" << std::endl ;
	for (std::vector<int>::iterator it = og.begin(); it != og.end(); it++){
		std::cout << *it << std::endl ;
	}

	// std::swap(og, og1);

	return 0;
}
