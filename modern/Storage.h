#ifndef STORAGES_H
#define STORAGES_H

struct Point
{
	double x;
	double y;
};

struct Segment
{
	Point a; // begin
	Point b; // direction
};

// points
template<typename Item> class storage
{

private:
	Item *_items;
	int _size;

public:
	// constructor
	storage()
	{
		_items = 0;
		_size = 0;
	};
	// distructor
	~storage()
	{
		if (_items)
			delete[] _items;
	};

	// Add element
	void add(Item);
	// Get element
	Item get(int num);
	// Delete element
	void del(int num);
	// Value 
	void value(int num1, int num2);
	// Size 
	int size();
};

template<typename Item> void storage<Item>::add(Item p)
{
	if (_size == 0)
	{
		_items = new Item;
		*_items = p;
		++_size;
	}

	else
	{
		Item*newItem = new Item[_size + 1];
		for (int i = 0; i < _size; i++)
		{
			newItem[i] = _items[i];
		}
		newItem[_size] = p;
		delete[] _items;
		_items = newItem;
		++_size;
	}
}

template<typename Item> void storage<Item>::del(int num)
{
	if (num == _size - 1)
	{
		Item*newItem = new Item[_size - 1];
		for (unsigned i = 0; i < _size - 1; i++)
			newItem[i] = _items[i];
		delete[] _items;
		_items = newItem;
		--_size;
	}
	else
	{
		Item*newItem = new Item[_size - 1];
		for (unsigned i = num; i < _size - 1; i++)
			_items[i] = _items[i + 1];
		for (unsigned i = 0; i < _size - 1; i++)
			newItem[i] = _items[i];
		delete[] _items;
		_items = newItem;
		--_size;
	}
}

template<typename Item> Item storage<Item>::get(int num)
{
	if (num >= _size)
		throw std::invalid_argument("Nope");
	return _items[num];
}

template<typename Item> int storage<Item>::size()
{
	return _size;
}

template<typename Item> void storage<Item>::value(int num1, int num2)
{
	_items[num2].b.x = _items[num2].a.x + (_items[num1].b.x - _items[num1].a.x);
	_items[num2].a.y = _items[num2].b.y - (_items[num1].b.y - _items[num1].a.y);
}

#endif