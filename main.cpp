#include "include/vector.hpp"
#include <vector>


int main(void)
{
	ft::vector<int> ft(14, 50);
	std::vector<int> og(14, 50);
	ft::vector<int> ft2(10, 1);
	std::vector<int> og2(10, 1);

// ambiente ft
	{		
	
		std::cout << "------------ Ft ---------" << std::endl ;
		ft.insert(ft.begin() + 5, 7);
		ft::vector<int>::reverse_iterator it = ft.rbegin();

		// it += 5;		

		for (int i = 0; it != ft.rend();i++, it++){
			std::cout << "index " << i << ": " << *(it.base()) << std::endl ;
		}
	}




// ambiente original
	{
		std::cout << "------------ Og ---------" << std::endl ;
		og.insert(og.begin() + 5, 7);
		std::vector<int>::reverse_iterator it = og.rbegin();
		// it += 5;
		
		for (int i = 0; it != og.rend();i++, it++){
			std::cout << "index " << i << ": " << *(it.base()) << std::endl ;
		}
	}



	return 0;
}
