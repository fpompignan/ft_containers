#ifndef UTILS_HPP
#define UTILS_HPP



namespace ft
{


//   ------------IS_INTEGRAL-----------------------

template <bool B>
struct bool_wrapper
{
	static const bool value = B;
};

// integral types : bool, char, char_16t, char32_t, wchar_t, short, int, long, long long

template <class T>
struct is_integral: bool_wrapper<false>{};

template<>
struct is_integral<bool>: bool_wrapper<true>{};

template<>
struct is_integral<char>: bool_wrapper<true>{};

template<>
struct is_integral<char16_t>: bool_wrapper<true>{};

template<>
struct is_integral<char32_t>: bool_wrapper<true>{};

template<>
struct is_integral<wchar_t>: bool_wrapper<true>{};

template<>
struct is_integral<short>: bool_wrapper<true>{};

template<>
struct is_integral<int>: bool_wrapper<true>{};

template<>
struct is_integral<long>: bool_wrapper<true>{};

template<>
struct is_integral<long long>: bool_wrapper<true>{};



//-------------------ENABLE_IF-----------------------

template<bool B, class T =void>
struct enable_if {};

template<class T>
struct enable_if <true, T>{typedef T type;};

//-------------EQUAL------------------------------
// Compares the elements in the range (first1, last1) with those in the range beginning at first2, and returns true if all
// of the elements in both ranges match

template<class InputIterator1, class InputIterator2>
bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

//-------------------LEXICOGRAPHICAL----------------------------
// Returns true if the range (first1, last1) compares lexicographically less than the range (first2, last2)
// A lexicographical comparison is the kind of comparison generally used to sort words alhabetically in
// dictionaries ; it involves comparing sequentially the elements that have the same position in both ranges
// against each other until one element is not equivalent ro the other
// The result of comparing these first non-matching elements is the result of lexicographical comparison
// If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one

template <class InputIterator1, class InputIterator2>
bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		first1++;
		first2++;
	}
	return (first2 != last2);
}


}






























#endif
