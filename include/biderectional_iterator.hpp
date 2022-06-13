#if !defined(BIDIRECTIONAL_ITERATOR_HPP)
#define BIDIRECTIONAL_ITERATOR_HPP
#include <iostream>
#include "RedBlackTree.hpp"

namespace ft {

template <typename Key, typename T> struct bidirectional_iterator
	{
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef  std::ptrdiff_t					difference_type;
		typedef  ft::pair<const Key, T>			value_type;
		typedef  value_type*					pointer;
		typedef  value_type& 					reference;

		bidirectional_iterator() 
		: _node(NULL), _firstNode(NULL), _lastNode(NULL), _end(false), _size(0){
			this->_pair = NULL;
		};

		bidirectional_iterator(ft::Node<Key, T> *node, ft::Node<Key, T> *first, ft::Node<Key, T> *last,int size, bool end = false) 
		: _node(node){
			this->_end = end;
			this->_size = size;
			this->_pair = NULL;

			this->_firstNode = first;
			this->_lastNode = last;
			if (end){
				this->_node = NULL;
			}
		};

		template <typename k, typename t>
		bidirectional_iterator(bidirectional_iterator<k, t> &other) 
		: _node(other._node){
			this->_pair = NULL;
			this->_firstNode = other._firstNode;
			this->_lastNode = other._lastNode;
			this->_end = other._end;
			this->_size = other._size;
		};

		template <typename k, typename t>
		bidirectional_iterator<k, t> &operator=(bidirectional_iterator<k, t> &other) 
		{
			this->_node = other._node;
			this->_firstNode = other._firstNode;
			this->_lastNode = other._lastNode;
			this->_end = other._end;
			this->_size = other._size;
			return *this;
		};

		~bidirectional_iterator(){
			if (this->_pair){
				delete _pair;
				this->_pair = NULL;
			}
		};

		ft::pair<const Key, T> &operator*()  {
			return *_node->value;
		};

    	ft::pair<const Key, T> *operator->() {
			if (!this->_end)
				return _node->value;
			return NULL;
		};

		bidirectional_iterator& operator++() {
			if (this->_end){
				this->_end = false;
				this->_node = this->_lastNode;
			}
			else if (this->_node->right) {
				this->_node = ft::BstAlgorithm<Key, T>::getLowerNode(this->_node->right);
			}
			else if (this->_node->parent && this->_node != this->_lastNode){
				this->_coming_from = ft::BstAlgorithm<Key, T>::getDirection(this->_node);
				const Key key = this->_node->value->first;
				this->_node = _node->parent;
				if (this->_coming_from == 2){
					while (this->_node->parent){
						this->_node = this->_node->parent;
						if (this->_node->value->first > key)
							break;
					}
				}
			}
			else {
				this->_end = true;
				this->_node = NULL;
			}
		
			return *this;
		};

		bidirectional_iterator operator++(int) {
			bidirectional_iterator it(this->_node, this->_firstNode, this->_lastNode, this->_size);
			++(*this);
			return it;
		};

		bidirectional_iterator& operator--() {
			
			if (this->_end){
				this->_end = false;
				this->_node = this->_lastNode;
			} else if (_node == this->_firstNode){
				this->_end = false;
				this->_node = this->_lastNode;
				
			} else if (_node != this->_firstNode && _node->left){
				_coming_from = 0;
				this->_node = ft::BstAlgorithm<Key, T>::getHigherNode(this->_node->left);
			} else if( this->_node->parent){
				_coming_from = ft::BstAlgorithm<Key, T>::getDirection(this->_node);
				Key key = this->_node->value->first;
				this->_node = _node->parent;
				if (_coming_from == 1){
					while (this->_node && this->_node->parent){
						this->_node = this->_node->parent;
						if (this->_node->value->first < key)
							break;
					}
				}	
			} else {
				this->_end = true;
				this->_node = NULL;
			}
			return *this;
		};

		bidirectional_iterator operator--(int) {
			bidirectional_iterator tmp(
				this->_node, this->_firstNode, this->_lastNode, this->_size);
			--(*this);
			return tmp;
		};

		Node<Key, T> *getLastNode() const{
			return this->_lastNode;
		};
		
		Node<Key, T> *getFirstNode() const{
			return this->_firstNode;
		};


		friend bool operator== (const bidirectional_iterator& a, const bidirectional_iterator& b) {
			return a._node == b._node;
		};

    	friend bool operator!= (const bidirectional_iterator& a, const bidirectional_iterator& b) {
			return a._node != b._node;
		};


		private:
			ft::Node<Key, T> 		*_node;
			ft::Node<Key, T>		*_firstNode;			
			ft::Node<Key, T>		*_lastNode;			
			int						_coming_from;
			bool					_end;
			size_t					_size;
			ft::pair<const Key, T>	*_pair;

	};
};

#endif // BIDIRECtIONAL_ITERATOR_HPP
