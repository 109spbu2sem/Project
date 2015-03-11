#ifndef _STORAGE_H
#define _STORAGE_H
template<typename Item> class storage_template
{

	private:
		Item *_items;
		unsigned _size;
	public:
		//constructor
		storage_template(void)
		{
			_items = 0;
			_size = 0;
		};

		// copying constr
		storage_template(const storage_template &s)
		{
			_items = 0;
			_size = s._size;
			if (_size)
			{
			_items = new Item[s._size()];
			for (unsigned k = 0; k<s._size; ++k)
				_items[k] = s._items[k];
			}
		}

		/*
		// copyTIPA=)
		storage_template(const storage_template &s)
		{
			_items = new Item[s._size()];
			for (unsigned k = 0; k < s._size; k++)
				_items[k] = s._items[k];
			_size = s._size;
		}
		*/
		//destructor
		~storage_template(void)
		{
			if (_items)	delete[] _items;
		};
		///we can work with storage as an array
		Item& operator[] (unsigned num);
		
		///we can produce copies of storage
		void operator = (const storage_template &s);

		/*
		// copy spisok
		void operator+++ (const storage_template &s);
		*/

		///add elem
		void add(const Item&p);
		//get _size
		unsigned size() const
		{
			return _size;
		}
};

template<typename Item> void storage_template<Item>::add(const Item&p) //
{
	//if storage is empty
	if (_items == 0)
	{
		_items = new Item(p);
		/*(*_items).x = p.x;
		(*_items).y = p.y;*/
		_size = 1;
		return;
	}
	else
	{
		_size++;
		//copy old
		Item *newitems = new Item[_size]; //temp
		for (unsigned i = 0; i < _size - 1; i++)
			newitems[i] = _items[i];
		//erase old
		delete[] _items;
		//add new
		newitems[_size - 1] = p;
		_items = newitems;
		return;
	}
	return;
}

template<typename Item> Item&storage_template<Item>::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items[num];
}

template<typename Item> void storage_template<Item>::operator=(const storage_template &s)
{
	if (_items) delete[] _items;
	_items = new Item[s._size()];
	for (unsigned k = 0; k<s._size; ++k)
		_items[k] = s._items[k];
	_size = s._size;
}

#endif