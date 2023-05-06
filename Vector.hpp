#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "include/random_access_iterator.hpp"
#include "include/reverse_iterator.hpp"
#include "include/utils.hpp"

namespace ft
{
template<typename T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef T					value_type;
	typedef Allocator				Allocator_type;
	typedef typename Allocator::pointer		pointer;
	typedef typename Allocator::reference		reference;
	typedef typename Allocator::const_pointer	const_pointer;
	typedef typename Allocator::const_reference	const_reference;
	typedef	typename std::size_t			size_type;
	typedef typename std::ptrdiff_t			difference_type;

	typedef typename ft::random_access_iterator<pointer>		iterator;
	typedef typename ft::random_access_iterator<const_pointer>	const_iterator;
	typedef typename ft::reverseIterator<iterator>			reverse_iterator;
	typedef typename ft::reverseIterator<const_iterator>		const_reverse_iterator;


//constructors

	explicit vector():_alloc(Allocator()), _ptr(0), _size_alloc(0), _size_filled(0){};

	explicit vector (const Allocator & alloc):_alloc(alloc), _ptr(0), _size_alloc(0), _size_filled(0){};

	vector (const vector & A):_alloc(A._alloc){*this = A;}

	explicit vector (size_type count, const T& value = T(), const Allocator& alloc = Allocator())
	:_alloc(alloc),_ptr(0),_size_alloc(0),_size_filled(0)
	{
		this->reserve(count);
		for (size_t i = 0; i < count; i++)
			_alloc.construct(_ptr + i, value);
		_size_alloc = count;
		_size_filled = count;
	}
	
	template <class InputIt>
	vector (InputIt first, typename enable_if<!is_integral<InputIt>::value,InputIt>::type last, const Allocator &alloc = Allocator())
	:_alloc(alloc), _ptr(0), _size_alloc(0), _size_filled(0)
	{
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
	}
	
	

	~vector()
	{
		this->clear();
		if (_size_alloc > 0)
		{
			_alloc.deallocate(_ptr, _size_alloc);
			_size_alloc = 0;
		}
	}

	//---------------ASSIGNEMENT-----------------------
	vector & operator=(const vector & A)
	{
		this->clear();
		for (const_iterator it = A.begin(); it != A.end(); it++)
			this->push_back(*it);
		return (*this);
	}
	
	vector & operator=(vector & A)
	{
		this->clear();
		for (iterator it = A.begin(); it != A.end(); it++)
			this->push_back(*it);
		return (*this);
	}
	
	void	assign(size_type count, const T& value)
	{
		this->clear();
		for (size_t i = 0; i < count; i++)
			this->push_back(value);
	}

	template <class InputIt>
	void	assign(InputIt first, typename enable_if<!is_integral<InputIt>::value,InputIt>::type last)
	{
		this->clear();
		for (iterator it = first; it != last; it++)
			this->push_back(*it);
	}




	// ------------ELEMENT ACCESS---------------------------
	reference at(size_type pos)
	{
		if (pos >= _size_filled)
			throw std::out_of_range("out of range");
		return (_ptr[pos]);
	}

	const_reference at(size_type pos) const
	{
		if (pos >= _size_filled)
			throw std::out_of_range("out of range");
		return (_ptr[pos]);
	}

	reference operator[](size_type pos) {return (_ptr[pos]);}
	const_reference operator[](size_type pos) const {return (_ptr[pos]);}

	reference front() {return (_ptr[0]);}
	const_reference front() const {return (_ptr[0]);}

	reference back() {return (_ptr[_size_filled - 1]);}
	const_reference back() const {return (_ptr[_size_filled - 1]);}

	//iterators
	iterator begin() {return (iterator(_ptr));}
	const_iterator begin() const {return (const_iterator(_ptr));}

	iterator end() {return (iterator(_ptr + _size_filled));}
	const_iterator end() const {return (const_iterator(_ptr + _size_filled));}

	reverse_iterator rbegin() { return (reverse_iterator(this->end() - 1));}
	const_reverse_iterator rbegin() const { return (rbegin());}

	reverse_iterator rend() { return (reverse_iterator(this->begin()));}
	const_reverse_iterator rend() const { return (rend());}

	//capacity
	bool		empty() const {return ((_size_filled == 0));}

	size_type	size() const {return (_size_filled);}

	size_type	max_size() const { return (std::numeric_limits<size_type>::max());}

	size_type	capacity() const { return (_size_alloc);}

	void		reserve(size_type new_cap)
	{
		if (new_cap > _size_alloc)
		{
			value_type	*new_array;
			new_array = _alloc.allocate(new_cap);
			for (size_t i = 0; i < _size_filled; i++)
				_alloc.construct(new_array + i, *(_ptr + i));
			//_alloc.deallocate(_ptr, _size_alloc);
			_size_alloc = new_cap;
			_ptr = new_array;
		}
	}

	//---------------------MODIFIERS--------------------------
	void	clear()
	{
		if (_size_filled > 0)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
				_alloc.destroy(&(*it));
			_size_filled = 0;
		}		
	}

	void	push_back(const T& value)
	{
		if (_size_alloc == 0)
		{
			_ptr = _alloc.allocate(1);
			_size_alloc++;
		}
		if (_size_filled == _size_alloc)
			_extend();
		_alloc.construct(_ptr + _size_filled, value);
		_size_filled++;
	}

	void	pop_back()
	{
		if (_size_filled > 0)
		{
			_alloc.destroy(_ptr + (_size_filled - 1));
			_size_filled--;
		}
	}

	void	swap(vector & other)
	{
		vector<value_type> temp;
		temp = *this;
		*this = other;
		other = temp;
	}

	iterator erase(iterator pos)
	{
		vector	temp(pos + 1, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();
		this->pop_back();
		for (iterator it = temp.begin(); it != temp.end(); it++)
			this->push_back(*it);
		return (pos);
	};

	iterator	erase(iterator first, iterator last)
	{
		iterator temp(first);
		while (temp != last)
		{
			this->erase(first);
			temp++;
		}
		return (first);
	}

	iterator	insert(iterator pos, const T& value)
	{
		iterator			absolute_iterator;
		difference_type		int_pos = pos - this->begin();

		if (this->capacity() == this->size())
			_extend();
		absolute_iterator = this->begin() + int_pos;

		vector		temp(absolute_iterator, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();

		this->push_back(value);
		iterator it = temp.begin();
		for (size_t i = 0; i < temp.size(); i++, it++)
			this->push_back(*it);
		return (this->begin() + int_pos);
	};

	void	insert(iterator pos, size_type count, const T& value)
	{
		difference_type		dif = pos - this->begin();	
		while (_size_alloc - _size_filled < count)
			_extend();
		iterator position = this->begin() + dif;
		for (size_type i = 0; i < count ; i++)
			this->insert(position, value);
	}

	template <class InputIt>
	void	insert(iterator pos, InputIt first, typename enable_if<!is_integral<InputIt>::value,InputIt>::type last)
	{
		difference_type		dif1 = last - first;
		difference_type		dif2 = pos - this->begin();

		while ( _size_alloc - _size_filled < (unsigned long)dif1)
			_extend();
		iterator position = this->begin() + dif2;
		for (long i = 0; i < dif1 ; i++)
			this->insert(position, *first++);
	}


	void	resize(size_type n, value_type val = value_type())
	{
		value_type	*new_arr;

		new_arr = _alloc.allocate(n);
		if (n > _size_filled)
		{
			for (size_t i=0; i < _size_filled; i++)
				_alloc.construct(new_arr + i, *(_ptr + i));
			for (size_t i=0; i < n - _size_filled; i++)
				_alloc.construct(new_arr + _size_filled + i, val);
		}
		else
		{
			for (size_t i=0; i < n; i++)
				_alloc.construct(new_arr + i, *(_ptr + i));
		}
		if (_size_filled)
		{
			_alloc.destroy(_ptr);
			_alloc.deallocate(_ptr, _size_alloc);
		}
		_size_alloc = n;
		_size_filled = n;
		_ptr = new_arr;
	}	
		

private:
	Allocator	_alloc;
	T*		_ptr;   	//tableau de donnees
	size_t		_size_alloc;	//nombre de blocks alloue a _ptr;
	size_t		_size_filled;	// nombre d'objets contenus dans le container.


	void	_extend()
	{
		if (_size_alloc == 0)
		{
			_ptr = _alloc.allocate(1);
			_size_alloc = 1;
		}
		else
		{
			T*	new_array;
			new_array = _alloc.allocate(_size_alloc * 2);
			for (size_t i = 0; i < _size_filled; i++)
			{
				_alloc.construct(new_array + i, *(_ptr + i));
				_alloc.destroy(_ptr + i);
			}
			_alloc.deallocate(_ptr, _size_alloc);
			_ptr = new_array;
			_size_alloc = _size_alloc * 2;
		}
	}



};

//-----------NON MEMBERS FUNCTION---------------------------

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return (equal(A.begin(),A.end(),B.begin()));
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return (!(A == B));
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return (lexicographical_compare(A.begin(),A.end(),B.begin(),B.end()));
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return ( (A < B) || (A == B));
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return ( B < A);
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& A, const vector<T,Alloc>& B)
{
	return ( (B < A) || (A == B));
}

template	< class T >
void		swap (vector<T> & A, vector<T> & B) 
{
	A.swap(B);
}


template <class T>
std::ostream& operator<<(std::ostream& flux, ft::vector<T>& A)
{
	if (A.empty())
		return (flux);
	for (size_t i=0; i < A.size(); i++)
		flux << A[i] << std::endl;
	return flux;
}



}
#endif
