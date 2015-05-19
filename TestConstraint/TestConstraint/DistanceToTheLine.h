#ifndef DISTANCETOTHELINE_H
#define DISTANCETOTHELINE_H
#include "global.h"
#include <cmath>

// (c) Anton //

class DistanceToTheLine :public IConstraint
{
	double*_x, *_y, *_x1, *_y1, *_x2, *_y2, *_d;

	double length(double x1, double y1, double x2, double y2);
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

	//err = abs((y2 - y1)*x + (x1 - x2)*(y) + (x2*y1) - x1*y2) / sqrt((y2 - y1)*(y2 - y1) + (x1 - x2)*(x1 - x2));

	double error()
	{
		double err = DistPointLine(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_XX = GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_YY = GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		_STARTING_ERROR = err;
		//err = abs((*_y2 - *_y1)*(*_x) + (*_x1 - *_x2)*(*_y) + (*_x2*(*_y1) - *_x1*(*_y2))) / sqrt(((*_y2 - *_y1)*(*_y2 - *_y1)) + (*_x1 - *_x2)*(*_x1 - *_x2));
		return (err - *_d)*(err - *_d);
	};

	double diff(double *par)
	{		
		if (par == _x) return 2 * (*_d - _STARTING_ERROR)*(_XX - *_x) / _STARTING_ERROR;
		if (par == _y) return 2 * (*_d - _STARTING_ERROR)*(_YY - *_y) / _STARTING_ERROR;
		if (par == _x1) return 0;
		if (par == _y1) return 0;
		if (par == _x2) return 0;
		if (par == _y2) return 0;
		if (par == _d) return 2 * (*_d - _STARTING_ERROR);
		return 0;
	};
	/*
	virtual CONSTR_TYPE type()
	{
	return CONSTR_P2LINEDIST;
	};
	*/
private:
	double _STARTING_ERROR;
	double _XX;
	double _YY;
};
#endif
