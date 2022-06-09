#if !defined(BST_ALGORTHM_HPP)
#define BST_ALGORTHM_HPP

#include <iostream>
#include "utility.hpp"
#include "functional.hpp"

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
			new_node->color = 0;
			new_node->value = this->_alloc->allocate(1);
			this->_alloc->construct(new_node->value, value_type(key, T()));
			return new_node;
		}

		Node<Key, T> *newNode(value_type value){
			Node<Key, T> *new_node = new Node<Key, T>;

			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->color = 0;
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
					}
					init = init->left;
				}
				else if (!(_comp(node->value->first, init->value->first))){
					if (!init->right){
						node->parent = init;
						init->right = node;
						this->size++;
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
				return 2;
			return 1;
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
			this->size --;
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
			if (ft::BstAlgorithm<Key, T>::getDirection(node) == 2){
				this->rotateLeft(node);
				
			} else
				this->rotateRight(node);
		}

		void rotateLeft(Node<Key, T> *node){
			Node<Key, T> *old_parent = node->parent;
			old_parent->right = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == 2){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;
			Node<Key, T> *leftTree = node->left;
			node->left = old_parent;
			old_parent->parent = node;
			size_t holder_size = this->size;
			this->mergeTrees(leftTree, &node->left);
			this->size = holder_size;
			if (old_parent == this->root)
				this->root = node;
		};

		void rotateRight(Node<Key, T> *node){
			Node<Key, T> *old_parent = node->parent;
			
			old_parent->left = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && ft::BstAlgorithm<Key, T>::getDirection(old_parent) == 2){
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

		int getSiblingColor(Node<Key, T> *node){
			
			if (!node->parent)
				return 0;
			if (node->parent->left != node){
				if (node->parent->left)
					return node->parent->left->color;
				return 0;
			}
			if (node->parent->right)
				return node->parent->right->color;
			return 0;
		};

		void	reddish(Node<Key, T> *node){
			node->color = 1;

			if (node->parent->color == 0){
				return ;
			} else if (node->parent->color == 1){
				int parentSiblingColor = getSiblingColor(node->parent);
				if (parentSiblingColor == 0){
					if (ft::BstAlgorithm<Key, T>::getDirection(node) == ft::BstAlgorithm<Key, T>::getDirection(node->parent)){
						this->rotate(node->parent);
						node->parent->color = 0;
						node->color = 1;
						this->getSibling(node)->color = 1;
					} else {
						this->rotate(node);
						this->rotate(node);
						node->color = 0;
						if (node->left)
							node->left->color = 1;
						if (node->right)
							node->right->color = 1;
					}
				} else if (parentSiblingColor == 1){
					node->parent->color = 0;
					this->getSibling(node->parent)->color = 0;
					if (node->parent->parent != this->root){
						this->reddish(node->parent->parent);
					}
				}	
			}
		};

		int opositeDirection(int dir){
			if (dir == 1)
				return 2;
			return 1;			
		}

		Node<Key, T> *getChild(Node<Key, T> *node, int dir){
			if (node){
				if (dir == 1)
					return node->left;
				return node->right;
			}
			return NULL;
		}


		bool isBlack(Node<Key, T> *node){
			return(!node || node->color == 0);
		};

		bool isRed(Node<Key, T> *node){
			return(node && node->color == 1);
		};

		void	repassBlack(Node<Key, T> *node){
			// Case 2

			if (node == this->root)
				return ;
			Node<Key, T> *sibling = this->getSibling(node);
			// Case 3
			if (sibling && isBlack(sibling) && isBlack(sibling->left) && isBlack(sibling->right)){
				
				sibling->color = 1;
				if (node->parent->color == 1)
					node->parent->color = 0;
				else
					repassBlack(node->parent);
			}
			// Case 4
			else if (isRed(sibling)){
				sibling->color = node->parent->color;
				node->parent->color = 1;
				rotate(sibling);
				repassBlack(node);
			}
			// Case 5 
			else if (isBlack(sibling) &&
				isBlack(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))) && 
				isRed(getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node)))){
					Node<Key, T> *nearChild = getChild(sibling,ft::BstAlgorithm<Key, T>::getDirection(node));
					sibling->color = 1;
					nearChild->color = 0;
					rotate(nearChild);			
			}
			// Case 6
			if (isBlack(sibling) &&
				isRed(getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node))))){
				sibling->color = node->parent->color;
				node->parent->color = 0;
				rotate(sibling);
			
				getChild(sibling, opositeDirection(ft::BstAlgorithm<Key, T>::getDirection(node)))->color = 0;
			}
		};

		void deleteNode(Node<Key, T> *node){
			// case 1
			if (!node->left && !node->right){
				
				if (node->color == 0){
					this->repassBlack(node);
				}
				this->swapNode(node, NULL);
				this->_alloc->destroy(node->value);
				this->_alloc->deallocate(node->value, 1);
				this->size--;
				delete node;
			} else if (node->left && node->right){
				Node<Key, T> *higher = this->getHigherNode(node->left);
				value_type *holder = node->value;
				node->value = higher->value;
				higher->value = holder;
				deleteNode(higher);
			} else if (node->left || node->right){
				if (node->left){
					value_type *holder = node->value;
					node->value = node->left->value;
					node->left->value = holder;
					deleteNode(node->left);
				} else {
					value_type *holder = node->value;
					node->value = node->right->value;
					node->right->value = holder;
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

		bool insert(const value_type &value){
			Node<Key, T> *node = this->newNode(value);
			Node<Key, T> *found;
			found = this->findSlot(node);
			if (found->value->first != node->value->first){
				delete node ;
				return false;
			}
			if (!node->parent && node != this->root){//caso ja exista
				delete node ;
				return false;
			}
			else if (node == this->root){// se for o proprio root
				return true;
			}
			this->reddish(node);
			return true;
		};
	};
}; // namespace ft

#endif // BST_ALGORTHM_HPP
