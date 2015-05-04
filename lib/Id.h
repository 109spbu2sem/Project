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
	unsigned getID() const
	{
		return _myid;
	}
	void setID(unsigned id)
	{
		_myid = id;
	}
};

#endif