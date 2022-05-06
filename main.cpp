#include "include/vector.hpp"
#include <vector>


int main(void)
{
	ft::vector<int> ft(4, 7);
	ft::vector<int> ft2(4, 9);
	std::vector<int> og(14, 50);
	std::vector<int> og1(10, 1);

	std::cout << "------------ Ft ---------" << std::endl ;
	ft::vector<int>::reverse_iterator it = ft.rbegin();
		std::cout << *(it.base() - 1) << std::endl ;

	// std::cout << "------------ Og ---------" << std::endl ;
	// og.insert(og.begin() + 5, 7);
	// std::vector<int>::reverse_iterator it = og.rbegin();
	// // std::cout << "base: " << *(it.base()) << std::endl ;
	// for (int i = 0; it != og.rend();i++, it++){
	// 	std::cout << "index " << i << ": " << *(it.base()) << std::endl ;

	// }
	ft.push_back(8);

	og.push_back(8);



	return 0;
}
