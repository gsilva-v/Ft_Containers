#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <exception>
#include "BstAlgorithm.hpp"
#include "functional.hpp"
#include "utility.hpp"
#include "biderectional_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
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
			typedef	ft::bidirectional_iterator<Key, T> iterator;
			typedef	const ft::bidirectional_iterator<Key, T> const_iterator;

			class value_compare{
				protected:
					Compare comp;
					value_compare( Compare c ){this->comp = c;};
				public:
					typedef bool result_type;
					typedef T first_argument_type;
					typedef T second_argument_type;
					
					/*
					** @brief  Compares lhs.first and rhs.first by calling the stored comparator.
					** 
					** @param lhs, rhs	-	values to compare
					** 
					** @return comp(lhs.first, rhs.first)
					*/
					bool operator()( const value_type& lhs, const value_type& rhs ) const{
						return comp(lhs.first, rhs.first);
					};		
			};

			// Constructors
			map():_alloc(), _node(){};
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
			: _comp(comp), _alloc(alloc), _node()
			{

			};

			// template< class InputIt >
			// 	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			// Destructor
			~map(){};

			// Operator=
			map& operator=( const map& other ){
				if (this != &other){
					this->_alloc = other._alloc;
					this->_comp = other._comp;
				}
				return *this;
			};
			// Get alocator
			/*
			** @brief Returns the allocator associated with the container.
			** 
			** @param none
			** 
			** @return The associated allocator.
			*/
			allocator_type get_allocator() const{
				return (this->_alloc);
			};
		// Element access
		// AT nao tem no C++98 https://en.cppreference.com/w/cpp/container/map/at

			//Operator[] 
			/*
			** @brief Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
			** 
			** @param key the key of the element to find
			** 
			** @return Reference to the mapped value of the new element if no element with key key existed. Otherwise a reference to the mapped value of the existing element whose key is equivalent to key.
			*/
			T& operator[](const Key& key){
				return this->_node.insert(key);
			};
			
		//Iterators
			// Begin  
			/*
			** @brief Returns an iterator to the first element of the map. If the map is empty, the returned iterator will be equal to end().
			** 
			** @param none
			** 
			** @return Iterator to the first element.
			*/
			iterator begin(){
				return(iterator(this->_node.getLowerNode(&this->_node), this->_node.size));
			}
		
			// Const Begin
			/*
			** @brief Returns an iterator to the first element of the map. If the map is empty, the returned iterator will be equal to end().
			** 
			** @param none
			** 
			** @return Iterator to the first element.
			*/
			const_iterator begin() const {
				return(iterator(this->_node.getLowerNode(&this->_node), this->_node.size));
			}

			// End
			/*
			** @brief Returns an iterator to the element following the last element of the map. This element acts as a placeholder; attempting to access it results in undefined behavior.
			** 
			** @param none
			** 
			** @return Iterator to the element following the last element.
			*/
			iterator end(){
				return(iterator(this->_node.getHigherNode(&this->_node), this->_node.size, true));
			}
		
			/*
			** @brief Returns an iterator to the element following the last element of the map. This element acts as a placeholder; attempting to access it results in undefined behavior.
			** 
			** @param none
			** 
			** @return Iterator to the element following the last element.
			*/
			const_iterator end() const {
				return(iterator(this->_node.getHigherNode(&this->_node), this->_node.size, true));
			}

			// RBegin

			// Rend

		// Capacity
			// Empty
			/*
			** @brief Checks if the container has no elements, i.e. whether begin() == end().
			** 
			** @param none
			** 
			** @return true if the container is empty, false otherwise
			*/
			bool empty() const{
				return this->begin() == this->end();
			};

			// Size
			/*
			** @brief Returns the number of elements in the container, i.e. std::distance(begin(), end()).
			** 
			** @param none
			** 
			** @return The number of elements in the container.
			*/
			size_type size() const {
				return this->_node.size;
			};

			// Max Size
			/*
			** @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
			** 
			** @param none
			** 
			** @return Maximum number of elements.
			*/
			size_type max_size() const {
				return this->_node.maxSize();
			};

		// Modifiers
			// Clear
			/*
			** @brief Erases all elements from the container. After this call, size() returns zero.
			** 
			** @param none
			** 
			** @return none
			*/
			void clear(){};

			// Erase
			/*
			** @brief Erases all elements from the container. After this call, size() returns zero.
			** 
			** @param none
			** 
			** @return none
			*/
			void erase( iterator pos ){};


			// Swap
			/*
			** @brief Erases all elements from the container. After this call, size() returns zero.
			** 
			** @param none
			** 
			** @return none
			*/
			void swap( map& other ){
				map
			};

		protected:
			key_compare _comp;
			allocator_type _alloc;
			ft::BstNode<Key, T> _node;
	};
	
} // namespace ft

#endif // MAP_HPP
