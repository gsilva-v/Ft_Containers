#pragma once
#include <Test.hpp>
#include "./include/vector.hpp"
#include <vector>
#include <sstream>

class VectorTest : doc::Test
{
private:
public:
	VectorTest(){
	}
	~VectorTest(){

	}

	void	test_size(){
		this->title("Size");
		{
			ft::vector<int> ft_list(5);
			this->name("Size must be 5 when list inicializes with 5 elements")->assertEqual(ft_list.size(), 5);
		}
		{
			ft::vector<int> ft_list(10);
			this->name("Size must be 10 when list inicializes with 10 elements")->assertEqual(ft_list.size(), 10);
		}
		{
			ft::vector<int> ft_list;
			this->name("Size must be 0 when list inicializes with 0 elements")->assertEqual(ft_list.size(), 0);
		}
	}

	void	test_assign(){
		this->title("Constructor/Assign Operators");

		{
			ft::vector<int>	ft_list;
			bool			res = (ft_list.capacity() == 0 && ft_list.size() == 0);
			this->name("Empty Constructor size and capacity must be 0")->assertEqual(res, true);
		}

		{
			ft::vector<int>	ft_list(5, 3);
			this->name("Constructor list(5, 3) the list must to have 5 elements with value 3")
				->assertEqual(this->getContent(ft_list), std::string("33333"));
		}

		{
			ft::vector<int>	other_list(3, 9);
			ft::vector<int>	ft_list(other_list.begin(), other_list.end());
			this->name("Constructor list = (other.begin(), other.end()) the list's content must be 999")
				->assertEqual(this->getContent(ft_list), std::string("999"));
		}

		{
			ft::vector<int>	other_list(2, 9);
			ft::vector<int>	ft_list(other_list);
			this->name("Constructor list(other(2,9)) list must contain 99")
				->assertEqual(this->getContent(ft_list), std::string("99"));
		}

		{
			ft::vector<int>	other_list(6, 2);
			ft::vector<int>	ft_list;
			
			ft_list = other_list;
			this->name("Constructor list = other_list(6,3) list must contain 222222")
				->assertEqual(this->getContent(ft_list), std::string("222222"));
		}
	}
	



	void	test_resize(){
		//considerações:
		//dobra a capacidade e ve se o novo numero de elementos cabe nela
		//caso o dobro da capacidade não for suficiente ele ira ter como capacidade o novo numero de elementos
		//todos novos elementos serão inicializados com val
		//caso o novo valor seja menor do que o tamanho atual, os elementos excedentes serão apagados mas a capacidade se mantem
		this->title("Resize");
		{
			ft::vector<int>	list;

			list.resize(5);
			this->name("Resizes 5 in a empty list new size has to be 5")->assertEqual(list.size(), 5);
		}
		{
			ft::vector<int>	list;

			list.resize(5);
			this->name("Resizes 5 in a empty list new capacity has to be 5")->assertEqual(list.capacity(), 5);
		}
		{
			ft::vector<int>	list(9, -1);

			list.resize(5);
			this->name("Resizes 5 in a list with 9 elements new size has to be 5")->assertEqual(list.size(), 5);
		}
		{
			ft::vector<int>	list(9, -1);

			list.resize(5);
			this->name("Resizes 5 in a list with 9 elements new capacity has to keep been 9")->assertEqual(list.capacity(), 9);
		}
		{
			std::stringstream	buffer;
			ft::vector<int>		list(9, 2);

			list.resize(5);
			for (ft::vector<int>::iterator i = list.begin(); i != list.end(); i++)
				buffer << *i;
			this->name("Resizes 5 in a list with 9 the the leftover elements has to keep the same")->assertEqual(std::string(buffer.str()), std::string("22222"));
		}
		{
			std::stringstream	buffer;
			ft::vector<int>		list(5, 2);

			list.resize(9, 1);
			for (ft::vector<int>::iterator i = list.begin(); i != list.end(); i++)
				buffer << *i;
			this->name("Resizes 9 in a list with 5 the the surplus elements has to be initialized as the value passed as second parameter")->assertEqual(std::string(buffer.str()), std::string("222221111"));
		}
	}

	void	test_capacity(){
		this->title("Capacity");
		{
			ft::vector<int> ft_list(60);
			this->name("Capaciy must return 60 when list iniciales with 60 elements")->assertEqual(ft_list.capacity(), 60);
		}
	}

	void test_reserve(){
		this->title("Reserve");
		{
			ft::vector<int> ft_list;
			ft_list.reserve(30);
			this->name("Empty list reserving 30 must have a capacity of 30")->assertEqual(ft_list.capacity(), 30);
		}
		{
			ft::vector<int> ft_list(20);
			ft_list.reserve(10);
			this->name("list with 20 slots reserving 10 must have a capacity of 20")->assertEqual(ft_list.capacity(), 20);
		}
	}

	void test_empty(){
		this->title("Empty");
		{
			ft::vector<int> ft_list;
			this->name("Empty List must return true")->assertEqual(ft_list.empty(), true);
		}
		{
			ft::vector<int> ft_list(1);
			this->name("List with elements must return false")->assertEqual(ft_list.empty(), false);
		}
	}

	void test_clear(){
		this->title("Clear");
		{
			ft::vector<int> ft_list(30, 2);
			ft_list.clear();
			this->name("List with elements after clear size must be 0")->assertEqual(ft_list.size(), 0);
		}
	}

	void test_reverse_iterator(){
		this->title("Reverse Iterator");
		{
			std::stringstream		std_buffer;
			std::stringstream		ft_buffer;
			ft::vector<int>			ft_list(5, 2);
			std::vector<int>		std_list(5, 2);


			int value = 0;
			for (std::vector<int>::iterator i = std_list.begin(); i != std_list.end(); i++, value++)
				*i = value;
			value = 0;
			for (ft::vector<int>::iterator i = ft_list.begin(); i != ft_list.end(); i++, value++)
				*i = value;

			for (std::vector<int>::reverse_iterator i = std_list.rbegin(); i != std_list.rend(); i++)
				std_buffer << *(i.base() - 1);
			for (ft::vector<int>::reverse_iterator i = ft_list.rbegin(); i != ft_list.rend(); i++)
				ft_buffer << *(i.base() - 1);
			this->name("Reverse iterator ft::vector output has to be equal std::vector output list 0 1 2 3 4")->assertEqual(std_buffer.str(), ft_buffer.str());
		}

		{
			std::stringstream		std_buffer;
			std::stringstream		ft_buffer;
			ft::vector<int>			ft_list(5, 2);
			std::vector<int>		std_list(5, 2);

			ft_list.insert(ft_list.begin() + 2, 1);
			std_list.insert(std_list.begin() + 2, 1);
			for (std::vector<int>::reverse_iterator i = std_list.rbegin(); i != std_list.rend(); i++){
				std_buffer << *(i.base() - 1);
			}
			for (ft::vector<int>::reverse_iterator i = ft_list.rbegin(); i != ft_list.rend(); i++)
				ft_buffer << *(i.base() - 1);
			
			this->name("Reverse iterator ft::vector output has to be equal std::vector output list 2 2 5 2 2 2")->assertEqual(std_buffer.str(), ft_buffer.str());
		}

		{
			std::stringstream		std_buffer;
			std::stringstream		ft_buffer;
			ft::vector<int>			ft_list(5, 2);
			std::vector<int>		std_list(5, 2);

			ft_list.insert(ft_list.begin() + 2, 1);
			std_list.insert(std_list.begin() + 2, 1);
			std::vector<int>::reverse_iterator std_i = std_list.rbegin();
			for (int index = 0; index < 5; index++){
				std_buffer << std_i[index];
			}
			ft::vector<int>::reverse_iterator ft_i = ft_list.rbegin();
			for (int index = 0; index < 5; index++){
				ft_buffer << ft_i[index];
			}
			
			this->name("Reverse iterator testing with index: ft_list[] == std_list[]")->assertEqual(std_buffer.str(), ft_buffer.str());
		}
	}

	std::string	getContent(ft::vector<int> list){
		std::stringstream	s;

		for (auto i : list)
			s << i;
		return (s.str());
	}


};
