#if !defined(TYPE_TRAITS_HPP)
#define TYPE_TRAITS_HPP

namespace ft {
template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> {
	typedef T type;
};


template <bool is_integral, typename T>
struct is_integral_res{
    typedef T type;
    static const bool value = is_integral;
};

template <class T> struct is_integral : public is_integral_res<false, T>{};

template<> struct is_integral<bool> : public is_integral_res<true, bool> {};
template<> struct is_integral<char> : public is_integral_res<true, char> {};
template<> struct is_integral<wchar_t> : public is_integral_res<true, wchar_t> {};
template<> struct is_integral<signed char> : public is_integral_res<true, signed char> {};
template<> struct is_integral<short int> : public is_integral_res<true, short int> {};
template<> struct is_integral<int> : public is_integral_res<true, int> {};
template<> struct is_integral<long int> : public is_integral_res<true, long int> {};
template<> struct is_integral<long long int> : public is_integral_res<true, long long int> {};
template<> struct is_integral<unsigned char> : public is_integral_res<true, unsigned char> {};
template<> struct is_integral<unsigned short int> : public is_integral_res<true, unsigned short int> {};
template<> struct is_integral<unsigned int> : public is_integral_res<true, unsigned int> {};
template<> struct is_integral<unsigned long int> : public is_integral_res<true, unsigned long int> {};
template<> struct is_integral<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

};


#endif // TYPE_TRAITS_HPP
