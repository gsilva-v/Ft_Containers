#if !defined(BSTALGORITHM_HPP)
#define BSTALGORITHM_HPP

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
			this->size = 1;
			this->color = Color::Black;
		};

		BstNode(const Key &key , const Allocator& alloc = Allocator()): _alloc(alloc){
			BstNode<Key, T> *new_node = new BstNode<Key, T>;

			this->right = NULL;
			this->left = NULL;
			this->parent = NULL;
			this->data = this->_alloc.allocate(1);
			this->size = 1;
			this->_alloc.construct(this->data, ft::pair<const Key, T>(key,T()));
			this->color = Color::Black;
		};


		~BstNode(){
			if (this->data){
				this->_alloc.destroy(this->data);
				this->_alloc.deallocate(this->data, this->size);
			}
		};
		
		size_type maxSize() const{
			return Allocator().max_size();
		};


		BstNode<Key, T>	*findSlot(BstNode<Key, T> *node){	
			BstNode<Key, T> *init = this;

			while (init)
			{
				if (node->data->first < init->data->first){
					if (!init->left){
						node->parent = init;
						init->left = node;
						break ;
					} else
						init = init->left;
				}
				else if (node->data->first > init->data->first){
					if (!init->right){
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

		virtual T &insert(const Key &key){
			if (this->data == NULL){
				this->data = this->_alloc.allocate(1);
				this->_alloc.construct(this->data, ft::pair<const Key, T>(key,T()));
				return this->data->second;
			}
			
			BstNode<Key, T> *new_node = new BstNode<Key, T>(key);
			BstNode<Key, T> *found;
			found = findSlot(new_node);
			if (!new_node->parent)
				delete new_node;	
			return found->data->second;
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
			else{
				this->left = sub->left;
				this->right = sub->right;
				this->data = sub->data;
				delete sub;

			}
		};

		virtual void deleteNode(BstNode<Key, T> *node){
			if (!node->left && !node->right){//se nao houver nenhum filho
				this->swapNode(node, NULL);
			} else if (node->left && node->right){ //caso tenham 2 filhos
				BstNode<Key, T> *higher = this->getHigherNode(node->left);
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

		void remove(const Key key){
			BstNode<Key, T> *node = this->find(key);

			if (node)
				this->deleteNode(node);
		};
	};

};

#endif // BSTALGORITHM_HPP