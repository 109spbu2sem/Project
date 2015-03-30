
#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
struct point {  
	double x, y;
};
struct segment { 
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
template<typename Item> Item LinkedList<Item>::get(unsigned i) { //посылем в функцию номер(кол-во раз сколько мы будем 
	//nextать элементы списка начина€ с первого так как мы можем только так "стрелочку перемещать") 
	if (i > _size) // если больше размера то выдаст то что в скобках(св€зь c catch с мейне)
		throw std::invalid_argument("Bad index");
	_CurrentCell = _FirstCell; //стрелочку на первый
	if (i == 1) //отдельно если 1 элемент добавлен
		return _CurrentCell->data; //возвращаем координаты(ах да -> значит тоже самое что и ".*" просто так удобней(как хочешь))
	for (unsigned j = 0; j < i - 1; ++j) { //некстаем до нужного элемента который хотим получить
		_CurrentCell = _CurrentCell->next;
	}
	return _CurrentCell->data;
}
template<typename Item> void LinkedList<Item>::del(int i) { //сам написал этой функции не было на паре (какой € молодец)
	if (i > _size) //вспоминаем
		throw std::invalid_argument("Bad index");
	_CurrentCell = _FirstCell; //€ уже говорил дл€ чего
	//if (i == 1) { //отдельно дл€ случа€ удалени€ первого элемента
		//_FirstCell = _FirstCell->next; //естессна первый удалим значит первый это уже второй
		//delete[] _CurrentCell; // удал€ем первый наконец
		//--_size; //ну блин
	//	return; // чтобы функци€ дальше не пошла работать
	//}
	for (int j = 0; j < i - 2; ++j) { //некстаем до нужного элемента(с циклом намудрил но работает правильно)
		_CurrentCell = _CurrentCell->next;
	}
	cell*newcur = new cell; //выдел€ем пам€ть 
	newcur = _CurrentCell->next->next; // нуууу вроде пон€тно типа ссылаюсь через один элемент
	//(ссылаюсь на следующий в котором ссылаюсь на следующий(вот такой вот парадокс(хз подход€щее ли слово(ой, все))))
	delete[] _CurrentCell->next; //а да € дохожу тем циклом не до нужной €чейки а типа до предыдущей
	//(т.е. мне следующую надо удалить) удал€ю
	_CurrentCell->next = newcur; //теперь присваиваю той которую удалил на через следующий(ну блин сложно объ€снить)
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