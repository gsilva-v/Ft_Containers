#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include <iostream>

namespace ft
{
	template <class T,class Allocator = std::allocator<T>> class vector
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
		
	// Member functions
	// Contructors (docs: https://en.cppreference.com/w/cpp/container/vector/vector)

		vector(){}//until C++17 (1)
		
		explicit vector(const Allocator& alloc = Allocator())//until C++17 (2)
		: _alloc(alloc), _start(nullptr), _index(nullptr), _capacity(nullptr){}
		
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())//until C++11 (3)
		: _alloc(alloc), _start(nullptr), _index(nullptr), _capacity(nullptr){
			_start = _alloc.allocate(count);
			_capacity = _start + count;
			_index = _start;
			while (count--){
				_alloc.construct(_index);
				_index++;
			}
		}

		template <class InputIt> vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()){}//until C++20 (5)
		
		vector(const vector& other)//until C++20 (6)
		: _alloc(other.alloc), _start(nullptr), _index(nullptr), _capacity(nullptr){
			this->insert(this->begin(), other->begin(), other->end())
		}
		
		// Destructor
		~vector(){
			this->clear();
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
		vector	&operator=(vector const &other);

		/*
		** @brief Replaces the contents with count copies of value value.
		** 
		** @param count	the new size of the container
		** @param value	the value to initialize elements of the container with
		** 
		** 
		*/
		void assign( size_type count, const T& value );

		/*
		** @brief Replaces the contents with copies of those in the range [first, last). 
			The behavior is undefined if either argument is an iterator into *this..
		** 
		** @param first
		** @param last  the range to copy the elements from
		** 
		** 
		*/
		template <class InputIt> void assign(InputIt first, InputIt last);

		// Getter
		/*
		** @brief Returns the allocator associated with the container.
		** 
		** @param none
		** 
		** @return The associated allocator.
		*/
		allocator_type get_allocator() const;

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
		reference at( size_type pos );
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
		const_reference at( size_type pos ) const;

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
		reference operator[]( size_type pos );
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
		const_reference operator[](size_type pos) const;

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
		reference front();
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
		const_reference front() const;

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
		reference back();
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
		const_reference back() const;

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
		T* data();
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
		const T* data() const;
	
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
		// iterator begin();
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
		// const_iterator begin() const;

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
		// iterator end();
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
		// const_iterator end() const;

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
		// reverse_iterator rbegin();
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
		// const_reverse_iterator rbegin() const;

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
		// reverse_iterator rend();
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
		// const_reverse_iterator rend() const;

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
		bool empty() const;

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
		size_type size() const;
		
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
		size_type max_size() const;

		// Reserve
		/*
		** @brief Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation) to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
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
		void reserve( size_type new_cap );

		// Capacity
		/*
		** @brief Returns the number of elements that the container has currently allocated space for.
		** 
		** @param none
		** 
		** @return Capacity of the currently allocated storage.
		** 
		** 
		*/
		size_type capacity() const;

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
		void clear();

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
		// iterator insert( iterator pos, const T& value );// (1)
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
		// void insert( iterator pos, size_type count, const T& value ); // (3)
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
		// template <class InputIt> void insert( iterator pos, InputIt first, InputIt last ); // (4)

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
		// iterator erase( iterator pos );
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
		// iterator erase( iterator first, iterator last );


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
		void push_back( const T& value );

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
		void pop_back();

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
		void resize( size_type count, T value = T() );

		// Swap
		/*
		** @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
		** 
		** @param other container to exchange the contents with
		** 
		** @return none
		** 
		*/
		void swap( vector& other );

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _index;
		pointer _capacity;
		
	// operators
	};
	

}


#endif // VECTOR_HPP