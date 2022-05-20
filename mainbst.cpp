#include "./include/BstAlgorithm.hpp"


int main(int argc, char const *argv[])
{
	ft::BstAlgorithm<int>  tree;
    std::string    buffer;
    int    value;


	tree.insert(10);
	tree.insert(20);
	tree.insert(13);
	tree.insert(5);
	tree.insert(7);
	tree.insert(8);
	tree.insert(14);
	tree.insert(12);
    while (1){
        std::cout << "> ";
        std::cin >> buffer;
        if (buffer == "add"){
            std::cout << "new node: ";
            std::cin >> value;
            tree.insert(value);
        }else if (buffer == "search"){
           ft::Node<int> *begin = tree.root;
            if (begin == NULL){
                std::cout << "is empty!" << std::endl;
                continue ;
            }
            while (true){
                std::cout << begin->value << std::endl;
                std::cout << "search: ";
                std::cin >> buffer;
                if (buffer == "exit")
                    break ;
                else if (buffer == "a" && begin->left)
                    begin = begin->left;
                else if (buffer == "d" && begin->right)
                    begin = begin->right;
                else if (buffer == "w" && begin->parent)
                    begin = begin->parent;
            }
        }else if (buffer == "del"){
            std::cout << "delete node: ";
            std::cin >> value;
            tree.remove(value);
        }
    }
	return 0;
}
