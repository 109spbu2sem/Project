#ifndef THREE_POINTS_LINE_H
#define THREE_POINTS_LINE_H
#include "..\global.h"
#include <cmath>

// (c) Alena // type = 5

class ThreePoints :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y;
public:
	ThreePoints(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_p3x = p3x;
		_p3y = p3y;
	}
	double error()
	{
		return pow(((*_p3x*(*_p2y-*_p1y) + *_p3y*(*_p1x - *_p2x) + *_p1y*(*_p2x-*_p1x) - *_p1x*(*_p2y - *_p1y))), 2);
	}
	double diff(double *par)
	{
		if (par == _p1x)
			return 2 * error()*(*_p3y - *_p2y);
		if (par == _p2x)
			return 2 * error()*(*_p1y - *_p3y);
		if (par == _p3x)
			return 2 * error()*(*_p2y - *_p1y);
		if (par == _p1y)
			return 2 * error()*(*_p2x - *_p3x);
		if (par == _p2y)
			return 2 * error()*(*_p3x - *_p1x);		
		if (par == _p3y)
			return 2 * error()*(*_p1x - *_p2x);
		return 0;
	}
	virtual CONSTR_TYPE type()
	{
		return CONSTR_3PONLINE;
	}
};

#endif // THREE_POINTS_LINE_H