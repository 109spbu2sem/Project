#ifndef DISTANCETOTHELINE_H
#define DISTANCETOTHELINE_H
#include "../global.h"
#include <cmath>

// (c) Anton // type CONSTR_P2LINEDIST

class DistanceToTheLine :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_d;
public:
	DistanceToTheLine(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *d)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_p3x = p3x;
		_p3y = p3y;
		_d = d;
	}
	virtual ~DistanceToTheLine()
	{

	}
		virtual double error()
	{
		return (*_d - abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y));
	}
	virtual double diff(double *par)
	{
		if (par == _d)
			return 1;
		if (*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x > 0)
		{
			if (par == _p1x)
				return (*_p3y - *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y);
			if (par == _p1y)
				return (*_p2x - *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y);
			if (par == _p2x)
				return ((*_p1y - *_p3y)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p2x - *_p3x)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p2y)
				return ((*_p3x - *_p1x)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p2y - *_p3y)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p3x)
				return ((*_p2y - *_p1y)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p3x - *_p2x)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p3y)
				return ((*_p1x - *_p2x)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p3y - *_p2y)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
		}
		else
		if (*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x < 0)
		{
			if (par == _p1x)
				return (-1)*(*_p3y - *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y);
			if (par == _p1y)
				return (-1)*(*_p2x - *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y);
			if (par == _p2x)
				return (-1)*((*_p1y - *_p3y)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p2x - *_p3x)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p2y)
				return (-1)*((*_p3x - *_p1x)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p2y - *_p3y)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p3x)
				return (-1)*((*_p2y - *_p1y)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p3x - *_p2x)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
			if (par == _p3y)
				return (-1)*((*_p1x - *_p2x)*length(*_p2x, *_p2y, *_p3x, *_p3y) + (*_p3y - *_p2y)*
				abs(*_p1x*(*_p2y - *_p3y) + *_p1y*(*_p3x - *_p2x) + *_p3y * *_p2x - *_p2y * *_p3x) / length(*_p2x, *_p2y, *_p3x, *_p3y)) /
				pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
		}
		return 0;
	}

	virtual CONSTR_TYPE type() const
	{
		return CONSTR_P2LINEDIST;
	}
	virtual double value() const
	{
		return *_d;
	}
private:
    double _STARTING_ERROR;
};
#endif
