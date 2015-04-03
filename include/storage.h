#ifndef _STORAGE_H
#define _STORAGE_H



template<typename Item> class storage_template{
private:
	unsigned _size;
	Item **_curItems;
	unsigned _size;
public:
	class Viewer{
	Item *_cur;
	Item *_limit;
	
	public:
	Viewer(){_cur=0;_limit=0;}
	Viewer(storage_template<Item> &s){
		_cur=s._items;
		_limit=s._items+s._size();
	}

	Item& getValue(){if(_cur) return *_cur;
	throw std::runtime_error("No such item");};
	void moveNext(){if (_cur && cer<_limit;)_cur++;}
	bool canMoveNext(){	if (_cur<_limit) return true;return false;};
	
	};
	//constructor
	storage_template(void){
		_items = 0;
		_size = 0;
	};
	// copying constr
	storage_template(const storage_template &s){
		_items = 0;
		_size = s._size;
		if (_size){
			_items = new Item[s._size];
			for (unsigned k = 0;k<s._size;++k)
				_items[k] = s._items[k];
		}		
	}
	//destructor
	~storage_template(void){
		if (_items) delete[] _items;
	};
	///we can work with storage as an array
	Item& operator[] (unsigned num);
	///we can produce copies of storage
	void operator= (const storage_template &s);
	///add elem
	void add(const Item &);
	//get _size
	unsigned size() const{
		return _size;
	}

	Viewer getStartingViewer(){
		return Viewer(*this);		
	};


};
template<typename Item> void storage_template<Item>::add(const Item& p)
{
	//if storage is empty
	if (_items == 0)
	{
		_items = new Item(p);
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
		newitems[_size - 1] = p;
		_items = newitems;
		return;
	}
	return;
}

template<typename Item> Item& storage_template<Item>::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _items[num];
}
template<typename Item> void storage_template<Item>::operator=(const storage_template &s){
	if (_items) delete[] _items;
	_items = new Item[s._size];
	for (unsigned k = 0;k<s._size;++k)
		_items[k] = s._items[k];
	_size = s._size;
}
#endif