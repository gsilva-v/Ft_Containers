#include "include/map.hpp"


int main(int argc, char const *argv[])
{
		ft::map<int, int> ftv;
		

		ftv[1] = 2;
		ftv[2] = 2;
		ftv[3] = 2;
		ftv[4] = 2;
		ftv[5] = 2;
		ftv[6] = 2;
		ftv[7] = 2;
		ftv.erase(2);


		std::cout << "---------------------"  << std::endl;
		for(ft::map<int, int>::iterator fti = ftv.begin(); fti != ftv.end(); fti++)
			std::cout << fti->first  << std::endl;


	return 0;
}
