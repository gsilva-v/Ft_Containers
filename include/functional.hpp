#if !defined(FUNCTIONAL_HPP)
#define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result> struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template< class T > struct less : public ft::binary_function<T, T, bool>
	{
	
		/*
		** @brief Checks whether lhs is less than rhs.
		** 
		** @param (lhs rhs)	: values to compare
		** 
		** @return For T which is not a pointer type, true if lhs < rhs, false otherwise.
		** 
		** 
		*/
		bool operator()( const T& lhs, const T& rhs ) const {
			return lhs < rhs;
		};
	};
} // namespace ft

#endif // FUNCTIONAL_HPP
