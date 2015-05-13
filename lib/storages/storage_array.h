#ifndef STORAGE_ARRAY_H
#define STORAGE_ARRAY_H
#include <stdexcept>
#include <iostream>

template<typename Item> class ArrayViewer;

//-----------------------------------------------------------------------
//----------------------------Array-------------------------------------
//-----------------------------------------------------------------------
template<typename Item> class Storage_Array
{
private:
	Item *_items;
	unsigned _size;
	unsigned _memory;


	unsigned To2(unsigned b)
	{
		return 1 << b;
	}
public:
	friend class ArrayViewer < Item > ;
	// constructor
	Storage_Array(void)
	{
		_items = 0;
		_size = 0;
		_memory = 0;
	};
	// copying constructor
	Storage_Array(const Storage_Array &storage)
	{
		_size = storage._size;
		_memory = storage._memory;
		if (_size)
		{
			_items = new Item[To2(_memory)];
			for (int i = 0; i < _size; i++)
				_items[i] = storage._items[i];
		}
		else _items = 0;
	}
	// destructor
	~Storage_Array(void)
	{
		if (_items)	delete[] _items;
	};

	Item* getPointer(unsigned num);
	/// we can work with storage as an array
	Item& operator[] (unsigned num);
	/// we can produce copy of storage
	void operator= (const Storage_Array &storage);
	/// add elem
	Item* add(const Item&);
	// get _size
	unsigned size() const
	{
		return _size;
	}
	// delete all cells in array
	void clear()
	{
		if (_items)
		{
			_size = 0;
			_memory = 0;
			delete[] _items;
		}
	}
	// get pointer to first cell of array
	ArrayViewer<Item> getStartingViewer()
	{
		ArrayViewer<Item> v(*this);
		return v;
	};
};

template<typename Item> Item& Storage_Array<Item>::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items[num];
}

template<typename Item> void Storage_Array<Item>::operator=(const Storage_Array &storage)
{
	if (_items) delete[] _items;
	_items = new Item[To2(storage._memory)];
	for (int i = 0; i < storage._size; i++)
		_items[i] = storage._items[i];
	_size = storage._size;
	_memory = storage._memory;
}

template<typename Item> Item* Storage_Array<Item>::getPointer(unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items + num;
}

template<typename Item> Item* Storage_Array<Item>::add(const Item& item)
{
	//if storage is empty
	if (_items == 0)
	{
		_items = new Item(item);
		_size = 1;
		_memory = 1;
		return _items;
	}
	else
	{
		_size++;
		if (_size == To2(_memory))
		{
			_memory++;
			//copy old
			Item *newitems = new Item[To2(_memory)];//temp
			for (unsigned i = 0; i < _size - 1; i++)
				newitems[i] = _items[i];
			//erase old
			delete[] _items;
			_items = newitems;
		}
		//add new
		_items[_size - 1] = item;
		return _items + _size - 1;
	}
}

//-----------------------------------------------------------------------
//-----------------------------Viewer------------------------------------
//-----------------------------------------------------------------------

template<typename Item> class ArrayViewer
{
private:
	Item *_current;
	Item *_limit;
public:
	ArrayViewer() //---------
	{
		_current = 0;
		_limit = 0;
	}
	ArrayViewer(Storage_Array<Item>& l) //---------
	{
		_current = l._items;
		_limit = l._items + l.size();
	}
	Item& getValue() //---------
	{
		if (_current) return *_current; 
		throw std::runtime_error("No such item"); 
	};
	void moveNext() //---------
	{
		if (_current) _current++;
	};
	bool canMoveNext() //---------
	{
		if (_current < _limit) return true; return false;
	};
};

#endif // STORAGE_ARRAY_H
