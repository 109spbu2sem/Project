template <typename Item> class LinkedList
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
	//constructors and destructors
	LinkedList(void)
	{
		_first = 0;
		_last = 0;
		_current = 0;
		_size = 0;
		return;
	}
	LinkedList(LinkedList &storage)
	{
		if (storage._first != 0)
		{
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
	~LinkedList(void)
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

	//ads methods and operators
	void add(const Item &I);

	bool canMoveNext()
	{
		if (_current->next) return false;
		return true;
	}

	Item get()
	{ 
		return _current->data; 
	}

	void rewind()
	{
		_current = _first;
		return;
	}

	void move_next()
	{
		if (_current->next)
			_current = _current->next;
		return;
	}

	//void remove();

	void clear();
};

template<typename Item> void LinkedList<Item>::add(const Item& I)
{
	if (_first)
	{
		Cell *c = new Cell;
		_last->next = c;
		_last = c;
		_last->data = I;
		_last->next = 0;
		_size++;
		return;
	}
	else
	{
		_last = new Cell;
		_first = _last;
		_last->next = 0;
		_first->next = 0;
		_first->data = I;
		_last->data = I;
		_current = _first;
		_size = 1;
		return;
	}
	return;
}

template<typename Item> void LinkedList<Item>::clear()
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
	_size = 0;
	_first = 0;
	_last=0;
	return;
}
