#if !defined(RANDOM_ACCESS_ITERATOR_HPP)
#define RANDOM_ACCESS_ITERATOR_HPP
#include <iostream>

namespace ft {
template <class T> struct random_access_iterator
	{
		typedef std::random_access_iterator_tag	iterator_category;  
		typedef std::ptrdiff_t					difference_type; 	
		typedef T 								value_type;		
		typedef T* 								pointer;		
		typedef T& 								reference;		

		random_access_iterator(pointer ptr) : _ptr(ptr){}

		reference operator*() const {
			return *_ptr;
		}

    	pointer operator->() {
			return _ptr;
		}

		random_access_iterator& operator++() {
			_ptr++;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		random_access_iterator& operator--() {
			_ptr--;
			return *this;
		}

		random_access_iterator operator--(int) {
			random_access_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		friend bool operator== (const random_access_iterator& a, const random_access_iterator& b) {
			return a._ptr == b._ptr;
		};

    	friend bool operator!= (const random_access_iterator& a, const random_access_iterator& b) {
			return a._ptr != b._ptr;
		};

		private:
			pointer	_ptr;
	};
};



#endif // RANDOM_ACCESS_ITERATOR_HPP
