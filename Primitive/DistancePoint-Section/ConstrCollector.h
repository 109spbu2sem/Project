#ifndef _CONSTRCOLLECTOR_H
#define _CONSTRCOLLECTOR_H
#include "global.h"
#include "storage.h"

class ConstrCollector:public IConstraint
{
public:
	ConstrCollector(){};
	void addConstraint(IConstraint *c)
	{
		if (c) _storage.add(c);
	}
	virtual double error()
	{
		double err = 0;
		for (unsigned k = 0;k< _storage.size();++k)
			err += _storage[k]->error();
		return err;
	};
	virtual double diff(double *par)
	{
		double res = 0;
		for (unsigned k = 0;k< _storage.size();++k)
			res += _storage[k]->diff(par);
		return res;
	}

private:
	storage_template<IConstraint*> _storage;
};
#endif