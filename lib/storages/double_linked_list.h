#ifndef STORAGE_LIST_H
#define STORAGE_LIST_H

#include <cmath>

template<typename Item> class DoubleViewer;

//------------------------------------------------------------------------
//----------------------------------LIST---------------------------------
//------------------------------------------------------------------------
template<typename Item> class DoubleLiknedList
{
private:
	struct Cell
	{
		Item data;
		Cell *next;
		Cell *prev;
	};
	Cell *_first;
	Cell *_last;
	Cell *_current;
	unsigned _size;
public:
	friend class DoubleViewer < Item >;
	//constructor
	DoubleLiknedList(void)
	{
		_first = 0;
		_last = 0;
		_current = 0;
		_size = 0;
		return;
	}
	//copying constructor
	DoubleLiknedList(const DoubleLiknedList &storage)
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
	~DoubleLiknedList(void)
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
	Item* add(const Item&);
	//set _current as _first
	void rewind()
	{
		_current = _first;
		return;
	}
	//check
	bool canMovePrev()
	{
		if (_current->prev) return false;
		return true;
	}
	bool canMoveNext()
	{
		if (_current->next) return false;
		return true;
	}
	void movePrev()
	{
		if (_current->prev)
			_current = _current->prev;
		return;
	}
	//move _current to next
	void moveNext()
	{
		if (_current->next)
			_current = _current->next;
		return;
	}
	//removes _current item
	void remove(DoubleViewer<Item>*);
	void clear();
	unsigned size() const
	{
		return _size;
	}
	// get pointer to first cell of list
	ListViewer<Item> getStartingViewer()
	{
		ListViewer<Item> v(*this);
		return v;
	};
};

template<typename Item> Item* DoubleLiknedList<Item>::add(const Item &item)
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
		_current = _first;
		_size = 1;
		return &(_last->data);
	}
}

//removes item
template<typename Item> void DoubleLiknedList<Item>::remove(DoubleViewer<Item>* viewer)
{
	if (viewer->_current)
	{
		Cell* prev;
		Cell* next;
		prev = viewer->_current->prev;
		next = viewer->_current->next;
		if (prev) prev->next = next;
		if (next) next->prev = prev;
		delete viewer->_current;
		viewer->_current = next;
		_size--;
	}
	return;
}
//clears storage
template<typename Item> void DoubleLiknedList<Item>::clear()
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
//-----------------------------Viewer------------------------------------
//-----------------------------------------------------------------------

template<typename Item> class DoubleViewer
{
private:
	typename DoubleLiknedList<Item>::Cell *_current;
public:
	friend class DoubleLiknedList < Item > ;
	DoubleViewer()
	{
		_current = 0;
	}
	DoubleViewer(DoubleLiknedList<Item>& l)
	{
		_current = l._first;
	}
	Item& getValue() { if (_current) return _current->data; throw std::runtime_error("No such item"); }
	void moveNext() { if (_current) _current = _current->next; }
	void movePrev() { if (_current) _current = _current->prev; }
	bool canMoveNext()
	{
		if (_current) return true; return false;
	}
	bool canMovePrev()
	{
		if (_current) return true; return false;
	}
	void remove()
	{
		if (_current)
		{
			typename DoubleLiknedList<Item>::Cell* prev;
			typename DoubleLiknedList<Item>::Cell* next;
			prev = _current->prev;
			next = _current->next;
			if (prev) prev->next = next;
			if (next) next->prev = prev;
			delete _current;
			_current = next;
		}
	}
};

#endif // STORAGE_LIST_H
