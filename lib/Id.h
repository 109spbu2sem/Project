#ifndef ID_H
#define ID_H

class ID
{
private:
	unsigned _myid;
public:
	ID()
	{
		_myid = 0;
	}
	ID(unsigned id)
	{
		_myid = id;
	}
	unsigned getID()
	{
		return _myid;
	}
};


class IDgenerator
{
private:
	unsigned _last;
public:
	IDgenerator()
	{
		_last = 0;
	}
	ID generateID()
	{
		_last++;
		return ID(_last);
	}
};

#endif