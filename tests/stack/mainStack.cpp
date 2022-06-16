#include "../../include/stack.hpp"
#include <stack>
#include <vector>


int main()
{
	std::cout << "Testing Constructors" << std::endl;
	{
		std::cout << "Testing: \"explicit stack( const Container& cont = Container() )\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);
		// std::vector<int> stdv(5);
		// std::stack<int> stds(stdv);
		std::cout << "\033[1;32mOk\033[0m\n";
	}

	{
		std::cout << "\nTesting: \"stack( const stack& other )\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);
		ft::stack<int> fts2(fts);
		std::cout << "\033[1;32mOk\033[0m\n";
	}

	{
		std::cout << "\nTesting: \"stack& operator=( const stack& other )\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);
		ft::stack<int> fts2 = fts;
		if (fts2.top() == fts.top())
			std::cout << "\033[1;32mOk\033[0m\n";
		else
			std::cout << "\033[1;31mKO\033[0m\n";
	}

	{
		std::cout << "\nTesting: \"reference top()\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);
		ft::stack<int> fts2 = fts;
		if (fts2.top() == fts.top())
			std::cout << "\033[1;32mOk\033[0m\n";
		else
			std::cout << "\033[1;31mKO\033[0m\n";
	}

	{
		std::cout << "\nTesting: \"bool empty() const\"\nresult: ";
		{
			ft::vector<int> ftv;
			ft::stack<int> fts(ftv);

			std::cout << "For empty stack: ";

			if (fts.empty())
				std::cout << "\033[1;32mOk\033[0m\n";
			else
				std::cout << "\033[1;31mKO\033[0m\n";
		}
		{
			ft::vector<int> ftv(5);
			ft::stack<int> fts(ftv);

			std::cout << "For non empty stack: ";

			if (fts.empty())
				std::cout << "\033[1;31mKO\033[0m\n";
			else
				std::cout << "\033[1;32mOk\033[0m\n";
		}
	}

	{
		std::cout << "\nTesting: \"size_type size() const\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);
		std::cout << "expected: 5\nreturned: " << fts.size() << std::endl;
	}

	{
		std::cout << "\nTesting: \"void push( const value_type& value )\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);

		std::cout << "top() before push: " << fts.top() << std::endl;
		fts.push(7);
		std::cout << "top() after push: " << fts.top() << std::endl;
	}
	
	{
		std::cout << "\nTesting: \"void pop()\"\nresult: ";
		ft::vector<int> ftv(5);
		ft::stack<int> fts(ftv);

		std::cout << "top() before push: " << fts.top() << std::endl;
		fts.pop();
		std::cout << "top() after push: " << fts.top() << std::endl;
	}

	return 0;
}
