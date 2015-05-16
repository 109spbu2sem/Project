#ifndef DISTANCE_POINT_POINT_H
#define DISTANCE_POINT_POINT_H
#include "..\global.h"

// (c) Alena // type CONSTR_P2PDIST

class Point2Point :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_d;
public:
	Point2Point(double *p1x, double *p1y, double *p2x, double *p2y, double *d)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_d = d;
	}
	virtual ~Point2Point()
	{

	}
	virtual double error()
	{
		return (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_d - length(*_p1x, *_p1y, *_p2x, *_p2y));
	}
	virtual double diff(double *par)
	{
		if (par == _p1x)
			return 2 * (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2x)
			return 2 * (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p1y)
			return 2 * (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2y)
			return 2 * (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _d)
			return 2 * (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y));
		return 0;
	}
	virtual CONSTR_TYPE type()
	{
		return CONSTR_P2PDIST;
	}
	virtual double value() const
	{
		return *_d;
	}
};


#endif // DISTANCE_POINT_POINT_H