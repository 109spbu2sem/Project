#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "..\global.h"
#include "..\storage_array.h"

// type = 0

class ConstraintCollector :public IConstraint
{

private:
	Storage_Array<IConstraint*> _storage;
public:
	ConstraintCollector() {};
	void addConstraint(IConstraint *c)
	{
		if (c) _storage.add(c);
	}
	virtual double error()
	{
		double err = 0;
		for (unsigned k = 0; k< _storage.size(); ++k)
			err += _storage[k]->error();
		return err;
	};
	virtual double diff(double *par)
	{
		double res = 0;
		for (unsigned k = 0; k< _storage.size(); ++k)
			res += _storage[k]->diff(par);
		return res;
	}
	virtual unsigned type()
	{
		return 0;
	}
};
#endif