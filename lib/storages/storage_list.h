#ifndef STORAGE_LIST_H
#define STORAGE_LIST_H
#include <stdexcept>
#include <cmath>

template<typename Item> class ListViewer;

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
	unsigned _size;
public:
	friend class ListViewer < Item > ;
	//constructor
	Storage_List(void)
	{
		_first = 0;
		_last = 0;
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
			Cell* _current = _first;
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
	//add element to storage
	Item* add(const Item&);
	//removes _current item
	void remove(ListViewer<Item>*);
	void clear();
	unsigned size() const
	{
		return _size;
	}
	//void delete(Storage_Array<Item>* s);
	// get pointer to first cell of list
	ListViewer<Item> getIterator()
	{
		ListViewer<Item> v(*this);
		return v;
	};
};

//template<typename Item> void Storage_List<Item>::delete(Storage_Array<Item>* s) {}

template<typename Item> Item* Storage_List<Item>::add(const Item &item)
{
	if (_first)//add new item
	{
		Cell *c = new Cell;
		_last->next = c;
		_last = c;
		_last->data = item;
		_last->next = 0;
		_size++;
		return &(_last->data);
	}
	else//create first item
	{
		_first = new Cell;
		_first->data = item;
		_first->next = 0;
		_last = _first;
		_size = 1;
		return &(_last->data);
	}
}

//removes next item
template<typename Item> void Storage_List<Item>::remove(ListViewer<Item>* viewer)
{
	Cell* _cur = _first;
	if (_cur == viewer->_current)
	{
		viewer->_current = _cur->next;
		_first = _cur->next;
		delete _cur;
		_size--;
		return;
	}
	while (_cur && _cur->next != viewer->_current)
	{
		_cur = _cur->next;
	}
	if (_cur)
	{
		if (_cur->next)
		{
			_cur->next = _cur->next->next;
			delete viewer->_current;
			viewer->_current = _cur->next;
		}
	}
	_size--;
	return;
}
//clears storage
template<typename Item> void Storage_List<Item>::clear()
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

//-----------------------------------------------------------------------
//-----------------------------Viewer------------------------------------
//-----------------------------------------------------------------------

template<typename Item> class ListViewer
{
private:
	typename Storage_List<Item>::Cell *_current;
public:
	friend class Storage_List < Item > ;
	ListViewer()
	{
		_current = 0;
	}
	ListViewer(Storage_List<Item>& l)
	{
		_current = l._first;
	}
	Item& getValue() { if (_current) return _current->data; throw std::out_of_range("No such item"); }
	void moveNext() { if (_current) _current = _current->next; }
	bool canMoveNext()
	{
		if (_current) return true; return false;
	}
};

#endif // STORAGE_LIST_H
