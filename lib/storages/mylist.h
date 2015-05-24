#ifndef MYLIST_H
#define MYLIST_H

//------------------------------------------------------------------------
//----------------------------------LIST---------------------------------
//------------------------------------------------------------------------
template<typename item_type> class mylist
{
private:
	struct Cell
	{
		item_type data;
		Cell *next;
		Cell *prev;
	};
	Cell *_first;
	Cell *_last;
	unsigned _size;
public:
	friend class myiterator;

	// default constructor
	mylist()
	{
		_first = 0;
		_last = 0;
		_size = 0;
		return;
	}

	// copying constructor
	mylist(const mylist& storage);

	// destructor
	~mylist()
	{
		if (_first)
		{
			Cell* _current = _first;
			do
			{
				Cell *cc = _current->next;
				delete _current;
				_current = cc;
			} while (_current);
		}
		return;
	}

	// assign content
	void operator=(const mylist& storage);

	// add element at the end
	void push_back(const item_type&);

	// insert element at beginning
	void push_front(const item_type&);

	// access first element
	item_type& front() const
	{
		return _first->data;
	}

	// access last element
	item_type& back() const
	{
		return _last->data;
	}

	class myiterator
	{
	private:
		Cell *_current;

	public:
		friend class mylist < item_type > ;
		myiterator()
		{
			_current = 0;
		}
		myiterator(const mylist& l)
		{
			_current = l._first;
		}
		myiterator(Cell* pointer)
		{
			_current = pointer;
		}
		item_type& operator*()
		{
			return _current->data;
		}
		myiterator operator++(int)
		{
			_current = _current->next;
			return myiterator(_current);
		}
		myiterator operator++()
		{
			_current = _current->next;
			return myiterator(_current);
		}
		myiterator operator--(int)
		{
			_current = _current->prev;
			return myiterator(_current);
		}
		myiterator operator--()
		{
			_current = _current->prev;
			return myiterator(_current);
		}
		bool valid()
		{
			if (_current) return true;
			return false;
		}
		bool operator==(const myiterator& other)
		{
			return _current == other._current;
		}
		bool operator!=(const myiterator& other)
		{
			return _current != other._current;
		}
		void operator=(const myiterator& other)
		{
			_current = other._current;
		}
		void operator=(int other)
		{
			_current = reinterpret_cast<item_type*>(other);
		}
	};

	// insert element
	myiterator insert(myiterator, const item_type&);

	// erase element
	void erase(myiterator);

	// clear content
	void clear();

	// return size
	unsigned size() const
	{
		return _size;
	}

	// get myiterator to begin
	myiterator begin() const
	{
		return myiterator(_first);
	}

	// get myiterator to end
	myiterator end() const
	{
		return myiterator(_last);
	}

	// test whether container is empty
	bool empty() const
	{
		return _size ? true : false;
	}

	myiterator find(const item_type& a)
	{
		for (myiterator i(_first); i.valid(); i++)
		{
			if (*i == a) return i;
		}
		return myiterator(0);
	}
};

template<typename item_type> mylist<item_type>::mylist(const mylist& storage)
{
	if (storage._first != 0)//if not empty
	{
		//create first cell with storage's data
		Cell* _current = new Cell;
		_current->data = storage._first->data;
		_current->next = 0;
		_current->prev = 0;
		_first = _current;
		if (storage._first->next)
		{
			for (myiterator i = storage.begin()++; i.valid(); i++)
			{
				Cell *p = new Cell;
				p->data = *i;
				p->prev = _current;
				_current->next = p;
				_current = p;
			}
		}
		_current->next = 0;
		_size = storage._size;
		_last = _current;
	}
	else
	{
		_first = 0;
		_last = 0;
		_size = 0;
	}
	return;
}

template<typename item_type> void mylist<item_type>::operator=(const mylist& storage)
{
	clear();
	if (storage._first != 0)//if not empty
	{
		//create first cell with storage's data
		Cell* _current = new Cell;
		_current->data = storage._first->data;
		_current->next = 0;
		_current->prev = 0;
		_first = _current;
		if (storage._first->next)
		{
			for (myiterator i = storage.begin()++; i != storage.end(); i++)
			{
				Cell *p = new Cell;
				p->data = *i;
				p->prev = _current;
				_current->next = p;
				_current = p;
			}
		}
		_current->next = 0;
		_size = storage._size;
		_last = _current;
	}
	else
	{
		_first = 0;
		_last = 0;
		_size = 0;
	}
	return;
}

template<typename item_type> void mylist<item_type>::push_back(const item_type &item)
{
	if (_first)//add new item
	{
		Cell *c = new Cell;
		_last->next = c;
		_last->next->prev = _last;
		_last = c;
		_last->data = item;
		_last->next = 0;
		_size++;
		//return &(_last->data);
	}
	else//create first item
	{
		_first = new Cell;
		_first->data = item;
		_first->next = 0;
		_first->prev = 0;
		_last = _first;
		_size = 1;
		//return &(_last->data);
	}
}

template<typename item_type> typename mylist<item_type>::myiterator mylist<item_type>::insert(myiterator iter, const item_type& item)
{
	if (iter.valid())
	{
		Cell* p = new Cell;
		p->data = item;
		p->next = iter._current->next;
		iter._current->next = p;
		if (p->next) p->next->prev = p;
		p->prev = iter._current;
		_size++;
		return myiterator(p);
	}
	return myiterator(0);
}

template<typename item_type> void mylist<item_type>::push_front(const item_type &item)
{
	if (_first)//add new item
	{
		Cell *c = new Cell;
		_first->prev = c;
		_first->prev->next = _first;
		_first = c;
		_first->data = item;
		_first->prev = 0;
		_size++;
		//return &(_last->data);
	}
	else//create first item
	{
		_first = new Cell;
		_first->data = item;
		_first->next = 0;
		_first->prev = 0;
		_last = _first;
		_size = 1;
		//return &(_last->data);
	}
}


template<typename item_type> void mylist<item_type>::erase(myiterator iter)
{
	if (iter._current)
	{
		Cell* prev;
		Cell* next;
		prev = iter._current->prev;
		next = iter._current->next;
		if (!prev && !next)
		{
			delete iter._current;
			_first = 0;
			_last = 0;
		}
		else
		{
			if (prev) prev->next = next;
			if (next) next->prev = prev;
			delete iter._current;
		}
		_size--;
	}
}

template<typename item_type> void mylist<item_type>::clear()
	{
		if (_first)
		{
			Cell* _current = _first;
			do
			{
				Cell *cc = _current->next;
				delete _current;
				_current = cc;
			} while (_current);
			_size = 0;
			_first = 0;
			_last = 0;
		}
		return;
	}

#endif // MYLIST_H
