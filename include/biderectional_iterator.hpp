#if !defined(BIDIRECTIONAL_ITERATOR_HPP)
#define BIDIRECTIONAL_ITERATOR_HPP
#include <iostream>
#include "BstAlgorithm.hpp"

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

		bidirectional_iterator(ft::BstNode<Key, T> *node, int size, bool end = false) 
		: _node(node){
			this->_end = end;
			this->_size = size;
			this->_pair = NULL;

			if (node){
				while(node && node->parent)
					node = node->parent;
				this->_firstNode = node->getLowerNode(node);
				this->_lastNode = node->getHigherNode(node);
			}
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
			if (this->_end){
				this->_pair = new ft::pair<const Key, T> (_size, T());
				return *this->_pair;
			}
			return *_node->data;
		};

    	ft::pair<const Key, T> *operator->() {
			if(this->_end){
				this->_pair = new ft::pair<const Key, T> (_size, T());
				return this->_pair;
			}
			return _node->data;
		};

		bidirectional_iterator& operator++() {
			if (this->_end){
				this->_end = false;
				this->_node = this->_lastNode;
			}
			else if (this->_node->right) {
				this->_node = this->_node->getLowerNode(this->_node->right);
			}
			else if (this->_node->parent && this->_node != this->_lastNode){
				this->_coming_from = this->_node->getDirection();
				const Key key = this->_node->data->first;
				this->_node = _node->parent;
				if (this->_coming_from == ft::Direction::Right){
					while (this->_node->parent){
						this->_node = this->_node->parent;
						if (this->_node->data->first > key)
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
			bidirectional_iterator it(this->_node, this->_size);
			++(*this);
			return it;
		};

		bidirectional_iterator& operator--() {
			if (this->_end){
				this->_end = false;
				this->_node = this->_lastNode;
			}
			else if (_node == this->_firstNode){
				return *this;
			}
			else if (_node != this->_firstNode && _node->left){
				_coming_from = ft::Direction::Parent;
				this->_node = this->_node->getHigherNode(this->_node->left);
			} else if( this->_node->parent){
				_coming_from = this->_node->getDirection();
				this->_node = _node->parent;
				if (_coming_from == ft::Direction::Left){
					while (this->_node->parent)
						this->_node = this->_node->parent;
				}	
			}
			return *this;
		};

		bidirectional_iterator operator--(int) {
			bidirectional_iterator tmp(this->_node, this->size);
			--(*this);
			return tmp;
		};

		BstNode<Key, T> *getLastNode() const{
			return this->_lastNode;
		};
		
		BstNode<Key, T> *getFirstNode() const{
			return this->_firstNode;
		};


		friend bool operator== (const bidirectional_iterator& a, const bidirectional_iterator& b) {
			return a._node == b._node;
		};

    	friend bool operator!= (const bidirectional_iterator& a, const bidirectional_iterator& b) {
			return a._node != b._node;
		};

		// bidirectional_iterator operator+(difference_type d) const{
		// 	bidirectional_iterator tmp(this->_ptr + d);
		// 	return tmp;
		// }

		// bidirectional_iterator& operator+=(difference_type d){
		// 	this->_ptr += d;
		// 	return *this;
		// }

		// bidirectional_iterator operator-(difference_type d) const{
		// 	bidirectional_iterator tmp(this->_ptr - d);
		// 	return tmp;
		// }

		// bidirectional_iterator& operator-=(difference_type d){
		// 	this->_ptr -= d;
		// 	return *this;
		// }

		// difference_type operator-(bidirectional_iterator const & rhs) const {
		// 	return this->_ptr - rhs._ptr;
		// }

		// reference operator[]( difference_type n) const {
		// 	return *(this->_ptr + n);
		// }

		private:
			ft::BstNode<Key, T> 	*_node;
			ft::BstNode<Key, T>		*_lastNode;			
			ft::BstNode<Key, T>		*_firstNode;			
			ft::Direction			_coming_from;
			bool					_end;
			int						_size;
			ft::pair<const Key, T>	*_pair;

	};
};



#endif // BIDIRECtIONAL_ITERATOR_HPP
