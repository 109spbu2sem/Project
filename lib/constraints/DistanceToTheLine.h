#ifndef DISTANCETOTHELINE_H
#define DISTANCETOTHELINE_H
#include "..\global.h"
#include <cmath>

// (c) Anton // type = 3

class DistanceToTheLine :public IConstraint
{
	double*_x, *_y, *_x1, *_y1, *_x2, *_y2, *_d;

	double GetX(double x, double y, double x1, double y1, double x2, double y2);
	double GetY(double x, double y, double x1, double y1, double x2, double y2);
	double DistPointLine(double x, double y, double x1, double y1, double x2, double y2);
public:
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
	virtual double error()
	{
		double err = DistPointLine(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		return (err - *_d)*(err - *_d);
	};

	virtual double diff(double *par)
	{
		if (par == _x) return 2 * (*_d - (sqrt(error()) + *_d))*(*_x - (GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _y) return 2 * (*_d - (sqrt(error()) + *_d))*(*_y - (GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _x1) return 2 * (*_d - (sqrt(error()) + *_d))*(*_x1 - (GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _y1) return 2 * (*_d - (sqrt(error()) + *_d))*(*_y1 - (GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _x2) return 2 * (*_d - (sqrt(error()) + *_d))*(*_x2 - (GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _y2) return 2 * (*_d - (sqrt(error()) + *_d))*(*_y2 - (GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2))) / sqrt((sqrt(error()) + *_d));
		if (par == _d) return 2 * (*_d - (sqrt(error()) + *_d));
		return 0;
	};

	virtual CONSTR_TYPE type()
	{
		return CONSTR_P2LINEDIST;
	};
};
#endif