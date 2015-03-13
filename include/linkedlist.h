#include "storages.h"
#include <stdexcept>

linkedlist::cell *_curcell;
linkedlist::cell *_curcell1;
linkedlist::cell *_curcell2;

class linkedlist{
	cell *_firstcell;
	cell *_lastcell;
	unsigned _size;
	
public:
	struct cell{
		Point data;
		cell *next;
	};
	linkedlist(){ _firstcell =  0;_lastcell = 0;_curcell = 0;_size = 0;};
	~linkedlist(){
		if (_firstcell){
			 _curcell = _firstcell;
			do{
				cell *cc = _curcell->next;
				delete _curcell;
				_curcell = cc;
			}
			while (_curcell );
		}
		
	}
	void add(const Point&);
	Point &operator[](unsigned);
	unsigned size() const{return _size;};

	cell* getFirst();


	Point & getCurrent() { if ( !_curcell) throw std::out_of_range("No current elem"); return _curcell->data; };
	void moveNext(){if (_curcell->next) _curcell = _curcell->next;};
	void rewind() {_curcell = _firstcell;};
	bool canMoveNext(){
		if (_curcell->next) return true;
		return false;
	}


};