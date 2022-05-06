#if !defined(REVERSE_ITERATOR_HPP)
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iter> class reverse_iterator
	{
		public:
			
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;		
			typedef typename ft::iterator_traits<Iter>::reference			reference;		

			reverse_iterator(){}

			explicit reverse_iterator( iterator_type x ) :current(x){}
			
			template< class U >reverse_iterator( const reverse_iterator<U>& other ){}
			
			/*
			** @brief The underlying iterator is assigned the value of the underlying iterator of other, i.e. other.base().
			** 
			** @param other	-	iterator adaptor to assign
			** 
			** @return *this
			*/
			template< class U >reverse_iterator& operator=( const reverse_iterator<U>& other ){
				if (this->current != other.base())
					this->current = other.base();
				return (*this);
			}

			/*
			** @brief Returns the underlying base iterator. That is ft::reverse_iterator(it).base() == it.
			** 
			**
			** 
			** @return The underlying iterator.
			*/
			iterator_type base() const{
				return (this->current);
			}

			reference operator*() const {
				return *current;
			}

			pointer operator->() {
				return current;
			}

			/*
			** @brief Returns a reference to the element at specified relative location.
			** 
			** @param n	-	position relative to current location.
			** 
			** @return A reference to the element at relative location, that is, base()[-n-1]..
			*/
			// operator[]( difference_type n ) const{}


			reverse_iterator& operator++() {
				current++;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			reverse_iterator& operator--() {
				current--;
				return *this;
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}

			reverse_iterator operator+( difference_type n ) const{}

			reverse_iterator operator-( difference_type n ) const{}
			
			reverse_iterator& operator+=( difference_type n ){}

			reverse_iterator& operator-=( difference_type n ){}


		protected:
			iterator_type current;
	};
	
	/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() == rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
	// 	const ft::reverse_iterator<Iterator2>& rhs ){}

	
	/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() != rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
	// 	const ft::reverse_iterator<Iterator2>& rhs ){}

/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() < rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
    //     const ft::reverse_iterator<Iterator2>& rhs ){}

/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() <= rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
    //     const ft::reverse_iterator<Iterator2>& rhs ){}

/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() > rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
    //     const ft::reverse_iterator<Iterator2>& rhs ){}


/*
	** @brief Compares the underlying iterators. Inverse comparisons are applied in order to take into account that the iterator order is reversed.
	** 
	** @param lhs, rhs	:	iterator adaptors to compare
	** 
	** @return lhs.base() >= rhs.base()
	*/
	// template< class Iterator1, class Iterator2 >bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
    //     const ft::reverse_iterator<Iterator2>& rhs ){}


/*
	** @brief Returns the iterator it incremented by n.
	** 
	** @param n	the number of positions to increment the iterator
	** @param it the iterator adaptor to increment
	** 
	** @return The incremented iterator, that is reverse_iterator<Iter>(it.base() - n)
	*/
	// template< class Iter >reverse_iterator<Iter>operator+( typename reverse_iterator<Iter>::difference_type n,
    //     const reverse_iterator<Iter>& it ){}


	/*
	** @brief Returns the distance between two iterator adaptors.
	** 
	** @param lhs, rhs:	iterator adaptors to compute the difference of
	** 
	** @return rhs.base() - lhs.base()
	*/
	// template< class Iterator >typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
    //     const reverse_iterator<Iterator>& rhs ){}

} // namespace ft


#endif // REVERSE_ITERATOR_HPP
