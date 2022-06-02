#include "include/stack.hpp"
#include <stack>


int main()
{
	std::stack<int> stdStack;
	ft::stack<int> ftStack;	
	
	for (int i = 0; i < 10; i++)
		stdStack.push(i * 2);
	for (int i = 0; i < 10; i++)
		ftStack.push(i * 2);
	
	std::cout << "Std:" << std::endl;
	for (int i = 0; i < 10; i++){
		std::cout << stdStack.top() << std::endl;
		stdStack.pop();
	}

	std::cout << "Ft:" << std::endl;
	for (int i = 0; i < 10; i++){
		std::cout << ftStack.top() << std::endl;
		ftStack.pop();
	}
	return 0;
}
