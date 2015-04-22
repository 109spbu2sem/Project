#ifndef ID_H
#define ID_H

class ID
{
private:
	unsigned _myid;
public:
	ID()
	{
		//_myid = generateID();
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

#endif