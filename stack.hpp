#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"


namespace	ft
{


template < typename T, class Container = ft::vector<T> >
class stack
{
public:

//------------Member types-----------------------------

	typedef Container			container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

//-----------Constructor-----------------------

	explicit stack( const container_type & cont = container_type()){_c = cont;}

	stack(const stack & A){*this = A;}

	~stack(){}

	stack &	operator=(const stack & A)
	{
		_c = A._c;
		return (*this);
	}

//-------------------Capacity------------------------------

	bool	empty() const {return (_c.empty());}

	size_type	size() const {return (_c.size());}

	
//-------------------Element access----------------------

	reference		top(){ return (_c.back());}
	const_reference		top() const { return (_c.back());}


//----------------Modifiers-------------------------------

	void	push(const value_type & value)
	{
		_c.push_back(value);
	}

	void	pop() { _c.pop_back();}

//-----------------------Friend Members Functions------------------------

friend bool	operator==(const stack & A, const stack & B)
{
	return (A._c == B._c);
}

friend bool	operator!=(const stack & A, const stack & B)
{
	return (A._c != B._c);
}

friend bool	operator<(const stack & A, const stack & B)
{
	return (A._c < B._c);
}

friend bool	operator<=(const stack & A, const stack & B)
{
	return (A._c <= B._c);
}

friend bool	operator>(const stack & A, const stack & B)
{
	return (A._c > B._c);
}

friend bool	operator>=(const stack & A, const stack & B)
{
	return (A._c >= B._c);
}



private:

	container_type		_c;

};



}
#endif
