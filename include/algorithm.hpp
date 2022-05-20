#if !defined(ALGORITHM_HPP)
#define ALGORITHM_HPP

namespace ft
{
	/*
	** @brief Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.
	** 
	** @param first1, last1	:	the first range of elements to examine
	** @param first2, last2	:	the second range of elements to examine
	** 
	** @return true or false
	** 
	*/
	template< class InputIt1, class InputIt2 >bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
		for (; first1 != last1; first1++, first2++){
			if (*first1 != *first2  || first2 == last2)
				return false;
		}
		return first2 != last2;
	}

	/*
	** @brief Elements are compared using operator<.
	** 
	** @param first1, last1	:	the first range of elements to examine
	** @param first2, last2	:	the second range of elements to examine
	** 
	** @return true or false
	** 
	*/
	template< class InputIt1, class InputIt2 >bool lexicographical_compare( InputIt1 first1, 
	InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
		for (; first1 != last1; first1++, first2++){
			if (*first1 > *first2  || first2 == last2)
				return false;
			else if (*first1 < *first2 )
				return true;
		}
		return first2 != last2;
	}

} // namespace ft

#endif // ALGORITHM_HPP
