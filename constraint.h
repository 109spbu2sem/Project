#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include "global.h" // взять из этой же папки

class Point2Point:public iConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_d;
	// тут объявить все функции кроме тех, которые ниже, объемные выносятся в cpp файл
public:
	Point2Point(double *p1x, double *p1y, double *p2x, double *p2y, double *d)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_d = d;
	}
	double error()
	{
		return (*_d - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_d - length(*_p1x, *_p1y, *_p2x, *_p2y));
	}
	double diff(double *par)
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
	unsigned type()
	{
		return 1;
	}
};


#endif // CONSTRAINT_H
