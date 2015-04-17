#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include "global.h"
#include <cmath>

class PointOnArc :public iConstraint
{
	double *_px,*_py,*_x0,*_y0,*_r;
public:
	PointOnArc(double *px,double *py, double *x0, double *y0, double *r)
	{
		_px=px;
		_py=py;
		_x0=x0;
		_y0=y0;
		_r=r;
	}
	double error ()
	{
		return (*_r - length(*_px, *_py, *_x0, *_y0))*(*_r - length(*_px, *_py, *_x0, *_y0));
	}

	double diff(double *par)
	{
		if (par == _px)
			return 2 * (*_r - length(*_px, *_py, *_x0, *_y0)) * (*_x0 - *_px) / (length(*_px, *_py, *_x0, *_y0));
		if (par == _x0)
			return 2 * (*_r - length(*_px, *_py, *_x0, *_y0)) * (*_x0 - *_px) / (length(*_px, *_py, *_x0, *_y0));
		if (par == _py)
			return 2 * (*_r - length(*_px, *_py, *_x0, *_y0)) * (*_y0 - *_py) / (length(*_px, *_py, *_x0, *_y0));
		if (par == _y0)
			return 2 * (*_r - length(*_px, *_py, *_x0, *_y0)) * (*_y0 - *_py) / (length(*_px, *_py, *_x0, *_y0));
		if (par == _r)
			return 2 * (*_r - length(*_px, *_py, *_x0, *_y0));
		return 0;
	}

	unsigned type()
	{
		return 1;
	}
};
