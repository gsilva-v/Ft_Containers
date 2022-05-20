#if !defined(UTILITY_HPP)
#define UTILITY_HPP

namespace ft
{
	template<class T1,class T2> struct pair
	{	
			typedef T1 first_type;
			typedef T2 second_type;
			first_type first;
			second_type second;
		// Constructors
			/*
			** @brief Default constructor. Value-initializes both elements of the pair, first and second.
			** 
			** 
			*/
			pair() : first(), second(){};//(1)
			
			/*
			** @brief Initializes first with x and second with y.
			** 
			** 
			*/
			pair( const T1& x, const T2& y ){this->first = x; this->second = y;};//(2)

			/*
			** @brief Initializes first with p.first and second with p.second.
			** 
			** 
			*/
			template< class U1, class U2 >
				pair( const pair<U1, U2>& p ){//(5)
					this->first = p.first;
					this->second = p.second;
				};
		
		// Operator=
			/*
			** @brief  Copy assignment operator. Replaces the contents with a copy of the contents of other.
			** 
			** 
			*/
			pair& operator=( const pair& other ){
				if (this != &other){
					this->second = other.second; 
				}
				return *this;
			}

	};

	template< class T1, class T2 >ft::pair<T1,T2> make_pair( T1 t, T2 u ){
		return (ft::pair<T1, T2>(t, u));
	};

	template< class T1, class T2 >bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		return false;
	};

	template< class T1, class T2 >bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(lhs == rhs));
	};

	template< class T1, class T2 >bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		if (lhs.first < rhs.first )
			return true;
		else if (lhs.first == rhs.first && lhs.second < rhs.second)
			return true;
		return false;
	};
	
	template< class T1, class T2 >bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return  !(rhs < lhs);
	};

	template< class T1, class T2 >bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return rhs < lhs;
	};

	template< class T1, class T2 >bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return !(lhs < rhs);
	};

}

#endif // UTILITY_HPP
