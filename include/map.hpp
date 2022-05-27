#if !defined(MAP_HPP)
#define MAP_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <exception>
#include "BstUtils.hpp"
#include "functional.hpp"
#include "utility.hpp"
#include "biderectional_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;			
			typedef ft::pair<const Key, T>						value_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef	ft::bidirectional_iterator<Key, T>			iterator;
			typedef	const ft::bidirectional_iterator<Key, T>	const_iterator;
			typedef ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef const ft::reverse_iterator<iterator> 		const_reverse_iterator;

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
			~map(){
				this->clear();
			};

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
				if (!this->_node){
					this->_node = new ft::BstNode<Key, T>(key, this->_alloc);
				}
				return this->_node->insert(key);
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
				return(iterator(this->_node ? this->_node->getLowerNode(this->_node) : NULL, this->_node  ? this->_node->size : 0));
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
				return(iterator(this->_node ? this->_node->getLowerNode(this->_node) : NULL, this->_node ? this->_node->size : 0));
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
				return(iterator(this->_node ? this->_node->getHigherNode(this->_node ): NULL,this->_node ? this->_node->size : 0, true));
			}
		
			/*
			** @brief Returns an iterator to the element following the last element of the map. This element acts as a placeholder; attempting to access it results in undefined behavior.
			** 
			** @param none
			** 
			** @return Iterator to the element following the last element.
			*/
			const_iterator end() const {
				return(iterator(this->_node ? this->_node->getHigherNode(this->_node ): NULL, this->_node ? this->_node->size : 0, true));
			}

			// RBegin
			/*
			** @brief Returns a reverse iterator to the first element of the reversed map. It corresponds to the last element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
			** 
			** @param none
			** 
			** @return Reverse iterator to the first element.
			*/
			reverse_iterator rbegin(){
				if (this->empty())
					return this->rend();
				return reverse_iterator((this->end()));
			};
			/*
			** @brief Returns a reverse iterator to the first element of the reversed map. It corresponds to the last element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
			** 
			** @param none
			** 
			** @return Reverse iterator to the first element.
			*/
			const_reverse_iterator rbegin() const {
				if (this->empty())
					return this->rend();
				return const_reverse_iterator((this->end()));
			};

			// Rend
			/*
			** @brief Returns a reverse iterator to the element following the last element of the reversed map. It corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder, attempting to access it results in undefined behavior.
			** 
			** @param none
			** 
			** @return Reverse iterator to the element following the last element.
			*/
			reverse_iterator rend(){
				return reverse_iterator((this->begin()));
			};
			/*
			** @brief Returns a reverse iterator to the element following the last element of the reversed map. It corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder, attempting to access it results in undefined behavior.
			** 
			** @param none
			** 
			** @return Reverse iterator to the element following the last element.
			*/
			const_reverse_iterator rend() const{
				return const_reverse_iterator((this->begin()));
			};

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
				return this->_node->size;
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
				return this->_alloc.max_size();
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
			void clear(){
				this->erase(this->begin(), this->end());
			};

			// Erase
			/*
			** @brief Erases all elements from the container. After this call, size() returns zero.
			** 
			** @param none
			** 
			** @return none
			*/
			void erase(iterator pos){
				this->erase(pos->first);
			};
			
			/*
			** @brief  Removes the elements in the range [first; last), which must be a valid range in *this
			** 
			** @param first, last: range of elements to remove
			** 
			** @return none
			*/
			void erase( iterator first, iterator last ){
				iterator holder;
				for (; first != last;){
					holder = first;
					first++;
					this->erase(holder->first);			
				}
			};

			/*
			** @brief Removes the element (if one exists) with the key equivalent to key.
			** 
			** @param key key value of the elements to remove
			** 
			** @return Number of elements removed (0 or 1)
			*/
			size_type erase( const Key& key ){
				return (ft::removeNode(key, &this->_node)) ? 1 : 0;
			};

			// Swap
			/*
			** @brief Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
			** 
			** @param other container to exchange the contents with
			** 
			** @return none
			*/
			void swap( map& other ){
				ft::BstNode<Key, T> holder = this->_node;

				this->_node = other._node;

				other._node = holder;
			};

			// Insert 
			/*
			** @brief  Inserts value.
			** 
			** @param value	element value to insert
			** 
			** @return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			*/
			ft::pair<iterator, bool> insert( const value_type& value ){
				bool created = this->_node->insert(value);
				ft::BstNode<Key, T> *cNode = this->_node->find(value.first);
				return ft::pair<iterator, bool>(iterator(cNode->data->first, this->_node->size), created);
			};
			
			/*
			** @brief Inserts value in the position as close as possible, just prior(since C++11), to hint.
			** 
			** @param iterator, used as a suggestion as to where to start the search
			** @param value	element value to insert
			** 
			** @return Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			*/
			iterator insert( iterator hint, const value_type& value ){
				this->_node->find(hint->first)->insert(value);
				return iterator(this->_node->find(value->first), this->_node->size);
			};
			
			/*
			** @brief  Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted
			** 
			** @param first, last:	range of elements to insert
			** 
			** @return none
			*/
			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				for (; first != last; first++){
					this->_node->insert(first->first) = first->second;
				}				
			};


		// Lookup
			// Count 	
			/*
			** @brief  Returns the number of elements with key that compares equivalent to the specified argument, which is either 1 or 0 since this container does not allow duplicates.
			** 
			** @param key key value of the elements to count
			** 
			** @return Returns the number of elements with key key.
			*/
			size_type count( const Key& key ) const {
				return this->_node->find(key) ? 1 : 0;
			};

			// Find
			/*
			** @brief  Finds an element with key equivalent to key.
			** 
			** @param key key value of the element to search for
			** 
			** @return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
			*/
			iterator find(const Key& key){
				if (!this->_node)
					return this->end();
				ft::BstNode<Key, T> *found = this->_node->find(key);
				if (!found)
					return this->end();
				return iterator(found->first, this->_node->size);
			};
			
			/*
			** @brief  Finds an element with key equivalent to key.
			** 
			** @param key key value of the element to search for
			** 
			** @return Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
			*/
			const_iterator find(const Key& key) const {
				if (!this->_node)
					return this->end();
				ft::BstNode<Key, T> *found = this->_node->find(key);
				if (!found)
					return this->end();
				return const_iterator(found->first, this->_node->size);
			};

			// Upper Bound
			/*
			** @brief  Returns an iterator pointing to the first element that is greater than key.
			** 
			** @param key key value to compare the elements to
			** 
			** @return Iterator pointing to the first element that is greater than key. If no such element is found, past-the-end (see end()) iterator is returned.
			*/
			iterator upper_bound( const Key& key ){
				iterator bgn = this->begin();
				iterator end = this->end();

				for (; bgn != end; bgn++){
					if (_comp(key, bgn->first))
						break ;
				}
				return bgn;
			};

			/*
			** @brief  Returns an iterator pointing to the first element that is greater than key.
			** 
			** @param key key value to compare the elements to
			** 
			** @return Iterator pointing to the first element that is greater than key. If no such element is found, past-the-end (see end()) iterator is returned.
			*/
			const_iterator upper_bound( const Key& key ) const {
				const_iterator bgn = this->begin();
				const_iterator end = this->end();

				for (; bgn != end; bgn++){
					if (_comp(key, bgn->first))
						break ;
				}
				return bgn;
			};
			
			// Lower Bounds
			/*
			** @brief  Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
			** 
			** @param key key value to compare the elements to
			** 
			** @return Iterator pointing to the first element that is not less than key. If no such element is found, a past-the-end iterator (see end()) is returned.
			*/
			iterator lower_bound( const Key& key ){
				iterator bgn = this->begin();
				iterator end = this->end();

				for (; bgn != end; bgn++){
					if (!_comp(bgn->first, key))
						break ;
				}
				return bgn;
			};
			
			/*
			** @brief  Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
			** 
			** @param key key value to compare the elements to
			** 
			** @return Iterator pointing to the first element that is not less than key. If no such element is found, a past-the-end iterator (see end()) is returned.
			*/
				const_iterator lower_bound( const Key& key ) const{
				const_iterator bgn = this->begin();
				const_iterator end = this->end();

				for (; bgn != end; bgn++){
					if (!_comp(bgn->first, key))
						break ;
				}
				return bgn;
			};

			// Equal Range
			/*
			** @brief  Returns a range containing all elements with the given key in the container.
			** The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key.
			** Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
			** 
			** @param key key value to compare the elements to
			** 
			** @return std::pair containing a pair of iterators defining the wanted range: the first pointing to the first element that is not less than key and the second pointing to the first element greater than key.
			*/
			ft::pair<iterator,iterator> equal_range(const Key& key){
				return ft::make_pair(this->lower_bound(key), this->upper_bound(key));
			};
		
			/*
			** @brief  Returns a range containing all elements with the given key in the container.
			** The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key.
			** Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
			** 
			** @param key key value to compare the elements to
			** 
			** @return std::pair containing a pair of iterators defining the wanted range: the first pointing to the first element that is not less than key and the second pointing to the first element greater than key.
			*/
			ft::pair<const_iterator,const_iterator> equal_range(const Key& key) const {
				return ft::make_pair(this->lower_bound(key), this->upper_bound(key));
			};

		// Observers
			// Key Comp
			/*
			** @brief Return a copy of the key comparison object.
			**
			** @param the key comparison object.
			*/
			key_compare key_comp() const {
				return (key_compare());
			};

			// Value Comp
			/*
			** @brief Return a copy of the value comparison object.
			**
			** @param the value comparison object.
			*/
			value_compare value_comp() const {
				return (value_compare(key_compare()));
			};

		protected:
			key_compare _comp;
			allocator_type _alloc;
			ft::BstNode<Key, T> *_node;
	};
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           		ft::map<Key,T,Compare,Alloc>& rhs ){
					   lhs.swap(rhs);
				   };
	

	
} // namespace ft

#endif // MAP_HPP
