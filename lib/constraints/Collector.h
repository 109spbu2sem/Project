#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "../global.h"
#include "../storages/myvector.h"

// type CONSTR_COLLECTOR

class ConstraintCollector :public IConstraint
{

private:
	myvector<IConstraint*> _storage;
public:
	ConstraintCollector()
	{
	};
	virtual ~ConstraintCollector()
	{

	}
	void addConstraint(IConstraint *c)
	{
		if (c) _storage.push_back(c);
	}
	virtual double error()
	{
		double err = 0;
		for (unsigned k = 0; k < _storage.size(); ++k)
			err += _storage[k]->error();
		return err;
	};
	virtual double diff(double *par)
	{
		double res = 0;
		for (unsigned k = 0; k < _storage.size(); ++k)
			res += _storage[k]->diff(par);
		return res;
	}
	virtual CONSTR_TYPE type() const
	{
		return CONSTR_COLLECTOR;
	}
	virtual double value() const
	{
		return NAN;
	}
};
#endif