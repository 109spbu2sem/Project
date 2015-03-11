#include "linkedlist.h"
#include <stdexcept>

void linkedlist::add(const Point& p)
{
	if(_firstcell == 0)
	{
		_firstcell = new cell;
		(*_firstcell).data = p;
		(*_firstcell).next = 0;
		_firstcell ->next=0;
		++ _size;
	}
	else 
	{
		cell *newcell = new cell;
		newcell -> data = p;
		newcell -> next = 0;
		// св€жем с предыдущей €чейкой
		//_lastcell -> next = newcell; //- надо убрать
		_lastcell = newcell;
	}
	++_size;
}

Point &linkedlist::operator[](unsigned pos)
{
	if (pos >= _size) throw std::invalid_argument("bad index");
	cell *current = _firstcell;
	unsigned counter = 0;
	while (++counter != pos && current && current-> next)
	{
		current = current->next;
	}
	return current->data;
}