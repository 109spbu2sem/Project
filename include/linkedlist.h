#include "storages.h"
#include <stdexcept>


class linkedlist{
	struct cell{
		Point data;
		cell *next;
	};
	cell *_firstcell;
	cell *_lastcell;
	unsigned _size;	
public:
	class Viewer{
		linkedlist::cell *_cur;		
	public:		
		Viewer(){_cur = 0;}
		Viewer(linkedlist&l){
			_cur = l._firstcell;			
		}

		Point & getValue(){if (_cur) return _cur->data;
		throw std::runtime_error("No such point");};
		void moveNext(){if (_cur) _cur = _cur->next;};
		bool canMoveNext(){if ( _cur ) return true; return false;};
	};


	friend class Viewer;
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
	void add(const Point&);
	unsigned size() const{return _size;};

	Viewer getStartingViewer(){
		Viewer v(*this);		
		return v;
	};
};

