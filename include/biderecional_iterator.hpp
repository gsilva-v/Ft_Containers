#if !defined(BIDIRECIONAL_ITERATOR_HPP)
#define BIDIRECIONAL_ITERATOR_HPP
#include <iostream>

namespace ft {
template <class T> struct bidirecional_iterator
	{
		typedef std::bidirecional_iterator_tag	iterator_category;
		typedef T::difference_type				difference_type;
		typedef T::size_type					size_type;
		typedef T::value_type					value_type;
		typedef T::pointer*						pointer;
		typedef T::reference& 					reference;

		bidirecional_iterator(pointer node = pointer()) : _node(node){}

		reference operator*() const {
			return *_node->value->second;
		}

    	pointer operator->() {
			return _node->value->second;
		}

		bidirecional_iterator& operator++() {
			_node->value->second++;
			return *this;
		}

		bidirecional_iterator operator++(int) {
			bidirecional_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		bidirecional_iterator& operator--() {
			_node->value->second--;
			return *this;
		}

		bidirecional_iterator operator--(int) {
			bidirecional_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		// friend bool operator== (const bidirecional_iterator& a, const bidirecional_iterator& b) {
		// 	return a._node->value->second == b._ptr;
		// }

    	// friend bool operator!= (const bidirecional_iterator& a, const bidirecional_iterator& b) {
		// 	return a._ptr != b._ptr;
		// }

		// bidirecional_iterator operator+(difference_type d) const{
		// 	bidirecional_iterator tmp(this->_ptr + d);
		// 	return tmp;
		// }

		// bidirecional_iterator& operator+=(difference_type d){
		// 	this->_ptr += d;
		// 	return *this;
		// }

		// bidirecional_iterator operator-(difference_type d) const{
		// 	bidirecional_iterator tmp(this->_ptr - d);
		// 	return tmp;
		// }

		// bidirecional_iterator& operator-=(difference_type d){
		// 	this->_ptr -= d;
		// 	return *this;
		// }

		// difference_type operator-(bidirecional_iterator const & rhs) const {
		// 	return this->_ptr - rhs._ptr;
		// }

		// reference operator[]( difference_type n) const {
		// 	return *(this->_ptr + n);
		// }

		private:
			ft::Node<T> *_node;
	};
};



#endif // BIDIRECIONAL_ITERATOR_HPP
