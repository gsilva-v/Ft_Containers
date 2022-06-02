#pragma once

// #include "BstUtils.hpp"
#include "utility.hpp"
#include "functional.hpp"
#include <memory>


namespace ft
{
	enum Color{
		Black,
		Red
	};
	enum Direction{
		Left,
		Right,
		Parent,
		None
	};

  	template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class BstNode
	{		
	private:


	public:
		typedef Key key_type;
		typedef T mapped_type;			
		typedef ft::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		BstNode<Key, T> *right;
		BstNode<Key, T> *left;
		BstNode<Key, T> *parent;
		pointer data;
		int color;
		int size;
		value_type 	value;
		
	protected:
		allocator_type _alloc;
		
	public:
		BstNode(const Allocator& alloc = Allocator()): _alloc(alloc){
			this->right = NULL;
			this->left = NULL;
			this->parent = NULL;
			this->data = NULL;
			this->size = 0;
			this->color = Color::Black;
		};

		BstNode(const Key &key , const Allocator& alloc = Allocator()): _alloc(alloc){
			this->right = NULL;
			this->left = NULL;
			this->parent = NULL;
			this->data = this->_alloc.allocate(1);
			this->size = 1;
			this->_alloc.construct(this->data, ft::pair<const Key, T>(key,T()));
			this->color = Color::Black;
		};

		BstNode(value_type &value , const Allocator& alloc = Allocator()): _alloc(alloc){
			this->right = NULL;
			this->left = NULL;
			this->parent = NULL;
			this->data = this->_alloc.allocate(1);
			this->size = 1;
			this->_alloc.construct(this->data, value);
			this->color = Color::Black;
		};


		~BstNode(){
			if (this->data){
				this->_alloc.destroy(this->data);
				this->_alloc.deallocate(this->data, 1);
			}
		};
		
		size_type maxSize() const{
			return Allocator().max_size();
		};


		BstNode<Key, T>	*findSlot(BstNode<Key, T> *node){	
			BstNode<Key, T> *init = this;

			while (init)
			{
				if (init->getDirection() == ft::Direction::Right){
					if (node->data->first < init->parent->data->first){
						init = init->parent;
						continue ;
					} 
					else if (node->data->first == init->parent->data->first)
						return init->parent;
				}
				else if (init->getDirection() == ft::Direction::Left){
					if (node->data->first > init->parent->data->first){
						init = init->parent;
						continue ;
					} 
					else if (node->data->first == init->parent->data->first)
						return init->parent;
				}
				if (node->data->first < init->data->first){
					if (!init->left){
						node->parent = init;
						init->left = node;
						break ;
					} else
						init = init->left;
				}
				else if (node->data->first > init->data->first){
					if (!init->right ){
						node->parent = init;
						init->right = node;
						break ;
					} else
						init = init->right;
				}
				else
					return init;
			}
			this->size += 1;
			return node;
		};

		BstNode<Key, T> *getSibling(){
			if (!this->parent)
				return NULL;
			if(this->parent->left != this)
				return this->parent->left;
			return this->parent->right;
		};


		void rotate(BstNode<Key, T> *node, BstNode<Key, T> **root){
			if (node->getDirection() == Direction::Right){
				this->rotateLeft(node, root);
			} else
				this->rotateRight(node, root);
		}

		void mergeTrees(BstNode<Key, T> *node, BstNode<Key, T> **root = NULL){
			if (!node)
				return ;
			this->findSlot(node);
			this->mergeTrees(node->left, root);
			this->mergeTrees(node->right, root);
		};

		void rotateLeft(BstNode<Key, T> *node, BstNode<Key, T> **root){
			BstNode<Key, T> *old_parent = node->parent;
			
			old_parent->right = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && old_parent->getDirection() == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			BstNode<Key, T> *leftTree = node->left;
			node->left = old_parent;
			old_parent->parent = node;
			this->mergeTrees(leftTree, &node->left);

			if (old_parent == *root)
				*root = node;
		};

		void rotateRight(BstNode<Key, T> *node,  BstNode<Key, T> **root){
			BstNode<Key, T> *old_parent = node->parent;
			
			old_parent->left = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && old_parent->getDirection() == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			BstNode<Key, T> *right = node->right;
			node->right = old_parent;
			old_parent->parent = node;
			this->mergeTrees(right, &node->right);

			if (old_parent == *root)
				*root = node;
		};

		T &insert(const Key &key , BstNode<Key, T> **root){
			if (this->data == NULL){
				this->data = this->_alloc.allocate(1);
				this->size += 1;
				this->_alloc.construct(this->data, ft::pair<const Key, T>(key,T()));
				return this->data->second;
			}
			
			BstNode<Key, T> *new_node = new BstNode<Key, T>(key);
			BstNode<Key, T> *found;
			found = findSlot(new_node);
			if (!new_node->parent)
				delete new_node;
			else 
				this->checkBalance(new_node, new_node, root);
			return found->data->second;
		};


		int checkHeight(BstNode<Key, T> *node){
			int size = 0;

			while (node)
			{
				BstNode<Key, T> *sibling = node->getSibling();
				if (node->left)
					node = node->left;
				else if (node->right)
					node = node->right;
				else if (sibling && sibling->right)
					node = sibling->right;
				else if (sibling && sibling->left)
					node = sibling->left;
				else
					node = NULL;
				size++;
			}
			return size;
			

		}


		void checkBalance(BstNode<Key, T> *node, BstNode<Key, T> *new_node, BstNode<Key, T> **root){
			if (!node)
				return ;
			int difference = checkHeight(node->left) - checkHeight(node->right);
			if (difference < -1){
				// direita
				// if (checkHeight(node->right->right) > checkHeight(node->right->left)){
				if (new_node->getDirection() == Direction::Right){
					rotate(node->right, root);
					return ;
				}
				else {
					rotate(new_node, root);
					rotate(node->left, root);
					return ;
				}

			}
			
			if (difference > 1){
				// esquerda
				if (checkHeight(node->left->left) > checkHeight(node->left->right)){
					rotate(node->left, root);
					return ;
				}
				else {
					rotate(node->left->right, root);
					rotate(node->right, root);
					return ;
				}
			}

			this->checkBalance(node->parent, new_node, root);
		}



		bool insert(const value_type &value, BstNode<Key, T> **root){
			if (this->data == NULL){
				this->data = this->_alloc.allocate(1);
				this->size += 1;
				this->_alloc.construct(this->data, value);
				return true;
			}
			
			BstNode<Key, T> *new_node = new BstNode<Key, T>(value);
			BstNode<Key, T> *found;
			found = findSlot(new_node);
			if (!new_node->parent){
				delete new_node;
				return false;
			}
			this->checkBalance(new_node, new_node, root);
			return true;
		};

		
		Direction getDirection(){
			if (this->parent == NULL){
				return Direction::None;
			}
			if (this->parent->right == this)
				return Direction::Right;
			return Direction::Left;
		};

		BstNode<Key, T> *getHigherNode(BstNode<Key, T> *node){
			while (node && node->right)
				node = node->right;
			return node;
		}

		BstNode<Key, T> *getLowerNode(BstNode<Key, T> *node){
			while (node && node->left)
				node = node->left;
			return node;
		}

		void	swapNode(BstNode<Key, T> *node, BstNode<Key, T> *sub){
			if (!node)
					return;

			if (sub){
				node->left = sub->left;
				if (sub->left)
					sub->left->parent = node->parent;
				node->right = sub->right;
				if (sub->right)
					sub->right->parent = node;
				node->parent = sub->parent->parent;
				this->_alloc.destroy(node->data);
				this->_alloc.deallocate(node->data, 1);
				node->data = sub->data;
			}
			else {
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				this->_alloc.destroy(node->data);
				this->_alloc.deallocate(node->data, 1);
				node->data = NULL;
			}
			// 	if (node->right != sub && node->right){
			// 		sub->right = node->right;
			// 		node->right->parent = sub;
			// 	}
			// }
		
			// if (node->parent){
			// 	if (node->parent->left == node)
			// 		node->parent->left = sub;
			// 	else
			// 		node->parent->right = sub;
			// }		
			// else{
			// 	this->left = sub->left;
			// 	this->right = sub->right;
			// 	this->data = sub->data;
			// 	delete sub;
			// }
		};

		void deleteNode(BstNode<Key, T> *node){
			// std::cout << "debug node \nright: " << *(&node->right) << std::endl;
			// std::cout << "left: " << *(&node->left->data->first) << std::endl;
			// std::cout << "parent: " << *(&node->parent->data->first) << std::endl;
			// std::cout << "node: " << *(&node->data->first) << std::endl;
			if (!node->left && !node->right){//se nao houver nenhum filho
				this->swapNode(node, NULL);
			} else if (node->left && node->right){ //caso tenham 2 filhos
				BstNode<Key, T> *higher = this->getHigherNode(node->left);
				this->swapNode(higher, higher->left);
				higher->left = NULL;
				higher->right = NULL;
				this->swapNode(node, higher);
			} else if (node->left || node->right){ //caso tenha 1 filho
				if (node->left){
					this->swapNode(node, node->left);
					// std::cout << "debug node 2 \nright: " << *(&node->right) << std::endl;
					// std::cout << "left: " << *(&node->left) << std::endl;
					// std::cout << "parent: " << *(&node->parent->data->first) << std::endl;
					// std::cout << "node: " << *(&node->data->first) << std::endl;
				} else {
					this->swapNode(node, node->right);
				}
			}
		};

		BstNode<Key, T> *find(const Key key){
			BstNode<Key, T> *init = this;

			while (init)
			{
				if (key == init->data->first){
					return init;
				} else if (key < init->data->first)
					init = init->left;
				else if (key > init->data->first)
					init = init->right;
			}
			return NULL;
		};

		bool remove(const Key key){
			BstNode<Key, T> *node = this->find(key);
		
			if (node){
				this->deleteNode(node);
				this->size -= 1;
				return true;	
			}
			return false;	
		};
	};  // BstNode




}