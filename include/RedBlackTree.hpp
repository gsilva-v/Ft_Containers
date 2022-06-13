#if !defined(BST_ALGORTHM_HPP)
#define BST_ALGORTHM_HPP

#include <iostream>
#include "utility.hpp"
#include "functional.hpp"
#define RIGHT 2
#define LEFT 1
#define PARENT 0
#define BLACK 0
#define RED 1

namespace ft
{

	template <typename Key, typename T> 
	struct Node
	{
		Node<Key, T>	*parent;
		ft::pair<const Key, T>	*value;
		Node<Key, T>	*left;
		Node<Key, T>	*right;
		int 	color;
	};

  	template<class Key, class T, class Compare = ft::less<const Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class BstAlgorithm
	{	
	protected:
		std::allocator<ft::pair<const Key, T> > *_alloc;

	public:
		typedef Key key_type;
		typedef T mapped_type;			
		typedef ft::pair<const Key, T> value_type;
		size_t size;
		Compare _comp;
		Node<Key, T> *root;

	public:
		BstAlgorithm(Allocator *alloc):_alloc(alloc), size(0),root(NULL) {};
		~BstAlgorithm(){};

		Node<Key, T> *newNode(Key key){
			Node<Key, T> *new_node = new Node<Key, T>;

			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->color = BLACK;
			new_node->value = this->_alloc->allocate(1);
			this->_alloc->construct(new_node->value, value_type(key, T()));
			return new_node;
		}

		Node<Key, T> *newNode(value_type value){
			Node<Key, T> *new_node = new Node<Key, T>;

			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->color = BLACK;
			new_node->value = this->_alloc->allocate(1);
			this->_alloc->construct(new_node->value, value);
			return new_node;
		}

		Node<Key, T>	*findSlot(Node<Key, T> *node, Node<Key, T> **root = NULL){	
			Node<Key, T> *init;

			if (root == NULL)
				root = &this->root;
			if (*root == NULL){
				*root = node;
				this->size++;
				return node;
			} else
				init = *root;
			while (init)
			{
				if (node->value->first == init->value->first)				
					return init;
				else if (_comp(node->value->first, init->value->first)){
					if (!init->left){
						node->parent = init;
						init->left = node;
						this->size++;
						break ;
					}
					init = init->left;
				}
				else if (!(_comp(node->value->first, init->value->first))){
					if (!init->right){
						node->parent = init;
						init->right = node;
						this->size++;
						break ; 
					}
					init = init->right;
				}
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

		static int getDirection(Node<Key, T> *node){
			if (node->parent->right == node)
				return RIGHT;
			return LEFT;
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
			if (!node->left && !node->right){//case don't have child
				this->swapNode(node, NULL);
			} else if (node->left && node->right){ //case have 2 child
				Node<Key, T> *higher = this->getHigherNode(node->left);
				this->swapNode(higher, higher->left);
				higher->left = NULL;
				higher->right = NULL;
				this->swapNode(node, higher);
			} else if (node->left || node->right){ //case have 1 child
				if (node->left){
					this->swapNode(node, node->left);
				} else {
					this->swapNode(node, node->right);
				}
			}
			delete node;
			this->size--;
		};

		void	connectFamily(Node<Key, T> *node){
			if (node->parent){
				if (getDirection(node) == RIGHT)
					node->parent->right = node;
				else 					
					node->parent->left = node;
			}
			else 
				this->root = node;
			if (node->left){
				node->left->parent = node;
			}
			if (node->right){
				node->right->parent = node;
			}

		}

		void	swapPointers(Node<Key, T> *node1, Node<Key, T> *node2){
			Node<Key, T> *parentHolder = node1->parent;
			Node<Key, T> *leftHolder = node1->left;
			Node<Key, T> *rightHolder = node1->right;
			this->swap(node1->color, node2->color);
			node1->parent = node2->parent == node1 ? node2 : node2->parent;
			node1->left = node2->left == node1 ? node2 : node2->left;
			node1->right = node2->right == node1 ? node2 : node2->right;
			node2->parent = parentHolder == node2 ? node1 : parentHolder;
			node2->left = leftHolder == node2 ? node1 : leftHolder;
			node2->right = rightHolder == node2 ? node1 : rightHolder;
		}

		void	swapNode(Node<Key, T> *node, Node<Key, T> *sub){
			this->swapPointers(node, sub);
			this->connectFamily(sub);
			this->connectFamily(node);
		}


		template <typename J>
		void swap(J &n1, J &n2){
			J holder = n1;
			n1 = n2;
			n2 = holder;
		}

		Node<Key, T> *find(Key key, Node<Key, T> *root = NULL){
			if (!root)
				root = this->root;			
			Node<Key, T> *init = this->root;
			while (init)
			{
				if (key == init->value->first){
					return init;
				} else if (_comp(key, init->value->first))
					init = init->left;
				else if (!_comp(key, init->value->first))
					init = init->right;
			}
			return NULL;
		};

		bool remove(Key key){
			Node<Key, T> *node = this->find(key);
			if (node){
				this->deleteNode(node);
				return true;
			}
			return false;
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
		RedBlackTree(Allocator *alloc = new Allocator()): BstAlgorithm<Key, T>(alloc){

		};
		~RedBlackTree(){};

	
		void mergeTrees(Node<Key, T> *node, Node<Key, T> **root){
			if (!node)
				return ;
			this->findSlot(node, root);
			this->mergeTrees(node->left, root);
			this->mergeTrees(node->right, root);
		};

		void rotate(Node<Key, T> *node){
			size_t holder_size = this->size;
			if (ft::BstAlgorithm<Key, T>::getDirection(node) == RIGHT){
				this->rotateLeft(node);
				
			} else
				this->rotateRight(node);
			this->size = holder_size;
		}

		void rotateLeft(Node<Key, T> *node){
			Node<Key, T> *old_parent = node->parent;
			old_parent->right = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == LEFT){
				node->parent->left = node;
			} else if (old_parent->parent)
				node->parent->right = node;
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
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == LEFT){
				node->parent->left = node;
			} else if (old_parent->parent)
				node->parent->right = node;

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

		int getSiblingColor(Node<Key, T> *node){
			if (!node->parent)
				return BLACK;
			if (node->parent->left != node){
				if (node->parent->left)
					return node->parent->left->color;
				return BLACK;
			}
			if (node->parent->right)
				return node->parent->right->color;
			return BLACK;
		};

		int getParentSiblingColor(Node<Key, T> *node){
			if (!node->parent)
				return (BLACK);
			if (!node->parent->parent)
				return (BLACK);
			Node<Key, T> *sibling;
			if (node->parent->parent->left != node->parent)
				sibling = node->parent->parent->left;
			else
				sibling = node->parent->parent->right;
			if (sibling)
				return (sibling->color);
			return (BLACK);
		};

		void	reddish(Node<Key, T> *node){
			node->color = RED;
			if (node->parent->color == BLACK){
				return ;
			} else if (node->parent->color == RED){
				int parentSiblingColor = this->getParentSiblingColor(node);
				if (parentSiblingColor == BLACK){
					if (ft::BstAlgorithm<Key, T>::getDirection(node) == ft::BstAlgorithm<Key, T>::getDirection(node->parent)){
						this->rotate(node->parent);
						node->parent->color = BLACK;
						node->color = RED;
						this->getSibling(node)->color = RED;
					} else {
						this->rotate(node);
						this->rotate(node);
						node->color = BLACK;
						if (node->left)
							node->left->color = RED;
						if (node->right)
							node->right->color = RED;
					}
				} else {
					node->parent->color = BLACK;
					this->getSibling(node->parent)->color = BLACK;
					if (node->parent->parent != this->root){
						this->reddish(node->parent->parent);
					}
				}	
			}
		};

		int opositeDirection(int dir){
			if (dir == LEFT)
				return RIGHT;
			return LEFT;			
		}

		Node<Key, T> *getChild(Node<Key, T> *node, int dir){
			if (node){
				if (dir == LEFT)
					return node->left;
				return node->right;
			}
			return NULL;
		}


		bool isBlack(Node<Key, T> *node){
			return(!node || node->color == BLACK);
		};

		bool isRed(Node<Key, T> *node){
			return(node && node->color == RED);
		};

		void	repassBlack(Node<Key, T> *node){
			// Case 2
			if (node == this->root)
				return ;
			Node<Key, T> *sibling = this->getSibling(node);
			// Case 3
			if (sibling && isBlack(sibling) && isBlack(sibling->left) && isBlack(sibling->right)){
				sibling->color = RED;
				if (node->parent->color == RED)
					node->parent->color = BLACK;
				else
					repassBlack(node->parent);
			}
			// Case 4
			else if (isRed(sibling)){
				sibling->color = node->parent->color;
				node->parent->color = RED;
				rotate(sibling);
				repassBlack(node);
			}
			// Case 5 
			else if (isBlack(sibling) &&
				isBlack(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))) && 
				isRed(getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node)))){
					Node<Key, T> *nearChild = getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node));
					nearChild->color = BLACK;
					sibling->color = RED;
					rotate(getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node)));
					repassBlack(node);
			}
			// Case 6
			else if (isBlack(sibling) &&
				isRed(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node))))){
				sibling->color = node->parent->color;
				node->parent->color = BLACK;
				getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))->color = BLACK;
				rotate(sibling);
			}
		};


		void deleteNode(Node<Key, T> *node){
			// case 1
			if (!node->left && !node->right){
				if (node->color == BLACK)
					this->repassBlack(node);
				if (node->parent){
					if (this->getDirection(node) == LEFT)
						node->parent->left = NULL;
					else
						node->parent->right = NULL;
				}
				else
					this->root = NULL;
				this->_alloc->destroy(node->value);
				this->_alloc->deallocate(node->value, 1);
				this->size--;
				delete node;
			} else if (node->left && node->right){
				Node<Key, T> *higher = this->getHigherNode(node->left);
				this->swapNode(node, higher);
				deleteNode(node);
			} else if (node->left || node->right){
				if (node->left)
					this->swapNode(node, node->left);
				else
					this->swapNode(node, node->right);
				deleteNode(node);
			}
		};
		

		T &insert(const Key key){
			Node<Key, T> *node = this->newNode(key);
			Node<Key, T> *found;

			found = this->findSlot(node);
			if (found->value->first != node->value->first){
				delete node; 
				return found->value->second;
			}
			if (!node->parent && node != this->root){
				delete node ;
				return found->value->second;
			}
			else if (node == this->root){
				return found->value->second;
			}
			this->reddish(node);
			return found->value->second;
		};

		bool insert(const value_type &value){
			Node<Key, T> *node = this->newNode(value);
			Node<Key, T> *found;
			found = this->findSlot(node);
			if (found->value->first != node->value->first){
				delete node ;
				return false;
			}
			if (!node->parent && node != this->root){
				delete node ;
				return false;
			}
			else if (node == this->root){
				return true;
			}
			this->reddish(node);
			return true;
		};
	};
}; // namespace ft

#endif // BST_ALGORTHM_HPP
