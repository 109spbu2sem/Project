#include "storages.h"

class linkedlist
{
	struct cell
	{
		Point data;
		cell *next;
	};
	cell *_firstcell;
	unsigned _size;
public:
	linkedlist(){ _firstcell = 0; _size = 0;};
	void add(const Point&);
	Point &operator[](unsigned);
	unsigned size() const;
};
