#ifndef STORAGE_H
#define STORAGE_H
struct point {
	double x, y;
};
struct section {
	point a, b;
};
template<typename Item> class DynArray
{
public:
	DynArray();
	//Distructor
	~DynArray();
	//Add element
	void add(Item);
	//Get element
	Item get(int num);
	//Delete element
	void del(int num);
	//Value
	void value(int num1, int num2);
	//Size
	int size();
	template<typename Item> class Viewer{
		typename DynArray::Item*_cur;
		typename DynArray::_item*_items;
		unsigned _count;
	public:
		Viewer() {
			*_cur = 0;
			*_items = 0;
			_count = 0;
		}
		Viewer(DynArray<Item> s) {
			_items = s._items;
		}
		void MoveNext() {
			if (_count + 1 < _size) {
				++count;
				_cur = _items[count];
			}
			else
				throw std::invalid_argument("Bad Index");
		}
		bool CanMoveNext() {
			if (_count + 1 < _size) true;
			else false;
		}
		void Return() {
			count = 0;
		}
	};
	private:
		Item*_items;
		int _size;
};
template<typename Item> DynArray<Item>::DynArray()
{
	_items = 0;
	_size = 0;
}
template<typename Item> DynArray<Item>::~DynArray() {
	if (_items)
		delete[] _items;
}
template<typename Item> void DynArray<Item>::add(Item s) {
	if (_size == 0) {
		_items = new Item;
		*_items = s;
		++_size;
	}
	else {
		Item*newItem = new Item[_size + 1];
		for (unsigned i = 0; i < _size; ++i)
			newItem[i] = _items[i];
		newItem[_size] = s;
		delete[]_items;
		_items = newItem;
		++_size;
	}
}
template<typename Item> void DynArray<Item>::del(int num) {
	if (num == _size - 1) {
		Item*newItem = new Item[_size - 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newItem[i] = _items[i];
		delete[] _items;
		_items = newItem;
		--_size;
	}
	else {
		Item*newItem = new Item[_size - 1];
		for (unsigned i = num; i < _size - 1; ++i)
			_items[i] = _items[i + 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newItem[i] = _items[i];
		delete[] _items;
		_items = newItem;
		--_size;
	}
}
template<typename Item> Item DynArray<Item>::get(int num) {
	if (num >= _size)
		throw std::invalid_argument("Nope");
	return _items[num];
}
template<typename Item> int DynArray<Item>::size() {
	return _size;
}
/*template<typename Item> void DynArray<Item>::value(int num1, int num2) {
	_items[num2].b.x = _items[num2].a.x + (_items[num1].b.x - _items[num1].a.x);
	_items[num2].a.y = _items[num2].b.y - (_items[num1].b.y - _items[num1].a.y);
}*/
#endif STORAGE_H