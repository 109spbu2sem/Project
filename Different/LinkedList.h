#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct point {
	double x, y;
};
struct section {
	point a, b;
};
template <typename Item> class LinkedList
{
	struct cell{
		Item data;
		cell*next;
	};
	cell*_FirstCell;
	cell*_LastCell;
	cell*_CurrentCell;
	int _size;
public:
	LinkedList() {
		_FirstCell = 0;
		_LastCell = 0;
		_CurrentCell = 0;
		_size = 0;
	};

	~LinkedList() {
		_CurrentCell = _FirstCell;
		while (_CurrentCell) {
			cell*c = _CurrentCell->next;
			delete[] _CurrentCell;
			_CurrentCell = c;
		}
	};
	void add(Item);
	Item get(unsigned);
	void del(int);
	int size();
	void MoveNext();
	void Rewind();
};
template<typename Item> void LinkedList<Item>::add(Item a) {
	if (_size == 0) {
		_FirstCell = new cell;
		_FirstCell->data = a;
		_FirstCell->next = 0;
		_LastCell = _FirstCell;
		++_size;
	}
	else {
		_CurrentCell = new cell;
		_CurrentCell->data = a;
		_CurrentCell->next = 0;
		_LastCell->next = _CurrentCell;
		_LastCell = _CurrentCell;
		++_size;
	}
}
template<typename Item> Item LinkedList<Item>::get(unsigned i) {
	if (i > _size)
		throw std::invalid_argument("Bad index");
	_CurrentCell = _FirstCell;
	if (i == 1)
		return _CurrentCell->data;
	for (unsigned j = 0; j < i-1; ++j) {
		_CurrentCell = _CurrentCell->next;
	}
	return _CurrentCell->data;
}
template<typename Item> void LinkedList<Item>::del(int i) {
	if (i > _size)
		throw std::invalid_argument("Bad index");
	_CurrentCell = _FirstCell;
	if (i == 1) {
		_FirstCell = _FirstCell->next;
		delete[] _CurrentCell;
		--_size;
		return;
	}
	for (int j = 0; j < i - 2; ++j) {
		_CurrentCell = _CurrentCell->next;
	}
	cell*newcur = new cell;
	newcur = _CurrentCell->next->next;
	delete[] _CurrentCell->next;
	_CurrentCell->next = newcur;
	--_size;
}
template<typename Item> int LinkedList<Item>::size() {
	return _size;
}
template<typename Item> void LinkedList<Item>::MoveNext() {
	if (_CurrentCell->next)
		_CurrentCell = _CurrentCell->next;
}
template<typename Item> void LinkedList<Item>::Rewind() {
	_CurrentCell = _FirstCell;
}
#endif LINKEDLIST_H

