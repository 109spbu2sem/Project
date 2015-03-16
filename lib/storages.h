#ifndef STORAGES_H
#define STORAGES_H

#include <iostream>

//------------------------------------------------------------------------
//----------------------------------LIST---------------------------------
//------------------------------------------------------------------------
template<typename Item> class Storage_List
{
private:
	struct Cell
	{
		Item data;
		Cell *next;
	};
	Cell *_first;
	Cell *_last;
	Cell *_current;
	unsigned _size;
public:
	//constructor
	Storage_List(void)
	{
		_first = 0;
		_last = 0;
		_current = 0;
		_size = 0;
		return;
	}
	//copying constructor
	Storage_List(const Storage_List &storage)
	{
		if (storage._first != 0)//if not empty
		{
			//create first cell with storage's data
			_first = new Cell;
			_first->data = storage._first->data;
			_first->next = 0;
			_current = _first;
			storage.rewind();
			storage.move_next();
			//copy others cells
			while (storage._current)
			{
				Cell *p = new Cell;
				p->data = storage._current->data;
				_current->next = p;
				_current = _current->next;
				storage.move_next();
			}
			_current->next = 0;
			_size = storage._size;
		}
		return;
	}
	//destructor
	~Storage_List(void)
	{
		if (_first)
		{
			_current = _first;
			do
			{
				Cell *cc = _current->next;
				delete _current;
				_current = cc;
			} while (_current);
		}
		return;
	}
	Item get() { return _current->data; }
	//add element to storage
	void add(const Item&);
	//set _current as _first
	void rewind()
	{
		_current = _first;
		return;
	}
	//check
	bool canMove_next()
	{
		if (_current->next) return false;
		return true;
	}
	//move _current to next
	void move_next()
	{
		if (_current->next)
			_current = _current->next;
		return;
	}
	//removes _current item
	void remove_next();
	void clear();
	unsigned size() const
	{
		return _size;
	}
};

template<typename Item> void Storage_List<Item>::add(const Item &item)
{
	if (_first)//add new item
	{
		Cell *c = new Cell;
		_last->next = c;
		_last = c;
		_last->data = item;
		_last->next = 0;
		_size++;
		return;
	}
	else//create first item
	{
		_first = new Cell;
		_first->data = item;
		_first->next = 0;
		_last = _first;
		_current = _first;
		_size = 1;
		return;
	}
	return;
}

//removes next item
template<typename Item> void Storage_List<Item>::remove_next()
{
	if (_current->next)
	{
		Cell *temp = _current->next;
		_current->next = _current->next->next;
		delete temp;
		_size--;
	}
	return;
}
//clears storage
template<typename Item> void Storage_List<Item>::clear()
{
	if (_first)
	{
		_current = _first;
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
//-----------------------------------------------------------------------
//----------------------------Array-------------------------------------
//-----------------------------------------------------------------------
template<typename Item> class Storage_Array
{
private:
	Item *_items;
	unsigned _size;
public:
	//constructor
	Storage_Array(void)
	{
		_items = 0;
		_size = 0;
	};
	//copying constructor
	Storage_Array(const Storage_Array &s)
	{
		_size = s._size;
		if (_size)
		{
			_items = new Item[s.size()];
			for (int i = 0; i < s.size(); i++)
				_items[i] = s._items[i];
		}
		else _items = 0;
	}
	//destructor
	~Storage_Array(void)
	{
		if (_items) delete[] _items;
	};
	///we can work with storage as an array
	Item& operator[] (unsigned num);
	///we can produce copy of storage
	void operator= (const Storage_Array &storage);
	///add elem
	void add(const Item&);
	//get _size
	unsigned size() const
	{
		return _size;
	}
	void clear()
	{
		if (_items)
		{
			_size = 0;
			delete[] _items;
		}
	}
};

template<typename Item> Item& Storage_Array<Item>::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items[num];
}

template<typename Item> void Storage_Array<Item>::operator=(const Storage_Array &storage)
{
	if (_items) delete[] _items;
	_items = new Item[storage._size];
	for (int i = 0; i < storage._size; i++)
		_items[i] = storage._items[i];
	_size = storage._size;
}

template<typename Item> void Storage_Array<Item>::add(const Item& item)
{
	//if storage is empty
	if (_items == 0)
	{
		_items = new Item(item);
		_size = 1;
		return;
	}
	else
	{
		_size++;
		//copy old
		Item *newitems = new Item[_size];//temp
		for (unsigned i = 0; i < _size - 1; i++)
			newitems[i] = _items[i];
		//erase old
		delete[] _items;
		//add new
		newitems[_size - 1] = item;
		_items = newitems;
		return;
	}
	return;
}

#endif // STORAGES_H
