#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{

template<class iter>
struct iterator_traits
{
	typedef typename iter::difference_type		difference_type;
	typedef typename iter::value_type		value_type;
	typedef typename iter::pointer			pointer;
	typedef typename iter::reference		reference;
	typedef typename iter::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t				difference_type;
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t				difference_type;
	typedef T					value_type;
	typedef const T*				pointer;
	typedef const T&				reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <class T>
struct map_iterator_traits
{
	typedef std::ptrdiff_t				difference_type;
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <class T>
struct map_iterator_traits<const T>
{
	typedef std::ptrdiff_t				difference_type;
	typedef T					value_type;
	typedef const T*				pointer;
	typedef const T&				reference;
	typedef std::random_access_iterator_tag		iterator_category;
};





}

#endif
