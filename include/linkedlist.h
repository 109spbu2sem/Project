#include "storages.h"
#include <stdexcept>



class linkedlist
{
public:

	struct cell
	{
		Point data;
		cell *next;
	};

	cell*_firstcell;
	cell*_lastcell;
	cell*_curcell;
	unsigned _size;

	linkedlist() // Conctructor
	{ 
		_firstcell = 0;
		_lastcell = 0;
		_curcell = 0;
		_size = 0;
	};
	~linkedlist() // Destructor
	{
		if (_firstcell)
		{
			_curcell = _firstcell;
			do
			{
				cell *cc = _curcell->next;
				delete _curcell;
				_curcell = cc;
			} while (_curcell);
		}
	}

	void add(const Point&);
	Point &operator[](unsigned);
	unsigned size() const{return _size;};

	cell* getFirst();

	Point & getCurrent() 
	{ 
		if (!_curcell) 
			throw std::out_of_range("No current elem");
		return _curcell->data; 
	};

	void moveNext()
	{
		if (_curcell->next) 
			_curcell = _curcell->next;
	};

	void rewind() 
	{
		_curcell = _firstcell;
	};

	bool canMoveNext()
	{
		if (_curcell->next)
			return true;
		return false;
	}
};
