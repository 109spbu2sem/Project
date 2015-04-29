#ifndef QUEUE_H
#define QUEUE_H

#include <cmath>

//------------------------------------------------------------------------
//----------------------------------Queue---------------------------------
//------------------------------------------------------------------------
template<typename Item> class SmallQueue
{
private:
	struct Cell
	{
		Item data;
		Cell *next;
	};
	Cell *_in;
	Cell *_out;
	unsigned _size;
public:
	SmallQueue()
	{
		_in = 0;
		_out = 0;
		_size = 0;
		return;
	}
	~SmallQueue()
	{
		if (_out)
		{
			Cell* _current = _out;
			do
			{
				Cell *cc = _current->next;
				delete _current;
				_current = cc;
			} while (_current);
		}
		return;
	}
	void push(const Item&);
	void pull();
	Item& top() const;
	unsigned size() const
	{
		return _size;
	}
	bool empty() const
	{
		if (_size) return false; return true;
	}
};

template<typename Item> Item& SmallQueue<Item>::top() const
{
	return _out->data;
}

template<typename Item> void SmallQueue<Item>::push(const Item& newitem)
{
	if (_in)
	{
		Cell* tempcell = new Cell;
		_in->next = tempcell;
		tempcell->data = newitem;
		tempcell->next = 0;
		_size++;
		_in = tempcell;
	}
	else
	{
		_in = new Cell;
		_out = _in;
		_in->data = newitem;
		_in->next = 0;
		_size = 1;
	}
}

template<typename Item> void SmallQueue<Item>::pull()
{
	if (_out)
	{
		Cell* temp = _out->next;
		delete _out;
		_out = temp;
	}
}


#endif // QUEUE_H
