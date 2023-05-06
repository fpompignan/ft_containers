#ifndef MAP_HPP
#define MAP_HPP


namespace ft
{

//--------------PAIR----------------------------------------------

template <typename Tkey, typename Tvalue>
class pair
{
    public:
    pair(){};
    
    pair(const pair & A){*this = A;}

    pair(const Tkey& key, const Tvalue& value):first(key), second(value){}

    ~pair(){};

    pair & operator=(const pair & A)
    {
        this->first = A.first;
        this->second = A.second;
        return (*this);
    }

    Tkey    first;
    Tvalue  second;

};

template <class Tkey, class Tvalue>
bool operator==(const pair<Tkey,Tvalue>& A, const pair<Tkey,Tvalue>& B)
{
	return ((A.first == B.first) && (A.second == B.second));
}

template <class Tkey, class Tvalue>
bool operator!=(const pair<Tkey,Tvalue>& A, const pair<Tkey,Tvalue>& B)
{
	return (!(A==B));
}

template <class Tkey, class Tvalue>
std::ostream &	operator<<(std::ostream & flux, pair<Tkey,Tvalue> const  & A)
{
	flux << "key = " << A.first << ", value = " << A.second;
	return (flux);
}

template <typename Tkey, typename Tvalue>
pair<Tkey,Tvalue>	make_pair(Tkey key, Tvalue value)
{
	return (pair<Tkey,Tvalue>(key,value));
}


//----------------------NODE----------------------------------------
template <typename Tkey, typename Tvalue>
class MapNode
{
public:
	typedef MapNode<Tkey,Tvalue>		node;
	typedef	node*				node_ptr;
	typedef const node*			const_node_ptr;
	typedef ft::pair<Tkey,Tvalue>		pair;

	MapNode():_empty(false),_top(NULL),_left(NULL),_right(NULL){}	
	MapNode(const pair & p):_empty(false),_keyval(p),_top(NULL),_left(NULL),_right(NULL){}
	MapNode(const MapNode & A){*this = A;}
	virtual ~MapNode(){}

	MapNode &	operator=(const MapNode & A)
	{
		_keyval = A._keyval;
		_top	= A._top;
		_left	= A._left;
		_right  = A._right;
		return (*this);
	}

	void	set_top(const node_ptr top){_top = top;}
	void	set_left(const node_ptr left){_left = left;}
	void	set_right(const node_ptr right){_right = right;}

	const_node_ptr	get_curr() const {return (this);}
	node_ptr	get_top() const {return (_top);}
	node_ptr	get_left() const {return (_left);}
	node_ptr	get_right() const {return (_right);}

	void	set_key(const Tkey & key) {_keyval.first = key;}
	void	set_val(const Tvalue & value) {_keyval.second = value;}
	void	set_pair(const pair & p) {_keyval = p;}

	Tkey&		get_key()  {return (_keyval.first);}
	const Tkey&	get_key() const {return (_keyval.first);}
	Tvalue&		get_val()  {return (_keyval.second);}
	pair&		get_pair()  {return (_keyval);}
	const pair&	get_pair() const {return (_keyval);}


private:
	bool		_empty;
	pair		_keyval;
	node_ptr	_top;
	node_ptr	_left;
	node_ptr	_right;
};

template <typename Tkey, typename Tvalue>
std::ostream&	operator<<(std::ostream& flux, const MapNode<Tkey,Tvalue>& A)
{
	flux << "curr = " << A.get_curr() << std::endl;
	flux << "_top = " << A.get_top() << std::endl;
	flux << "_left = " << A.get_left() << std::endl;
	flux << "_right = " << A.get_right() << std::endl;
	flux << "_keyval = " << A.get_pair() << std::endl;
	return (flux);
}

//----------------MAP ITERATOR (parcours infixe)-----------------------

template <typename Tkey, typename Tvalue, class Compare = std::less<Tkey> >
class mapIterator
{
public:
	typedef MapNode<Tkey,Tvalue>		node;
	typedef node*				node_ptr;
	typedef ft::pair<Tkey, Tvalue>		pair;

	typedef	typename ft::map_iterator_traits<node>::value_type		value_type;	
	typedef	typename ft::map_iterator_traits<node>::difference_type		difference_type;	
	typedef	typename ft::map_iterator_traits<node>::pointer			pointer;	
	typedef	typename ft::map_iterator_traits<node>::reference		reference;	
	typedef	typename ft::map_iterator_traits<node>::iterator_category	iterator_category;	

	//constructors
	mapIterator():_is_ghost(false){}
	mapIterator(node_ptr pt):_is_ghost(false),_ptr(pt){}
	mapIterator(const mapIterator& A):_is_ghost(false),_ptr(NULL){*this = A;}
	~mapIterator(){}
	/*{
		if (_is_ghost == true)
			//delete _ptr;
	}*/

	mapIterator & operator=(const mapIterator& A)
	{
		if(_is_ghost == true)
			delete _ptr;
		_ptr = A._ptr;
		_is_ghost = A._is_ghost;
		return (*this);
	}	

	//incrementation

	mapIterator	operator++()	//++a
	{
		if (is_the_last_leaf() == true)
		{
			node_ptr	ghost_node = new node();
			
			ghost_node->set_top(_ptr);
			set_is_ghost(true);
			_ptr = ghost_node;
			return (*this);
		}
		if (_ptr->get_right())
		{
			_ptr = _ptr->get_right();
			go_leftmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_left() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_left() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	}

	mapIterator	operator--()		//--a
	{
		if(_is_ghost == true)
		{
			node_ptr	temp = _ptr->get_top();

			//delete _ptr;
			_ptr = temp;
			_is_ghost = false;
			return (*this);
		}			
		if (_ptr->get_left())
		{
			_ptr = _ptr->get_left();
			go_rightmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_right() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_right() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	}

	mapIterator operator++(int)		//a++
	{
		mapIterator temp = *this;
		++(*this);
		return (temp);
	}

	mapIterator operator--(int)		//a--
	{
		mapIterator temp = *this;
		--(*this);
		return (temp);
	}


	mapIterator operator+(difference_type n)   // a + n
	{
		mapIterator temp(*this);
		for (difference_type i = 0; i < n; i++)
			++temp;
		return temp;
	}

	mapIterator operator-(difference_type n)   //  a - n
	{
		mapIterator temp(*this);
		for (difference_type i = 0; i < n; i++)
			--temp;
		return temp;
	}



	bool	operator==(const mapIterator & A) const
	{
		if (this->_is_ghost == true && A._is_ghost == true)
			return true;
		else if (this->_is_ghost == true || A._is_ghost == true)
			return false;
		return (_ptr->get_key() == A._ptr->get_key());
	}

	bool	operator!=(const mapIterator & A) const {return (!(*this == A));}

	
	reference	operator*() {return (*_ptr);}
	//reference	operator*() const {return (_ptr->get_pair());}
	pointer		operator->() {return (_ptr);}
	pointer		operator->() const {return (&(_ptr->get_pair()));}




	void	go_rightmost()
	{
		while (_ptr->get_right())
			_ptr = _ptr->get_right();
	}	

	void	go_leftmost()
	{
		while (_ptr->get_left())
			_ptr = _ptr->get_left();
	}	


	bool	is_the_last_leaf(void)
	{
		node_ptr	move = _ptr;
		
		if (move->get_right())
			return (false);
		while (move->get_top() && move->get_top()->get_right() == move)
			move = move->get_top();
		return ((move->get_top() == NULL));
	} 
		
	void		set_is_ghost(bool b){_is_ghost = b;}
	node_ptr	get_ptr() const {return _ptr;}
	bool		get_is_ghost() const {return _is_ghost;}



private:
	bool		_is_ghost;
	node_ptr	_ptr;


};

//---------------------------------MAP----------------------------------------

template < class Tkey,
	   class Tvalue,
	   class Compare = std::less<Tkey>,
	   class Alloc = std::allocator<pair<const Tkey, Tvalue>>
	 >
class map
{
public:
//-----------------members type--------------------------
	typedef	Tkey				key_type;
	typedef Tvalue				mapped_type;
	typedef	ft::pair<Tkey, Tvalue>		value_type;
	typedef	std::size_t			size_type;
	typedef	std::ptrdiff_t			difference_type;
	typedef	Compare				key_compare;
	typedef	Alloc				allocator_type;

	typedef	value_type &			reference;
	typedef const value_type &		const_reference;
	typedef	value_type *			pointer;
	typedef const value_type *		const_pointer;

	typedef mapIterator<key_type, mapped_type>		iterator;
	typedef mapIterator<const key_type, mapped_type>	const_iterator;
	typedef reverseIterator<iterator>			reverse_iterator;
	typedef reverseIterator<const iterator>			const_reverse_iterator;

	typedef MapNode<Tkey, Tvalue>				node;
	typedef node *						node_ptr;

//-------------------constructors-----------------------------------

	explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = Alloc())
	:_size(0), _root(NULL), _comp(comp), _alloc(alloc){}

	template<class InputIt>
	map(InputIt first, typename enable_if<!is_integral<InputIt>::value,InputIt>::type last,
		const Compare & comp = Compare(), const Alloc & alloc = Alloc())
	:_size(0), _root(NULL), _comp(comp), _alloc(alloc)
	{
		insert(first, last);
	}


	map(map & A)
	:_size(0), _root(NULL), _comp(key_compare()), _alloc(allocator_type()){*this = A;}

	virtual ~map(){this->clear();} 

	map &	operator=(map & A)
	{
		clear();
		if (A.size() > 0)
			insert(A.begin(),A.end());
		return (*this);
	}

//-----------------Element access--------------------------------------

	mapped_type & operator[](const key_type & key)
	{
		node_ptr	res = _find_node(key);

		if (_root == NULL)
		{
			value_type pair(key,mapped_type());
			_size++;
			_root = _new_node(pair);
			return (_root->get_val());
		}
		else if (res->get_key() != key)
		{
			value_type pair(key,mapped_type());
			_size++;
			return (_assign_pair_node(res, pair));
		}
		return (res->get_val());
	}

	mapped_type & at(const key_type & key)
	{
		node_ptr	res = _find_node(key);
	
		if (res->get_key() != key)
			throw	std::out_of_range("out of range");
		return (res->get_val());
	} 

//-----------------capacity---------------------------------------

	bool 		empty() const { return (_size == 0);}
	size_type	size() const { return (_size);}
	
	size_type	max_size() const
	{
		return (std::numeric_limits<size_type>::max() / sizeof(value_type));
	}

//-----------------iterators--------------------------------

		
	iterator	begin()
	{
		iterator	it(_root);
		it.go_leftmost();
		return (it);
	}

	const_iterator	begin () const 
	{
		const_iterator	it(_root);
		it.go_leftmost();
		return (it);
	}

//End will stored a ghost node that have for top pointer the rightmost element

	iterator	end()
	{
		iterator 	righestnode(_root);
		righestnode.go_rightmost();

		node_ptr	ghost_node = _new_node();
		ghost_node->set_top(righestnode.get_ptr());
		
		iterator	result(ghost_node);
		result.set_is_ghost(true);

		return (result);
	}

	const_iterator	end () const 
	{
		iterator 	righestnode(_root);
		righestnode.go_rightmost();

		node_ptr	ghost_node = _new_node();
		ghost_node->set_top(righestnode.get_ptr());
		
		const_iterator	result(ghost_node);
		result.set_is_ghost(true);
		return (result);
	}
		
		
	reverse_iterator rbegin()
	{
		reverse_iterator it(--this->end());
		return it;
	}	
	const_reverse_iterator rbegin() const
	{
		const_reverse_iterator it(--this->end());
		return it;
	}

	reverse_iterator rend()
	{
		reverse_iterator it(this->begin());
		return it;
	}	
	const_reverse_iterator rend() const
	{
		const_reverse_iterator it(this->begin());
		return it;
	}

//-------------------modifiers----------------------------------------

	ft::pair<iterator, bool>	insert (const value_type & pair)
	{
		node_ptr	res = _find_node(pair.first);
	
		if (res == NULL)
		{
			_root = new node(pair);
			res = _find_node(pair.first);
			_size++;
		}	
		if (res->get_key() == pair.first)
		{
			iterator it(res);
			ft::pair<iterator, bool> p(it, false);
			return p;
		}
		else
		{
			value_type	pair1 = static_cast<value_type>(pair);
			_size++;
			_assign_pair_node(res, pair1);
			if (_comp(pair.first, res->get_key()) == true)
			{
				iterator	it(res->get_left());
				ft::pair<iterator,bool> p(it, true);
				return (p);
			}
			else
			{
				iterator	it(res->get_right());
				ft::pair<iterator,bool> p(it, true);
				return (p);
			}
		}
	}
			
	iterator	insert(iterator hint, const value_type & pair)
	{
		//iterator temp;
		//temp = hint;
		iterator temp(hint);

		node_ptr	res = _find_node(pair.first);
		
		if (res->get_key() == pair.first)
		{
			iterator	it(res);
			return (it);
		}
		else
		{
			value_type	pair1 = static_cast<value_type>(pair);
			_size++;
			_assign_pair_node(res, pair1);
			if (_comp(pair.first, res->get_key()) == true)
			{
				iterator	it(res->get_left());
				return (it);
			}
			else
			{
				iterator	it(res->get_right());
				return (it);
			}
		}
	}


	template<class InputIt>
	void	insert(InputIt first, typename enable_if<!is_integral<InputIt>::value,InputIt>::type last)
	{
		while (first != last)
		{
			const value_type	p(first.get_ptr()->get_pair());
			insert(p);
			//insert(first->get_pair());
			first++;
		}
	}

	size_type	erase(const key_type & k)
	{
		node_ptr	target = _find_node(k);
		node_ptr	new_root;

		if (target != NULL && target->get_key() != k)
			return (0);
		
		_size--;
		if (target->get_left() == NULL && target->get_right() == NULL)
			new_root = _delete_leaf(target);
		else if (target->get_left() == NULL || target->get_right() == NULL)
			new_root = _delete_branch_one_child(target);
		else
			new_root = _delete_branch_two_child(target);
		
		if (new_root != NULL && new_root->get_top() == NULL)
			_root = new_root;
		return (1);
	}

	iterator	erase(iterator pos)
	{
		iterator it = pos;
		it = pos + 1;
		erase(pos.get_ptr()->get_key());
		return (it);
	}

	iterator	erase(iterator first, iterator last)
	{
		iterator it = first;
		while (first != last)
		{
			first++;
			erase(it);
			it = first;
		}
		return first;
	}

	void	clear()
	{
		if (_size > 0)
			erase(begin(),end());
		_root = NULL;
	}


	void swap (map& x)
	{
		size_t		x_size = x._size;
		node_ptr	x_root = x._root;

		x._root = _root;
		x._size = _size;

		_root = x_root;
		_size = x_size;
	};
		
//---------------OBSERVERS-------------------------

	key_compare	key_comp() const {return (_comp);}


	class value_compare
	{
	public:
		value_compare(Compare comp):_comp(comp){}
		virtual	~value_compare(){}

		bool	operator()(const value_type & A, const value_type & B)
		{
			return (_comp(A.first,B.first));
		}
	private:	
		Compare	_comp;
	};

	value_compare	value_comp() const {return (value_compare(_comp));}

//-------------------LOOK UP----------------------------------------

	iterator	find(const key_type & k)
	{
		node_ptr res = _find_node(k);

		if (res->get_key() == k)
			return (iterator(res));
		else
			return (end());
	}

	const_iterator	find(const key_type & k) const
	{
		node_ptr res = _find_node(k);

		if (res->get_key() == k)
			return (const_iterator(res));
		else
			return (end());
	}

	size_type	count(const key_type & k)
	{
		node_ptr res = _find_node(k);

		if (res->get_key() == k)
			return (1);
		else
			return (0);
	}


	iterator	lower_bound(const key_type & k)
	{
		iterator	it = begin();

		while (it != end() && _comp(it.get_ptr()->get_key(),k) == true)
			it++;
		return (it);
	}

	const_iterator	lower_bound(const key_type & k) const
	{
		return (lower_bound(k));
	}

	iterator	upper_bound(const key_type & k)
	{
		iterator	it = begin();

		while (it != end() && _comp(it.get_ptr()->get_key(),k) == true)
			it++;
		if (it == end())
			return (end());
		if (it.get_ptr()->get_key() == k)
			it++;
		return (it);
	}

	const_iterator upper_bound (const key_type & k) const
	{
		return (upper_bound(k));
	}

	ft::pair<iterator, iterator>	equal_range(const key_type & k)
	{
		return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	}
	
	ft::pair<const_iterator, const_iterator>	equal_range(const key_type & k) const
	{
		return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
	}









private:
	size_t		_size;
	node_ptr	_root;
	key_compare	_comp;
	allocator_type	_alloc;



	// pour creer et allouer facilement des nodes
	node_ptr	_new_node() const
	{
		node_ptr	res;
		res = new node();
		return (res);
	}

	node_ptr	_new_node(value_type & pair) const
	{
		node_ptr	res;
		res = new node(pair);
		return (res);
	}
			
	// Return the node that have val for key. If no node found with val for key, return the node who will be the parent.	
	node_ptr	_find_node(const key_type & val)
	{
		node_ptr	temp = _root;

		while (temp != NULL && temp->get_key() != val)
		{
			if (_comp(val, temp->get_key()) == true)
			{
				if (temp->get_left() != NULL)
					temp = temp->get_left();
				else
					break;
			}
			else
			{
				if (temp->get_right() != NULL)
					temp = temp->get_right();
				else
					break;
			}
		}
		return (temp);
	}
	
	//Function qui assigne une paire a une feuille et la rattache a un noeud donne
	mapped_type &	_assign_pair_node(node_ptr node, value_type & val)
	{
		node_ptr	temp = _new_node(val);

		 temp->set_top(node);
		if (_comp(val.first, node->get_key()) == true)
			node->set_left(temp);
		else
			node->set_right(temp);
		return (temp->get_val());
	}
		

	node_ptr	_delete_leaf(node_ptr & leaf)
	{
		if (leaf->get_top())
		{
			if (leaf->get_top()->get_left() == leaf)
				leaf->get_top()->set_left(NULL);
			else
				leaf->get_top()->set_right(NULL);
		}
		delete leaf;
		return (NULL);
	}
			
	node_ptr	_delete_branch_one_child(node_ptr & leaf)
	{
		node_ptr	child;

		if (leaf->get_left())
			child = leaf->get_left();
		else
			child = leaf->get_right();

		if (leaf->get_top() != NULL)
		{
			if (leaf->get_top()->get_left() == leaf)
				leaf->get_top()->set_left(child);
			else 
				leaf->get_top()->set_right(child);
		}
		child->set_top(leaf->get_top());
		delete leaf;
		return (child);
	}
	
	node_ptr	_delete_branch_two_child(node_ptr & leaf)
	{
		node_ptr	to_exchange = leaf->get_right();

		while (to_exchange->get_left())
			to_exchange = to_exchange->get_left();

		if (to_exchange == leaf->get_right())
		{
			to_exchange->set_top(leaf->get_top());
			if (leaf->get_top())
			{
				if (leaf->get_top()->get_left() == leaf)
					leaf->get_top()->set_left(to_exchange);
				else
					leaf->get_top()->set_right(to_exchange);
			}
			to_exchange->set_left(leaf->get_left());
			leaf->get_left()->set_top(to_exchange);
			delete leaf;
		}
		else
		{
			to_exchange->get_top()->set_left(to_exchange->get_right());
			to_exchange->set_right(leaf->get_right());
			to_exchange->get_right()->set_top(to_exchange);
			to_exchange->set_top(leaf->get_top());
			to_exchange->set_left(leaf->get_left());
			to_exchange->get_left()->set_top(to_exchange);
			if (to_exchange->get_top())
			{
				if(to_exchange->get_top()->get_left() == leaf)
					to_exchange->get_top()->set_left(to_exchange);
				else if (to_exchange->get_top()->get_right() == leaf)
					to_exchange->get_top()->set_right(to_exchange);
			}
			delete leaf;
		}
		return (to_exchange);
	}



};




template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>>
bool operator==( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
	iterator	it1(A.begin());
	iterator	it2(B.begin());

	while (it1 != A.end())
        {
                if (it1.get_ptr()->get_key() != it2.get_ptr()->get_key())
                        return (false);
                it1++; 
                it2++;
        }
        return (true);	
}


template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>>
bool operator!=( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
        return (!(A == B));
}

template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>, class compare= std::less<Tkey>>
bool operator<( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
	
	iterator	it1(A.begin());
	iterator	it2(B.begin());

	compare		comp;

	while (it1 != A.end())
        {
		if (it1.get_ptr()->get_key() == it2.get_ptr()->get_key())
		{
			it1++;
			it2++;
		}
		else if(comp(it1.get_ptr()->get_key(), it2.get_ptr()->get_key()) == true)
			return true;
		else 
			return false;
                //if (it1.get_ptr()->get_key() >= it2.get_ptr()->get_key())
                        //return (false);
        }
	return (false);
}

template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>>
bool operator<=( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
        return ( (A < B) || (A == B));
}

template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>>
bool operator>( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
	std::cout << "coucoyc" << std::endl;	
        return ( B < A);
}

template <class Tkey, class Tvalue, class iterator = mapIterator<Tkey, Tvalue>>
bool operator>=( map<Tkey, Tvalue> & A,  map<Tkey,Tvalue> & B)
{
        return ( (B < A) || (A == B));
}

template <class Tkey, class Tvalue>
void            swap (map<Tkey, Tvalue> & A, map<Tkey, Tvalue> & B)
{
        A.swap(B);
}



template <class Tkey, class Tvalue, class iterator=mapIterator<Tkey,Tvalue>>
std::ostream& operator<<(std::ostream& flux, ft::map<Tkey, Tvalue>& A)
{
        if (A.empty())
                return (flux);
	
	for (iterator it = A.begin(); it != A.end(); it++)
		flux << it.get_ptr()->get_pair() << std::endl;
        return flux;
}










}
#endif
