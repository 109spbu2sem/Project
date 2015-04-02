#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
#include "storages.h"
#include <stdexcept>
// -----------------------list---------------------------
template <typename Item> class linkedlist
{
private:
	struct Cell
	{
		Item data;
		Cell *next;
	};
	Cell *_firstcell;
	Cell *_lastcell;
	unsigned _size;
	Cell *_curcell;
public:
	//constructor
	linkedlist()
	{
		_firstcell = 0;
		_lastcell = 0;
		_curcell = 0;
		_size = 0;
	};
	//copying constructor
	linkedlist(const linkedlist &storage)
	{
		if (storage._firstcell != 0)//if not empty
		{
			//create first cell with storage's data
			_firstcell = new Cell;
			_firstcell->data = storage._firstcell->data;
			_firstcell->next = 0;
			_curcell = _firstcell;
			storage.rewind();
			storage.moveNext();
			//copy others cells
			while (storage._curcell)
			{
				Cell *p = new Cell;
				p->data = storage._curcell->data;
				_curcell->next = p;
				_curcell = _curcell->next;
				storage.moveNext();
			}
			_curcell->next = 0;
			_size = storage._size;
		}
		return;
	}
	//destructor
	~linkedlist()
	{
		if (_firstcell)
		{
			_curcell = _firstcell;
			do
			{
				Cell *cc = _curcell->next;
				delete _curcell;
				_curcell = cc;
			} while (_curcell);
			_size = 0;
			_firstcell = 0;
			_lastcell = 0;
		}
	}
	void add(const Item&);
	void remove_next();
	unsigned size() const;
	Item & getCurrent()// обращение к текущему
	{
		if (_curcell) return _curcell->data;
	}
	void moveNext()// перемещение к следующему элементу
	{
		if (_curcell->next) _curcell = _curcell->next;
	}
	void rewind()//возвращает текущий  элемеен к первому элементу в хранилище
	{
		_curcell = _firstcell;
	}
	bool canMoveNext() // возможность обращения к сл эл
	{
		if (_curcell->next) return true;
		return false;
	}

};
	template <typename Item> void linkedlist<Item>::add(const Item &item)
	{
		if (_firstcell == 0)
		{
			_firstcell = new Cell;
			_firstcell->data = item;
			_firstcell->next = 0;
			_lastcell = _firstcell;
			_curcell = _firstcell;
			_size = 1;
			return;
		}
		else
		{
			Cell *newcell = new Cell;
			// свяжем с предыдущей
			_lastcell->next = newcell;
			_lastcell = newcell;
			newcell->data = item;
			newcell->next = 0;
			size++;
		}
	};
	//removes next item
	template<typename Item> void linkedlist<Item>::remove_next()
	{
		if (_curcell->next)
		{
			Cell *temp = _curcell->next;
			_curcell->next = _curcell->next->next;
			delete temp;
			_size--;
		}
		return;
	}
#endif LINKEDLIST_H