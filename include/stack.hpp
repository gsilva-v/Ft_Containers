#if !defined(STACK_HPP)
#define STACK_HPP

#include "vector.hpp"
namespace ft
{
	template< class T, class Container = ft::vector<T> > 
	class stack{
		public: 
			typedef	T									value_type;
			typedef Container							container_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference const_reference;

		protected:
			Container c;

		public:
		// Constructors
			/*
			** @brief Copy-constructs the underlying container c with the contents of cont. 
			** 
			** @param cont container to be used as source to initialize the underlying container
			** 
			**
			** 
			*/
			explicit stack( const Container& cont = Container() ){
				this->c = cont;
			};

			/*
			** @brief Copy constructor. The adaptor is copy-constructed with the contents of other.c. 
			** 
			** @param other	another container adaptor to be used as source to initialize the underlying container
			** 
			**
			** 
			*/
			stack( const stack& other ){
				this->c = other.c;
			};
			
			~stack(){};

			/*
			** @brief Copy assignment operator. Replaces the contents with a copy of the contents of other. Effectively calls c = other.c;
			** 
			** @param other	another container adaptor to be used as source
			** 
			**
			** 
			*/
			stack& operator=( const stack& other ){
				this->c = other.c;
				return *this;
			};
			
			/*
			** @brief Returns reference to the top element in the stack. This is the most recently pushed element. This element will be removed on a call to pop(). Effectively calls c.back().
			** 
			** @param none
			** 
			** @return Reference to the last element
			** 
			*/
			reference top(){
				return c.back();
			};

			const_reference top() const{
				return c.back();
			};
			
			/*
			** @brief Checks if the underlying container has no elements, i.e. whether c.empty().
			** 
			** @param none
			** 
			** @return true if the underlying container is empty, false otherwise
			** 
			*/
			bool empty() const{
				return c.empty();
			};

			/*
			** @brief Returns the number of elements in the underlying container, that is, c.size().
			** 
			** @param none
			** 
			** @return The number of elements in the container.
			** 
			*/
			size_type size() const{
				return c.size();
			};

			/*
			** @brief Pushes the given element value to the top of the stack. Effectively calls c.push_back(value)
			** 
			** @param value	the value of the element to push
			** 
			** @return none.
			** 
			*/
			void push( const value_type& value ){
				c.push_back(value);
			};

			/*
			** @brief Removes the top element from the stack. Effectively calls c.pop_back()
			** 
			** 
			** 
			** @return none.
			** 
			*/
			void pop(){
				c.pop_back();
			};
	
	};

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c == rhs.c;
	};

	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c != rhs.c;
	};

	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c < rhs.c;
	};

	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c <= rhs.c;
	};

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c > rhs.c;
	};

	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
		return lhs.c >= rhs.c;
	};
} // namespace ft

#endif // STACK_HPP
