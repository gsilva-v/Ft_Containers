#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <exception>
#include "BstAlgorithm.hpp"
#include "functional.hpp"
#include "utility.hpp"

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
			map():_alloc(){};
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
			: _comp(comp), _alloc(alloc) 
			{

			};

			// template< class InputIt >
			// 	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			// Operator=
			map& operator=( const map& other ){
				if (this != &other){
					this->_alloc = other._alloc;
					this->_comp = other._comp;
				}
				return *this;
			};
			// Get alocator
			allocator_type get_allocator() const{
				return (this->_alloc);
			};
			// Destructor
			~map(){};

			//Operator[] 
			T& operator[](const Key& key){
				value_type *new_pair = this->_alloc.allocate(1);
				value_type *pair_found;
				
				pair_found = this->tree.insert(new_pair);

				if (pair_found == new_pair){
					this->_alloc.construct(new_pair);
					return new_pair->second;
				}
				this->_alloc.deallocate(new_pair, 1);
				return pair_found->second;
			};


		protected:
			key_compare _comp;
			allocator_type _alloc;
			ft::RedBlackTree<value_type *> tree;
	};
	
} // namespace ft

#endif // MAP_HPP
