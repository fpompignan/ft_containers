#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "type_traits.hpp"


namespace ft
{

template <class iter>
class reverseIterator
{
public:
	typedef typename ft::iterator_traits<iter>::value_type			value_type;
	typedef typename ft::iterator_traits<iter>::pointer			pointer;
	typedef typename ft::iterator_traits<iter>::reference			reference;
	typedef typename ft::iterator_traits<iter>::difference_type		difference_type;
	typedef typename ft::iterator_traits<iter>::iterator_category		iterator_category;
	
	reverseIterator(){};
	reverseIterator(pointer ptr):_ptr(ptr){};
	reverseIterator(reverseIterator const & A){*this = A;}
	reverseIterator(random_access_iterator<pointer> const & A){_ptr=A.get_ptr();}
	virtual ~reverseIterator(){};

	reverseIterator& operator=(reverseIterator const & A)
	{
		this->_ptr = A._ptr;
		return (*this);
	}

	//BOOLEANS
	bool	operator==(reverseIterator const & A) const {return(this->_ptr == A._ptr);}
	bool	operator!=(reverseIterator const & A) const {return(this->_ptr != A._ptr);}
	bool	operator>=(reverseIterator const & A) const {return(this->_ptr >= A._ptr);}
	bool	operator<=(reverseIterator const & A) const {return(this->_ptr <= A._ptr);}
	bool	operator>(reverseIterator const & A) const {return(this->_ptr > A._ptr);}
	bool	operator<(reverseIterator const & A) const {return(this->_ptr < A._ptr);}

	//ARITHMETIC
	reverseIterator operator+(difference_type n) {return (reverseIterator(_ptr - n));} // a + n
	reverseIterator operator-(difference_type n) {return (reverseIterator(_ptr + n));} // a - n

	difference_type operator+(reverseIterator A) {return (_ptr - A._ptr);} // a + b
	difference_type operator-(reverseIterator A) {return (_ptr + A._ptr);} // a - b

	//INCREMENTERS
	reverseIterator operator++() {_ptr--; return(*this);}				//++a
	reverseIterator operator++(int) {_ptr--; return(reverseIterator(_ptr + 1));}	//a++
	reverseIterator operator--() {_ptr++; return(*this);}				//--a
	reverseIterator operator--(int) {_ptr++; return(reverseIterator(_ptr - 1));}	//a--

	//COMPOUND ASSIGNMENTS
	reverseIterator	operator+=(difference_type n) {_ptr-=n; return (*this);} //a+=n
	reverseIterator	operator-=(difference_type n) {_ptr+=n; return (*this);} //a-=n

	//deferencement et addressage
	reference	operator*() {return(*_ptr);}
	reference	operator[](difference_type n) {return (*(_ptr + n));}
	pointer		operator->() {return (_ptr);}



private:
	pointer  _ptr;


};
}
#endif
