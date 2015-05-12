#ifndef CIRCLECONTACT_H
#define CIRCLECONTACT_H
#include "..\global.h"
#include <cmath>

// (c) Daria // type CONSTR_EXCONTACT CONSTR_INTCONTACT

class InternalContactCircle :public IConstraint
{
	double *_p1x, *_p1y, *_r1, *_p2x, *_p2y, *_r2;

public:
	InternalContactCircle(double *p1x, double *p1y, double *p2x, double *p2y, double *r1, double *r2)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_r1 = r1;
		_r2 = r2;
	}
	virtual ~InternalContactCircle()
	{

	}
	virtual double error()
	{
		return ((*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));

	};
	virtual double diff(double *par)
	{
		if (par == _p1x)
			return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2x)
			return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p1y)
			return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2y)
			return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _r1)
			return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _r2)
			return (-2) * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y));
		return 0;
	}
	virtual CONSTR_TYPE type()
	{
		return CONSTR_INCONTACT;
	}
};
class ExternalContactCircle :public IConstraint
{
	double *_p1x, *_p1y, *_r1, *_p2x, *_p2y, *_r2;

public:
	ExternalContactCircle(double *p1x, double *p1y, double *p2x, double *p2y, double *r1, double *r2)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_r1 = r1;
		_r2 = r2;
	}
	virtual ~ExternalContactCircle()
	{

	}
	virtual double error()
	{
		return ((*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));
	};
	virtual double diff(double *par)
	{
		if (par == _p1x)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2x)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p1y)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2y)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _r1)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _r2)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y));
		return 0;
	}
	virtual CONSTR_TYPE type()
	{
		return CONSTR_EXCONTACT;
	}
};

#endif