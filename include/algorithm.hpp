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

	}

	/*
	** @brief Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise.
	** 
	** @param first1, last1	:	the first range of elements to examine
	** @param first2, last2	:	the second range of elements to examine
	** @param p		binary predicate which returns ​true if the elements should be treated as equal.
	** 
	** @return true or false
	** 
	*/
	template< class InputIt1, class InputIt2, class BinaryPredicate >bool equal( InputIt1 first1, 
	InputIt1 last1, InputIt2 first2, BinaryPredicate p ){

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

	}
	/*
	** doc https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare 
	** @brief Elements are compared using the given binary comparison function comp.
	** 
	** @param first1, last1	:	the first range of elements to examine
	** @param first2, last2	:	the second range of elements to examine
	** @param 	comparison function object (i.e. an object that satisfies the requirements of Compare) which returns ​true if the first argument is less than the second.
	** 
	** @return true or false
	** 
	*/
	template< class InputIt1, class InputIt2, class Compare >bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2, Compare comp ){

	}


} // namespace ft


#endif // ALGORITHM_HPP
