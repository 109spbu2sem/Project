#include "linkedlist.h"
#include <stdexcept>

void linkedlist::add(const Point&p){
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