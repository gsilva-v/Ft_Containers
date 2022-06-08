#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <exception>
#include <sstream>
#include <cmath>


#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template < class T,class Allocator = std::allocator<T> > 
	class vector
	{
	public:
	// Member Types
		typedef	T											value_type;
		typedef	Allocator									allocator_type;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::random_access_iterator<value_type>		iterator;
		typedef ft::random_access_iterator<value_type> 		const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
		
	// Member functions
	// Contructors (docs: https://en.cppreference.com/w/cpp/container/vector/vector)

		explicit vector(const Allocator& alloc = Allocator())//until C++17 (2)
		: _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL){}
		
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())//until C++11 (3)
		: _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL){
			_start = _alloc.allocate(count);
			_end_capacity = _start + count;
			_end = _start;
			while (count--){
				_alloc.construct(_end, value);
				_end++;
			}
		}

		template <class InputIt>
		vector(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator())//until C++20 (5)
		: _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL)
		{
			this->insert(this->begin(), first, last);
		}
		
		vector(const vector& other)//until C++20 (6)
		: _alloc(other._alloc), _start(NULL), _end(NULL), _end_capacity(NULL){
			this->insert(this->begin(), other.begin(), other.end());
		}
		
		// Destructor
		~vector(){
			this->clear();
			if (_start)
				_alloc.deallocate(_start, this->capacity());
		}
		// Assigners
		/*
		** @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
		** 
		** @param other another container to use as data source
		** 
		** @return *this
		*/
		vector	&operator=(vector const &other)
		{
			this->clear();
			this->insert(this->begin(), other.begin(), other.end());
			return (*this);
		}

		/*
		** @brief Replaces the contents with count copies of value value.
		** 
		** @param count	the new size of the container
		** @param value	the value to initialize elements of the container with
		** 
		** 
		*/
		void assign( size_type count, const T& value ){
			this->clear();
			this->insert(this->begin(), count, value);
		}

		/*
		** @brief Replaces the contents with copies of those in the range [first, last). 
			The behavior is undefined if either argument is an iterator into *this..
		** 
		** @param first
		** @param last  the range to copy the elements from
		** 
		** 
		*/
		template <class InputIt> 
		void assign(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last){
			this->clear();
			this->insert(this->begin(), first, last);
		}

		// Getter
		/*
		** @brief Returns the allocator associated with the container.
		** 
		** @param none
		** 
		** @return The associated allocator.
		*/
		allocator_type get_allocator() const{
			return (this->_alloc);
		}

	// Element access
		//At 
		/*
		** @brief Returns a reference to the element at specified location pos, with bounds checking.
		**If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
		** 
		** @param pos position of the element to return
		** 
		** @return Reference to the requested element.
		** 
		** @exception std::out_of_range if !(pos < size()).
		** 
		*/
		reference at( size_type pos ){
			std::ostringstream exception;

			exception << "vector::_M_range_check: __n (which is " << pos << ") >= this->size() (which is " << this->size() << ")";
			if (pos >= size())
				throw (std::out_of_range(exception.str()));
			iterator it = this->begin();
			for (size_type i = 0; i < pos ;i++, it++)
				;
			return (*it);
		}
		/*
		** @brief Returns a reference to the element at specified location pos, with bounds checking.
		**If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
		** 
		** @param pos position of the element to return
		** 
		** @return Reference to the requested element.
		** 
		** @exception std::out_of_range if !(pos < size()).
		** 
		*/
		const_reference at( size_type pos ) const{
			std::ostringstream exception;

			exception << "vector::_M_range_check: __n (which is " << pos << ") >= this->size() (which is " << this->size() << ")";
			if (pos >= size())
				throw (std::out_of_range(exception.str()));
			iterator it = this->begin();
			for (size_type i = 0; i < pos ;i++, it++)
				;
			return (*it);
		}

		// Operator []
		/*
		** @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
		** 
		** @param pos position of the element to return
		** 
		** @return Reference to the requested element.
		** 
		**
		** 
		*/
		reference operator[]( size_type pos ){
			iterator it = this->begin();
			for (size_type i = 0; i < pos ;i++, it++)
				;
			return (*it);
		}
		/*
		** @brief Returns a reference to the element at specified location pos. No bounds checking is performed.
		** 
		** @param pos position of the element to return
		** 
		** @return Reference to the requested element.
		** 
		**
		** 
		*/
		const_reference operator[](size_type pos) const{
			iterator it = this->begin();
			for (size_type i = 0; i < pos ;i++, it++)
				;
			return (*it);
		}

		// Front
		/*
		** @brief Returns a reference to the first element in the container.
		** Calling front on an empty container is undefined.
		** 
		** @param none
		** 
		** @return Reference to the first element
		** 
		**
		** 
		*/
		reference front(){
			return (*(this->begin()));
		}
		/*
		** @brief Returns a reference to the first element in the container.
		** Calling front on an empty container is undefined.
		** 
		** @param none
		** 
		** @return Reference to the first element
		** 
		**
		** 
		*/
		const_reference front() const{
			return (*(this->begin()));
		}

		// Back
		/*
		** @brief Returns a reference to the last element in the container.
		** Calling back on an empty container causes undefined behavior.
		** 
		** @param none
		** 
		** @return Reference to the last element
		** 
		**
		** 
		*/
		reference back(){
			iterator it = this->end();
			it--;
			return (*it);
		}
		/*
		** @brief Returns a reference to the last element in the container.
		** Calling back on an empty container causes undefined behavior.
		** 
		** @param none
		** 
		** @return Reference to the last element
		** 
		**
		** 
		*/
		const_reference back() const{
			iterator it = this->end();
			it--;
			return (*it);
		}

		// Data
		/*
		** @brief Returns pointer to the underlying array serving as element storage.
		** The pointer is such that range [data(); data() + size()) is always a valid range, even if the container is empty (data() is not dereferenceable in that case).
		** 
		** @param none
		** 
		** @return Pointer to the underlying element storage.
		** For non-empty containers, the returned pointer compares equal to the address of the first element.
		** 
		**
		** 
		*/
		T* data(){
			return (_start);
		}
		/*
		** @brief Returns pointer to the underlying array serving as element storage.
		** The pointer is such that range [data(); data() + size()) is always a valid range, even if the container is empty (data() is not dereferenceable in that case).
		** 
		** @param none
		** 
		** @return Pointer to the underlying element storage.
		** For non-empty containers, the returned pointer compares equal to the address of the first element.
		** 
		**
		** 
		*/
		const T* data() const{
			return (_start);
		}
	
	// Iterators
		// Begin
		/*
		** @brief Returns an iterator to the first element of the vector.
		** If the vector is empty, the returned iterator will be equal to end().
		** 
		** @param none
		** 
		** @return Iterator to the first element.
		** 
		**
		** 
		*/
		iterator begin(){
			return iterator(_start);
		}
		/*
		** @brief Returns an iterator to the first element of the vector.
		** If the vector is empty, the returned iterator will be equal to end().
		** 
		** @param none
		** 
		** @return Iterator to the first element.
		** 
		**
		** 
		*/
		const_iterator begin() const{
			return const_iterator(_start);
		}

		// End
		/*
		** @brief  Returns an iterator to the element following the last element of the vector.
		** This element acts as a placeholder; attempting to access it results in undefined behavior.
		** 
		** @param none
		** 
		** @return Iterator to the element following the last element.
		** 
		**
		** 
		*/
		iterator end(){
			return iterator(_start + this->size());
		}
		/*
		** @brief  Returns an iterator to the element following the last element of the vector.
		** This element acts as a placeholder; attempting to access it results in undefined behavior.
		** 
		** @param none
		** 
		** @return Iterator to the element following the last element.
		** 
		**
		** 
		*/
		const_iterator end() const{
			return const_iterator(_start + this->size());
		}

		// RBegin
		/*
		** @brief Returns a reverse iterator to the first element of the reversed vector.
		** It corresponds to the last element of the non-reversed vector. 
		** If the vector is empty, the returned iterator is equal to rend().
		** 
		** @param none
		** 
		** @return Reverse iterator to the first element.
		** 
		**
		** 
		*/
		reverse_iterator rbegin(){
			return (reverse_iterator(end()));
		}
		/*
		** @brief Returns a reverse iterator to the first element of the reversed vector.
		** It corresponds to the last element of the non-reversed vector. 
		** If the vector is empty, the returned iterator is equal to rend().
		** 
		** @param none
		** 
		** @return Reverse iterator to the first element.
		** 
		**
		** 
		*/
		const_reverse_iterator rbegin() const{
			return (reverse_iterator(end()));
		}

		// REnd
		/*
		** @brief Returns a reverse iterator to the element following the last element of the reversed vector.
		** It corresponds to the element preceding the first element of the non-reversed vector.
		** This element acts as a placeholder, attempting to access it results in undefined behavior.
		** 
		** @param none
		** 
		** @return Reverse iterator to the element following the last element.
		** 
		**
		** 
		*/
		reverse_iterator rend(){
			return (reverse_iterator((begin())));
		}
		/*
		** @brief Returns a reverse iterator to the element following the last element of the reversed vector.
		** It corresponds to the element preceding the first element of the non-reversed vector.
		** This element acts as a placeholder, attempting to access it results in undefined behavior.
		** 
		** @param none
		** 
		** @return Reverse iterator to the element following the last element.
		** 
		**
		** 
		*/
		const_reverse_iterator rend() const{
			return (reverse_iterator((begin())));
		}

	// Capacity
		// Empty
		/*
		** @brief Checks if the container has no elements, i.e. whether begin() == end().
		** 
		** @param none
		** 
		** @return true if the container is empty, false otherwise
		** 
		**
		** 
		*/
		bool empty() const{
			return (this->begin() == this->end() ? true : false);
		}

		// Size
		/*
		** @brief Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		** 
		** @param none
		** 
		** @return The number of elements in the container.
		** 
		**
		** 
		*/
		size_type size() const {
			return (_end -_start);
		}
		
		// Max size
		/*
		** @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e.
		** std::distance(begin(), end()) for the largest container.
		** 
		** @param none
		** 
		** @return Maximum number of elements.
		** 
		**
		** 
		*/
		size_type max_size() const{
			return (_alloc.max_size());
		}

		// Reserve
		/*
		** @brief Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation) to a value that's greater or equal to new_cap.
		** If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
		** reserve() does not change the size of the vector.
		** If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all references to the elements are invalidated. Otherwise, no iterators or references are invalidated.
		** 
		** @param new_cap new capacity of the vector, in number of elements
		** 
		** @return none
		** 
		** @exception std::length_error if new_cap > max_size().
		** @exception any exception thrown by Allocator::allocate() (typically std::bad_alloc).
		** If an exception is thrown, this function has no effect (strong exception guarantee).
		** 
		*/
		void reserve( size_type new_cap ){
			if (new_cap > this->max_size())
				return ;
			if (new_cap > this->capacity()){
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				int new_capacity = this->size() * 2 >= new_cap ? this->size() * 2 : new_cap;

				new_start = _alloc.allocate( new_capacity );
				new_end = new_start;
				new_end_capacity = new_start + new_capacity;
			
				for (iterator i = this->begin(); i != this->end(); i++){
					_alloc.construct(new_end, *i);
					new_end++;
				}

				for (size_type l = 0; l < this->size(); l++)
					_alloc.destroy(_start + l);
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}

		// capacity
		/*
		** @brief Returns the number of elements that the container has currently allocated space for.
		** 
		** @param none
		** 
		** @return capacity of the currently allocated storage.
		** 
		** 
		*/
		size_type capacity() const{
			return _end_capacity - _start;
		}

	//Modifiers 
		// Clear
		/*
		** @brief Erases all elements from the container. After this call, size() returns zero.
		Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated.
		Leaves the capacity() of the vector unchanged (note: the standard's restriction on the changes to capacity is in the specification of vector::reserve, see [1]).
		** 
		** @param none
		** 
		** @return none
		** 
		** 
		*/
		void clear(){
			for (size_type l = 0; l < this->size(); l++)
				_alloc.destroy(_start + l);
			_end = _start;
		}

		// Insert
		/*
		** @brief inserts value before pos
		** 
		** @param pos iterator before which the content will be inserted. pos may be the end() iterator
		** @param value element value to insert
		** 
		** @return Iterator pointing to the inserted value
		** 
		** 
		*/
		iterator insert(iterator pos, const T& value)// (1)
		{
			size_type pos_len = &(*pos) - _start;
			if (size_type(_end_capacity - _end) >= this->size() + 1)
			{
				for (size_type i = 0; i < pos_len; i++)
					_alloc.construct(_end - i, *(_end - i - 1));
				_end++;
				_alloc.construct(&(*pos), value);
			} else {
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				int new_capacity;
				if (this->size() * 2 < this->max_size())
					new_capacity = (this->size() * 2 > 0) ?  this->size() * 2 : 1 ; 
				else
					new_capacity = this->max_size();

				new_start = _alloc.allocate( new_capacity );
				new_end = new_start + this->size() + 1;
				new_end_capacity = new_start + new_capacity;
			
				for (size_type i = 0; i < pos_len && i <= this->size(); i++){
					if (i < this->size())
						_alloc.construct(new_start + i, *(_start + i));
					else
						_alloc.construct(new_start + i, T());					
				}
				if ( pos_len > this->size()){
					std::cout << "ta errado\n";
		
				} else {
					_alloc.construct(new_start + pos_len, value);
					for (size_type j = 0; j < this->size() - pos_len; j++)
						_alloc.construct(new_end - j - 1, *(_end - j - 1));
				}
				this->clear();
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
			return (iterator(_start + pos_len));
		}
		/*
		** @brief inserts count copies of the value before pos
		** 
		** @param pos iterator before which the content will be inserted. pos may be the end() iterator
		** @param count number of elements to insert
		** @param value element value to insert
		** 
		** @return Iterator pointing to the first element inserted, or pos if count==0.
		** 
		** 
		*/
		void insert(iterator pos, size_type count, const T& value){// (3)
			size_type pos_len = &(*pos) - _start;
			if (size_type(_end_capacity - _end) >= this->size() + count)
			{
				for (size_type j = 0; j < count; j++){
					for (size_type i = this->size(); i > pos_len; i--)
						_alloc.construct(_start + i, *(_start + i - 1));
					_end++;
					_alloc.construct(&(*pos), value);
				}
			} else {
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				int new_capacity;
				if (this->size() + count < this->max_size())
					new_capacity = this->size() + count; 
				else
					new_capacity = this->max_size() - 1;

				new_start = _alloc.allocate( new_capacity );
				new_end = new_start + this->size() + count;
				new_end_capacity = new_start + new_capacity;
			
				for (size_type i = 0; i < pos_len && i <= this->size(); i++){
					if (i < this->size())
						_alloc.construct(new_start + i, *(_start + i));
					else
						_alloc.construct(new_start + i, T());					
				}
				for (size_type j = 0; j < count; j++)
					_alloc.construct(new_start + pos_len + j, value);

				for (size_type j = 0; j < this->size() - pos_len; j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));
				this->clear();
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		} 

		/*
		** @brief inserts elements from range [first, last) before pos.
		** 
		** @param pos iterator before which the content will be inserted. pos may be the end() iterator
		** @param first, 
		** @param last the range of elements to insert, can't be iterators into container for which insert is called
		** 
		** @return Iterator pointing to the first element inserted, or pos if first==last.
		** 
		** 
		*/
		template <class InputIt> void insert( iterator pos, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last ){// (4)
			size_type	rangeSpace = std::abs(&(*last) - &(*first));
			size_type	pos_len = &(*pos) - _start;
			if (this->size() + rangeSpace <= this->capacity()){
				for(size_type i = 0; i < this->size() - (&(*pos) - _start); i++)
					_alloc.construct(_end - i + (rangeSpace - 1), *(_end - i - 1));
				_end += rangeSpace;
				for (; &(*first) != &(*last); first++, pos++)
					_alloc.construct(&(*pos), *first);
			} else {

				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();

				int new_capacity;
				if (this->size() + rangeSpace < this->max_size())
					new_capacity = this->size() + rangeSpace; 
				else
					new_capacity = this->max_size() - 1;

				new_start = _alloc.allocate( new_capacity );
				new_end = new_start + this->size() + rangeSpace;
				new_end_capacity = new_start + new_capacity;
			
				for (size_type i = 0; i < pos_len && i <= this->size(); i++){
					if (i < this->size())
						_alloc.construct(new_start + i, *(_start + i));
					else
						_alloc.construct(new_start + i, T());					
				}
				for (size_type j = 0; j < rangeSpace; j++){
					_alloc.construct(new_start + pos_len + j, *first);
					first++;
				}
				for (size_type j = 0; j < this->size() - pos_len; j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));
				this->clear();
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		} 

		// Erase
		/*
		** @brief  Removes the element at pos.
		** 
		** @param pos iterator to the element to remove
		** 
		** @return Iterator following the last removed element.
		** If pos refers to the last element, then the end() iterator is returned.
		** 
		** 
		*/
		iterator erase( iterator pos ){
			iterator ret = pos;
			ret++;
			size_type index = &(*pos) - _start;
			
			_alloc.destroy(this->_start + index);
			for ( ; index < this->size() - 1 ; index++)
				this->_alloc.construct(this->_start + index, *(this->_start + index + 1));
			_end--;
			return (ret);
		}
		/*
		** @brief  Removes the elements in the range [first, last).
		** 
		** @param first, 
		** @param last range of elements to remove
		** 
		** @return Iterator following the last removed element.
		** If pos refers to the last element, then the end() iterator is returned.
		** If last==end() prior to removal, then the updated end() iterator is returned.
		** If [first, last) is an empty range, then last is returned.
		** 
		** 
		*/
		iterator erase( iterator first, iterator last ){
			pointer p_first = &(*first);
			for (; &(*first) != &(*last); first++)
				_alloc.destroy(&(*first));
			for (int i = 0; i < _end - &(*last); i++){
				_alloc.construct(p_first + i, *(&(*last) + i));
				_alloc.destroy(&(*last) + i);
			}
			_end -= (&(*last) - p_first);
			return (iterator(p_first));
		}

		// Push Back
		/*
		** @brief  The new element is initialized as a copy of value.
		** 
		** @param value the value of the element to append
		** 
		** @return none
		** 
		** @exception If an exception is thrown (which can be due to Allocator::allocate() or element copy/move constructor/assignment), this function has no effect (strong exception guarantee).
		*/
		void push_back( const T& value ){
			this->reserve(this->size() + 1);
			this->_alloc.construct(_start + this->size(), value);
			this->_end++;
		}

		// Pop Back
		/*
		** @brief  Removes the last element of the container.
		** 
		** @param none
		** 
		** @return none
		** 
		** @exception Throws nothing.
		*/
		void pop_back(){
			if (this->size() > 0){
				this->_alloc.destroy(_start + this->size() - 1);
				this->_end--;
			}
		}

		// Resize
		/*
		** @brief  Resizes the container to contain count elements.
		** 
		** @param count	new size of the container
		** @param value	the value to initialize the new elements with
		** 
		** @return none
		** 
		** @exception If an exception is thrown, this function has no effect (strong exception guarantee).
		*/
		void resize(size_type count, T value = T()){
			if (count < this->size()){
				size_type old_size = this->size();
				for (size_type i = count; i < old_size; i++){
					this->_alloc.destroy(_start + i);
					_end--;
				}
			} else if (count > this->size()){
				if (count > this->capacity())
					this->reserve(count);
				for (size_type i = this->size(); i < count; i++){
					this->_alloc.construct(_end, value);
					_end++;
				}
			}			
		}

		// Swap
		/*
		** @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
		** 
		** @param other container to exchange the contents with
		** 
		** @return none
		** 
		*/
		void swap( vector& other ){
			allocator_type alloc_holder = other._alloc;
			pointer	start_holder = other._start;
			pointer	end_holder = other._end;
			pointer	end_cap_holder = other._end_capacity;

			other._alloc = this->_alloc;
			other._start = this->_start;
			other._end = this->_end;
			other._end_capacity = this->_end_capacity;

			this->_alloc = alloc_holder;
			this->_start = start_holder;
			this->_end = end_holder;
			this->_end_capacity = end_cap_holder;
		}

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _end;
		pointer _end_capacity;
		
	};
	// operators

	template< class T, class Alloc >bool operator== ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::iterator lIt = lhs.begin(); 
		typename ft::vector<T>::iterator rIt = rhs.begin();
		for (; lIt != lhs.end(); lIt++, rIt++){
			if (*lIt != *rIt || rIt == rhs.end())
				return false;
		}
		return true;
	}

	template< class T, class Alloc >bool operator!= ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template< class T, class Alloc >bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		typename ft::vector<T>::iterator lIt = lhs.begin(); 
		typename ft::vector<T>::iterator rIt = rhs.begin();
		for (; lIt != lhs.end(); lIt++, rIt++){
			if (*lIt > *rIt)
				return false;
			else if (*lIt < *rIt)
				return true;
		}
		if (lhs.size() >= rhs.size())
			return false;
		return false;
	}

	template< class T, class Alloc >bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		typename ft::vector<T>::iterator lIt = lhs.begin(); 
		typename ft::vector<T>::iterator rIt = rhs.begin();
		for (; lIt != lhs.end(); lIt++, rIt++){
			if (*lIt > *rIt)
				return false;
			else if (*lIt < *rIt)
				return true;
		}
		if (lhs.size() > rhs.size())
			return false;
		return true;
	}

	template< class T, class Alloc >bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		typename ft::vector<T>::iterator lIt = lhs.begin(); 
		typename ft::vector<T>::iterator rIt = rhs.begin();
		for (; lIt != lhs.end(); lIt++, rIt++){
			if (*lIt < *rIt)
				return false;
		}
		if (lhs.size() < rhs.size())
			return false;
		return true;
	}
	
	template< class T, class Alloc >bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		typename ft::vector<T>::iterator lIt = lhs.begin(); 
		typename ft::vector<T>::iterator rIt = rhs.begin();
		for (; lIt != lhs.end(); lIt++, rIt++){
			if (*lIt < *rIt)
				return false;
		}
		if (lhs.size() < rhs.size())
			return false;
		return true;
	}

	template< class T, class Alloc >void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ){
		lhs.swap(rhs);
	}
};

#endif // VECTOR_HPP