#include "include/vector.hpp"



int main(int argc, char const *argv[])
{
	ft::vector<int> vec(4, 7);


	// for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
	// 	std::cout << *it << std::endl ;
	// }
	ft::vector<int>::iterator it = vec.end(); 
	it++;
	it++;

	vec.insert(it, 5);
	
	// std::cout << vec.capacity() << "\n";
	// std::cout << vec.size() << "\n";

	// vec.reserve(10); 
	// std::cout << vec.capacity() << "\n";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		std::cout << *it << std::endl ;
	}


	return 0;
}
