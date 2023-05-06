# ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "include/type_traits.hpp"

namespace ft
{

// T est un pointeur sur value_type;
template<class T>
class random_access_iterator
{
public:
	typedef typename ft::iterator_traits<T>::value_type		value_type;
	typedef typename ft::iterator_traits<T>::pointer		pointer;
	typedef typename ft::iterator_traits<T>::reference		reference;
	typedef typename ft::iterator_traits<T>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

//CONSTRUCTORS
	random_access_iterator(void):_ptr(0){}
	random_access_iterator(pointer ptr):_ptr(ptr){}
	random_access_iterator(random_access_iterator const & A):_ptr(A._ptr){}
	~random_access_iterator(){}		

//ASSIGNMENT
	random_access_iterator	operator=(const random_access_iterator & A){_ptr = A._ptr; return(*this);}

//ACCESSEURS
	T	get_ptr() const {return(_ptr);}	

//BOOLEANS
	bool	operator==(random_access_iterator const & A) const {return(this->_ptr == A._ptr);}
	bool	operator!=(random_access_iterator const & A) const {return(this->_ptr != A._ptr);}
	bool	operator>=(random_access_iterator const & A) const {return(this->_ptr >= A._ptr);}
	bool	operator<=(random_access_iterator const & A) const {return(this->_ptr <= A._ptr);}
	bool	operator>(random_access_iterator const & A) const {return(this->_ptr > A._ptr);}
	bool	operator<(random_access_iterator const & A) const {return(this->_ptr < A._ptr);}


//ARITHMETIC
	random_access_iterator operator+(difference_type n) {return (random_access_iterator(_ptr + n));} // a + n
	random_access_iterator operator-(difference_type n) {return (random_access_iterator(_ptr - n));} // a - n

	difference_type operator+(random_access_iterator A) {return (_ptr + A._ptr);} // a + b
	difference_type operator-(random_access_iterator A) {return (_ptr - A._ptr);} // a - b

	//INCREMENTERS
	random_access_iterator operator++() {_ptr++; return(*this);}				//++a
	random_access_iterator operator++(int) {_ptr++; return(random_access_iterator(_ptr - 1));}	//a++
	random_access_iterator operator--() {_ptr--; return(*this);}				//--a
	random_access_iterator operator--(int) {_ptr--; return(random_access_iterator(_ptr + 1));}	//a--

	//COMPOUND ASSIGNMENTS
	random_access_iterator	operator+=(difference_type n) {_ptr+=n; return (*this);} //a+=n
	random_access_iterator	operator-=(difference_type n) {_ptr-=n; return (*this);} //a-=n

	//deferencement et addressage
	reference	operator*() {return(*_ptr);}
	reference	operator[](difference_type n) {return (*(_ptr + n));}
	pointer		operator->() {return (_ptr);}




private:
	T	_ptr;

};
}
#endif
