#ifndef DISTANCETOTHELINE_H
#define DISTANCETOTHELINE_H
#include "../global.h"
#include <cmath>

// (c) Anton // type CONSTR_P2LINEDIST

class DistanceToTheLine :public IConstraint
{
	double*_x, *_y, *_x1, *_y1, *_x2, *_y2, *_d;

	double GetX(double x, double y, double x1, double y1, double x2, double y2);
	double GetY(double x, double y, double x1, double y1, double x2, double y2);

public:
	double DistPointLine(double x, double y, double x1, double y1, double x2, double y2);
	DistanceToTheLine(double*x, double *y, double *x1, double *y1, double *x2, double *y2, double *d)
	{
		_x = x;
		_y = y;
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;
		_d = d;
	}
	virtual ~DistanceToTheLine()
	{

	}

	double error()
	{
		/*double err = DistPointLine(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_XX = GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_YY = GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_STARTING_ERROR = err;*/
		return 0;//(err - *_d)*(err - *_d);
	};

	double diff(double *par)
	{		
		/*if (par == _x) return 2 * (*_d - _STARTING_ERROR)*(_XX - *_x) / _STARTING_ERROR;
		if (par == _y) return 2 * (*_d - _STARTING_ERROR)*(_YY - *_y) / _STARTING_ERROR;
		if (par == _x1) return 0;
		if (par == _y1) return 0;
		if (par == _x2) return 0;
		if (par == _y2) return 0;
		if (par == _d) return 2 * (*_d - _STARTING_ERROR);*/
		return 0;
	};

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
