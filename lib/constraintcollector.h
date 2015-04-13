#ifndef CONSTRAINTCOLLECTOR_H
#define CONSTRAINTCOLLECTOR_H

#include "global.h"
#include "storage_array.h"

class ConstraintCollector: public iConstraint
{
private:
	Storage_Array<iConstraint*> _storage;
public:
	ConstraintCollector()
	{
	}
	void add(iConstraint *c)
	{
		if (c) _storage.add(c);
	}
	virtual double error()
	{
		double res = 0;
		for (unsigned i = 0; i < _storage.size(); i++)
		{
			res += _storage[i]->error();
		}
		return res;
	}
	virtual double diff(double *par)
	{
		double res = 0;
		for (unsigned i = 0; i < _storage.size(); i++)
		{
			res += _storage[i]->diff(par);
		}
		return res;
	}
};

#endif CONSTRAINTCOLLECTOR_H
