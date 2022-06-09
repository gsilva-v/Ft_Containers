#include "./include/map.hpp"
#include <map>

int main() {
	ft::map<int, int> stdv;

	stdv[3] = 3;
	stdv[4] = 3;
	stdv[1] = 3;
	stdv[6] = 1;
	stdv[8] = 3;

	ft::map<int, int>::iterator it = stdv.begin();
	it = it + 1;

	std::cout << it->first<< std::endl;
	return 0;
}