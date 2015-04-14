#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stdexcept>

template<typename T> class linkedlist{
	struct cell{
		T data;
		cell *next;
	};
	cell *_firstcell;
	cell *_lastcell;
	unsigned _size;	
public:
	template<typename T> class Viewer{
		typename linkedlist<T>::cell *_cur;		
	public:		
		Viewer(){_cur = 0;}
		Viewer(linkedlist&l){
			_cur = l._firstcell;
		}
		T & getValue(){
			if (_cur) return _cur->data;
			throw std::runtime_error("Invalid viewer");
		};
		void moveNext(){
			if (_cur) _cur = _cur->next;			
		};
		bool canMoveNext(){
			if ( _cur ) return true; 
			return false;
		};
	};


	friend class Viewer<T>;
	linkedlist(){ _firstcell =  0;_lastcell = 0;_size = 0;};
	~linkedlist(){
		if (_firstcell){
			cell* _curcell = _firstcell;
			do{
				cell *cc = _curcell->next;
				delete _curcell;
				_curcell = cc;
			}
			while (_curcell );
		}

	}
	void add(const T&p){
		if (_firstcell == 0){
			_firstcell =  new cell;
			_firstcell->data = p;		
			_firstcell->next = 0;		
			_lastcell = _firstcell;
		}
		else{
			cell *newcell = new cell;
			newcell->data = p;
			newcell->next = 0;
			// св€жем с предыдущей €чейкой
			_lastcell->next = newcell;
			_lastcell = newcell;
		}
		++_size;
	}
	unsigned size() const{return _size;};
};

#endif