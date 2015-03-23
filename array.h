#include <cmath>

struct Point
{
	double x;
	double y;
};
struct Sect
{
	Point A;
	Point B;
	double length(){
		double a = (A.x - B.x)*(A.x - B.x);
		double b = (A.y - B.y)*(A.y - B.y);
		return sqrt(a + b);
	}
};

template <typename Item> class Darray
{
private:
	unsigned _size;
	Item *_items;
public:
	//constructors and destructors
	Darray(void)
	{
		_items = 0;
		_size = 0;
	};
	Darray(const Darray &s)
	{
		_size = s._size;
		if (_size)
		{
			_items = new Item[s.size()];
			for (int i = 0; i < s.size(); i++)
				_items[i] = s._items[i];
		}
		else _items = 0;
	};
	~Darray(void)
	{
		if (_items) delete[]_items;
	}

	//operators
	Item&operator[](unsigned num);
	void operator=(const Darray &A);
	//ads methods
	void add(Item I);
	unsigned size()const
	{
		return _size;
	}
	void del(unsigned num);
	
};

//methods

template<typename Item> Item& Darray<Item>::operator[](unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items[num];
}
template<typename Item> void Darray<Item>::operator=(const Darray &A)
{
	if (_items) delete[] _items;
	_items = new Item[A._size];
	for (int i = 0; i < A._size; i++)
		_items[i] = A._items[i];
	_size = A._size;
}
//
template<typename Item> void Darray<Item>::add(Item I)
{
	//if storage is empty
	if (_items == 0)
	{
		_items = new Item(I);
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
		newitems[_size - 1] = I;
		_items = newitems;
		return;
	}
	return;
}
template<typename Item> void Darray<Item>::del(unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	//copy old
	Item *newitems = new Item[_size];//temp
	for (unsigned i = 0; i < num; i++)
		newitems[i] = _items[i];
	for (unsigned i = num; i < _size - 1; i++)
		newitems[i] = _items[i-1];
	//erase old
	delete[] _items;

	_items = newitems;
	return;


}




