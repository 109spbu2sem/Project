#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

//-----------------------------------------------------------------------
//----------------------------Array-------------------------------------
//-----------------------------------------------------------------------

template<typename item_type> class myvector
{
private:
	item_type *_items;
	unsigned _size;
	unsigned _memory;


	unsigned _2pow(unsigned b)
	{
		return 1 << b;
	}
public:

	friend class myiterator;

	// default constructor
	myvector()
	{
		_items = 0;
		_size = 0;
		_memory = 0;
	};

	// copy constructor
	myvector(myvector& storage);

	// destructor
	~myvector();

	// assign content
	void operator=(const myvector& storage);

	// access element
	item_type& operator[] (unsigned num) const;

	item_type& at(unsigned num) const;

	void push_back(const item_type&);

	// access first element
	item_type& front() const
	{
		return _items[0];
	}

	// access last element
	item_type& back() const
	{
		return _items[_size];
	}

	// return size
	unsigned size() const
	{
		return _size;
	}

	// clear content
	void clear();

	// test whether container is empty
	bool empty()
	{
		return _items ? false : true;
	}

	class myiterator
	{
	private:
		item_type* _current;
	public:
		myiterator()
		{
			_current = 0;
		}
		myiterator(item_type* pointer)
		{
			_current = pointer;
		}
		myiterator(myvector<item_type>& l)
		{
			_current = l._items;
		}
		item_type& operator*() const
		{
			return *_current;
		}
		myiterator operator++(int i)
		{
			_current++;
			return myiterator(_current);
		}
		myiterator operator++()
		{
			_current++;
			return myiterator(_current);
		}
		myiterator operator--(int i)
		{
			_current--;
			return myiterator(_current);
		}
		myiterator operator--()
		{
			_current--;
			return myiterator(_current);
		}
		bool operator==(const myiterator& other) const
		{
			return _current == other._current;
		}
		bool operator!=(const myiterator& other) const
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
		bool valid() const
		{
			if (_current) return true;
			return false;
		}
		item_type& operator[](unsigned num) const
		{
			return _current[num];
		}
		item_type& operator[](int num) const
		{
			return _current[num];
		}
	};

	// get myiterator to begin
	myiterator begin() const
	{
		return myiterator(_items);
	}

	// get myiterator to  end
	myiterator end() const
	{
		return myiterator(_items + _size);
	}

	// erase element
	void erase(myiterator iter);

};

template<typename item_type> myvector<item_type>::myvector(myvector& storage)
{
	_size = storage._size;
	_memory = storage._memory;
	if (_size)
	{
		_items = new item_type[_2pow(_memory)];
		for (int i = 0; i < _size; i++)
			_items[i] = storage._items[i];
	}
	else _items = 0;
}

template<typename item_type> myvector<item_type>::~myvector()
{
	if (_items)	delete[] _items;
}

template<typename item_type> item_type& myvector<item_type>::operator[](unsigned num) const
{
	return _items[num];
}

template<typename item_type> void myvector<item_type>::clear()
{
	if (_items)
	{
		_size = 0;
		_memory = 0;
		delete[] _items;
		_items = 0;
	}
}

template<typename item_type> void myvector<item_type>::erase(myiterator iter)
{
	if (iter.valid() && _items)
	{
		// copy old elements to new
		item_type* temp = new item_type[_2pow(_memory)];
		// myiterator for new vector
		myiterator j(temp);
		// copy
		for (myiterator i(_items); i != this->end(); i++)
		{
			if (i != iter)
			{
				*j = *i;
				j++;
			}
		}
		// delete old
		_size--;
		delete[] _items;

		_items = temp;
		// set iter as invalid
		iter = 0;
	}
}

template<typename item_type> void myvector<item_type>::operator=(const myvector& storage)
{
	if (_items) delete[] _items;
	_items = new item_type[_2pow(storage._memory)];
	for (int i = 0; i < storage._size; i++)
		_items[i] = storage._items[i];
	_size = storage._size;
	_memory = storage._memory;
}

template<typename item_type> item_type& myvector<item_type>::at(unsigned num) const
{
	if (num >= _size) throw std::out_of_range("myvector::at");
	return _items[num];
}

template<typename item_type> void myvector<item_type>::push_back(const item_type& item)
{
	if (_items == 0)
	{
		_items = new item_type(item);
		_size = 1;
		_memory = 0;
	}
	else
	{		
		if (_size == _2pow(_memory))
		{
			_memory++;
			item_type *newitems = new item_type[_2pow(_memory)];//temp
			for (unsigned i = 0; i < _size; i++)
				newitems[i] = _items[i];
			delete[] _items;
			_items = newitems;
		}
		_items[_size] = item;
		_size++;
	}
}

#endif // MYVECTOR_H