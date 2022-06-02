#if !defined(BST_ALGORTHM_HPP)
#define BST_ALGORTHM_HPP

#include <iostream>
#include "utility.hpp"

namespace ft
{
	enum Direction{
		Left,
		Right,
		Parent
	};

	enum Color{
		Black,
		Red
	};

	template <typename Key, typename T> 
	struct Node
	{
		Node<Key, T>	*parent;
		ft::pair<const Key, T>	*value;
		Node<Key, T>	*left;
		Node<Key, T>	*right;
		Color 	color;
	};

  	template<class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class BstAlgorithm
	{	
	protected:
		std::allocator<ft::pair<const Key, T> > *_alloc;

	public:
		typedef Key key_type;
		typedef T mapped_type;			
		typedef ft::pair<const Key, T> value_type;
		Node<Key, T> *root;

	public:
		BstAlgorithm(Allocator *alloc): root(NULL), _alloc(alloc){};
		~BstAlgorithm(){};

		Node<Key, T> *newNode(Key key){
			Node<Key, T> *new_node = new Node<Key, T>;

			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->color = ft::Color::Black;
			new_node->value = this->_alloc->allocate(1);
			this->_alloc->construct(new_node->value, value_type(key, T()));
			return new_node;
		}

		Node<Key, T>	*findSlot(Node<Key, T> *node, Node<Key, T> **root = NULL){	
			Node<Key, T> *init;

			if (root == NULL)
				root = &this->root;
			if (*root == NULL){
				*root = node;
				return node;
			} else
				init = *root;
			while (init)
			{
				if (node->value->first < init->value->first){
					if (!init->left){
						node->parent = init;
						init->left = node;
					}
					init = init->left;
				}
				else if (node->value->first > init->value->first){
					if (!init->right){
						node->parent = init;
						init->right = node;
					}
					init = init->right;
				}
				else
					return init;
			}
			return node;
		};

		virtual T& insert(Key key){

			Node<Key, T> *new_node = newNode(key);
			Node<Key, T> *found;
			found = findSlot(new_node);
			if (!new_node->parent && new_node != this->root)
				delete new_node;	
			return found->value->second;
		};

		static Direction getDirection(Node<Key, T> *node){
			if (node->parent->right == node)
				return Direction::Right;
			return Direction::Left;
		};

		static Node<Key, T> *getHigherNode(Node<Key, T> *node){
			while (node && node->right)
				node = node->right;
			return node;
		}

		static Node<Key, T> *getLowerNode(Node<Key, T> *node){
			while (node && node->left)
				node = node->left;
			return node;
		}

		virtual void deleteNode(Node<Key, T> *node){
			if (!node->left && !node->right){//se nao houver nenhum filho
				this->swapNode(node, NULL);
			} else if (node->left && node->right){ //caso tenham 2 filhos
				Node<Key, T> *higher = this->getHigherNode(node->left);
				this->swapNode(higher, higher->left);
				this->swapNode(node, higher);
			} else if (node->left || node->right){ //caso tenha 1 filho
				if (node->left){
					this->swapNode(node, node->left);
				} else {
					this->swapNode(node, node->right);
				}
			}
			delete node;
		};

		void	swapNode(Node<Key, T> *node, Node<Key, T> *sub){
			
			if (!node)
					return;

			if (sub){
				sub->parent = node->parent;
				if (node->left != sub && node->left){
					sub->left = node->left;
					node->left->parent = sub;
				}
				if (node->right != sub && node->right){
					sub->right = node->right;
					node->right->parent = sub;
				}
			}
		
			if (node && node->parent){
				if (node->parent->left == node)
					node->parent->left = sub;
				else
					node->parent->right = sub;
			}		
			else
				this->root = sub;
		}

		Node<Key, T> *find(Key key, Node<Key, T> *root = NULL){
			if (!root)
				root = this->root;			
			Node<Key, T> *init = root;

			while (init)
			{
				if (key == init->value->first){
					return init;
				} else if (key < init->value->first)
					init = init->left;
				else if (key > init->value->first)
					init = init->right;
			}
			return NULL;
		};

		void remove(Key key){
			Node<Key, T> *node = this->find(key);

			if (node)
				this->deleteNode(node);
		};
	};

	
	
	template<class Key, class T, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class RedBlackTree : public BstAlgorithm<Key, T>
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;			
		typedef ft::pair<const Key, T> value_type;

	public:
		RedBlackTree(Allocator *alloc): BstAlgorithm<Key, T>(alloc){

		};
		~RedBlackTree(){};

	
		void mergeTrees(Node<Key, T> *node, Node<Key, T> **root = NULL){
			if (!node)
				return ;
			this->findSlot(node, root);
			this->mergeTrees(node->left);
			this->mergeTrees(node->right);
		};

		void rotate(Node<Key, T> *node){
			if (ft::BstAlgorithm<Key, T>::getDirection(node) == Direction::Right){
				this->rotateLeft(node);
			} else
				this->rotateRight(node);
		}

		void rotateLeft(Node<Key, T> *node){
			Node<Key, T> *old_parent = node->parent;
			
			old_parent->right = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			Node<Key, T> *leftTree = node->left;
			node->left = old_parent;
			old_parent->parent = node;
			this->mergeTrees(leftTree, &node->left);

			if (old_parent == this->root)
				this->root = node;
		};

		void rotateRight(Node<Key, T> *node){
			Node<Key, T> *old_parent = node->parent;
			
			old_parent->left = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			Node<Key, T> *right = node->right;
			node->right = old_parent;
			old_parent->parent = node;
			this->mergeTrees(right, &node->right);

			if (old_parent == this->root)
				this->root = node;
		};

		Node<Key, T> *getSibling(Node<Key, T> *node){
			
			if (!node->parent)
				return NULL;
			if(node->parent->left != node)
				return node->parent->left;
			return node->parent->right;
		};

		ft::Color getSiblingColor(Node<Key, T> *node){
			
			if (!node->parent)
				return ft::Color::Black;
			if (node->parent->left != node){
				if (node->parent->left)
					return node->parent->left->color;
				return ft::Color::Black;
			}
			if (node->parent->right)
				return node->parent->right->color;
			return ft::Color::Black;
		};

		void	reddish(Node<Key, T> *node){
			node->color = ft::Color::Red;

			if (node->parent->color == ft::Color::Black){
				return ;
			} else if (node->parent->color == ft::Color::Red){
				ft::Color parentSiblingColor = getSiblingColor(node->parent);
				if (parentSiblingColor == ft::Color::Black){
					if (ft::BstAlgorithm<Key, T>::getDirection(node) == ft::BstAlgorithm<Key, T>::getDirection(node->parent)){
						this->rotate(node->parent);
						node->parent->color = ft::Color::Black;
						node->color = ft::Color::Red;
						this->getSibling(node)->color = ft::Color::Red;
					} else {
						this->rotate(node);
						this->rotate(node);
						node->color = ft::Color::Black;
						if (node->left)
							node->left->color = ft::Color::Red;
						if (node->right)
							node->right->color = ft::Color::Red;
					}
				} else if (parentSiblingColor == ft::Color::Red){
					node->parent->color = ft::Color::Black;
					this->getSibling(node->parent)->color = ft::Color::Black;
					if (node->parent->parent != this->root){
						this->reddish(node->parent->parent);
					}
				}	
			}
		};

		ft::Direction opositeDirection(ft::Direction dir){
			if (dir == ft::Direction::Left)
				return ft::Direction::Right;
			return ft::Direction::Left;			
		}

		Node<Key, T> *getChild(Node<Key, T> *node, ft::Direction dir){
			if (dir == ft::Direction::Left)
				return node->left;
			return node->right;
		}


		bool isBlack(Node<Key, T> *node){
			return(!node || node->color == ft::Color::Black);
		};

		bool isRed(Node<Key, T> *node){
			return(node && node->color == ft::Color::Red);
		};

		void	repassBlack(Node<Key, T> *node){
			// Case 2
			if (node == this->root)
				return ;
			Node<Key, T> *sibling = this->getSibling(node);
			// Case 3
			if (isBlack(sibling) && isBlack(sibling->left) && isBlack(sibling->right)){
				sibling->color = ft::Color::Red;
				if (node->parent->color == ft::Color::Red)
					node->parent->color == ft::Color::Black;
				else
					repassBlack(node->parent);
			}
			// Case 4
			else if (isRed(sibling)){
				sibling->color = node->parent->color;
				node->parent->color = ft::Color::Red;
				rotate(sibling);
				repassBlack(node);
			}
			// Case 5 
			else if (isBlack(sibling) &&
				isBlack(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))) && 
				isRed(getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node)))){
					Node<Key, T> *nearChild = getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node));
					sibling->color = ft::Color::Red;
					nearChild->color = ft::Color::Black;
					rotate(nearChild);				
			}
			// Case 6
			if (isBlack(sibling) &&
				isRed(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node))))){
				sibling->color = node->parent->color;
				node->parent->color = ft::Color::Black;
				rotate(sibling);
				getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))->color = ft::Color::Black;
			}
		};

		void deleteNode(Node<Key, T> *node){
			// case 1
			if (!node->left && !node->right){
				if (node->color == ft::Color::Black){
					this->repassBlack(node);
				}
				this->swapNode(node, NULL);
				delete node;
			} else if (node->left && node->right){
				Node<Key, T> *higher = this->getHigherNode(node->left);

				node->value = higher->value;
				deleteNode(higher);
			} else if (node->left || node->right){
				if (node->left){
					node->value = node->left->value;
					deleteNode(node->left);
				} else {
					node->value = node->right->value;
					deleteNode(node->right);
				}
			}
		};

		T &insert(const Key key){
			Node<Key, T> *node = this->newNode(key);
			Node<Key, T> *found;

			found = this->findSlot(node);
			if (found->value->first != node->value->first){
				delete node ;
				return found->value->second;
			}

			if (!node->parent && node != this->root){//caso ja exista
				delete node ;
				return found->value->second;
			}
			else if (node == this->root){// se for o proprio root
				return found->value->second;
			}
			this->reddish(node);
			return found->value->second;
		};
	};
}; // namespace ft

#endif // BST_ALGORTHM_HPP
