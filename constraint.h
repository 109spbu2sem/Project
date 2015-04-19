#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include "global.h"
#include <cmath>

class Point2Point :public iConstraint
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
};
class Angle :public iConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_p4x, *_p4y, *_a;
	double _angle(double* p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y, double *a)
	{
		return 2 * sqrt(error())* ((*_p4x - *_p3x)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) +
			((*_p1x - *_p2x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
			(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3)));
	}
public:
	Angle(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y, double *a)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_p3x = p3x;
		_p3y = p3y;
		_p4x = p4x;
		_p4y = p4y;
		_a = a;
	}
	double error()
	{
		return pow(cos(*_a) - ((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y)*(*_p3y - *_p4y)) /
			(length(*_p1x, *_p1y, *_p2x, *_p2y)*length(*_p3x, *_p3y, *_p4x, *_p4y)), 2);
	}
	double diff(double *par)
	{
		if (par == _p1x)
			return _angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y, _a);
		//return 2 * sqrt(error())* ((*_p4x - *_p3x)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y),2)) +
		//((*_p1x - *_p2x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		//(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3)));
		if (par == _p2x)
			return -(_angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y, _a));
		/*return (-2) * sqrt(error())* ((*_p4x - *_p3x)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) +
		((*_p1x - *_p2x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3)));*/
		if (par == _p3x)
			return _angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a);
		//return 2 * sqrt(error())* ((*_p2x - *_p1x)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 2)) +
		//((*_p3x - *_p4x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		//(length(*_p1x, *_p1y, *_p2x, *_p2y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 3)));
		if (par == _p4x)
			return -(_angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a));
		//return (-2) * sqrt(error())* ((*_p2x - *_p1x)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 2)) +
		//((*_p3x - *_p4x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		//(length(*_p1x, *_p1y, *_p2x, *_p2y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 3)));
		if (par == _p1y)
			return _angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a);
		/*return (2 * sqrt(error())* ((*_p4y - *_p3y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) +
		((*_p2y - *_p1y)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3))));*/
		if (par == _p2y)
			return -(_angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a));
		/*return ((-2) * sqrt(error())* ((*_p4y - *_p3y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) +
		((*_p2y - *_p1y)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3))));*/
		if (par == _p3y)
			return _angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a);
		/*return 2 * sqrt(error())* ((*_p2y - *_p1y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 2), 2) +
		((*_p3y - *_p4y)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		(length(*_p1x, *_p1y, *_p2x, *_p2y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 3)));*/
		if (par == _p4y)
			return -(_angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a));
		/*return (-2) * sqrt(error())* ((*_p2y - *_p1y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 2), 2) +
		((*_p3y - *_p4y)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
		(length(*_p1x, *_p1y, *_p2x, *_p2y)*(pow(length(*_p3x, *_p3y, *_p4x, *_p4y), 3)));*/
		return 0;
	}
	unsigned type()
	{
		return 1;
	}
};

class ThreePoints :public iConstraint
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
		return pow((*_p3x*(*_p2y - *_p1y) + *_p3y*(*_p1x - *_p2x) + *_p1y*(*_p2x - *_p1x) - *_p1x*(*_p2y - *_p1y)), 2);
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
	unsigned type()
	{
		return 1;
	}
};

class AspectRatio :public iConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_k;
public:
	AspectRatio(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *k)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_p3x = p3x;
		_p3y = p3y;
		_k = k;
	}
	double error()
	{
		return pow(*_k - length(*_p1x, *_p1y, *_p2x, *_p2y)/length(*_p2x, *_p2y, *_p3x, *_p3y),2);
	}
	double diff(double *par)
	{
		if (par == _p1x)
			return (-2) * (*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y)) *
			(*_p1x - *_p2x) / (length(*_p2x, *_p2y, *_p3x, *_p3y)*length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p1y)
			return (-2) * (*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y)) *
			(*_p1y - *_p2y) / (length(*_p2x, *_p2y, *_p3x, *_p3y)*length(*_p1x, *_p1y, *_p2x, *_p2y));
		if (par == _p2x)
			return (-2) * (*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y)) *
			length(*_p2x, *_p2y, *_p3x, *_p3y)*((*_p2x - *_p1x)*pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2) -
			(*_p2x - *_p3x)*pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) / (length(*_p1x, *_p1y, *_p2x, *_p2y)*
			pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 4));
		if (par == _p2y)
			return (-2) * (*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y)) *
			length(*_p2x, *_p2y, *_p3x, *_p3y)*((*_p2y - *_p1y)*pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 2) -
			(*_p2y - *_p3y)*pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) / (length(*_p1x, *_p1y, *_p2x, *_p2y)*
			pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 4));
		if (par == _p3x)
			return 2 * length(*_p1x, *_p1y, *_p2x, *_p2y)*(*_p3x - *_p2x) / pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 3);
		if (par == _p3y)
			return 2 * length(*_p1x, *_p1y, *_p2x, *_p2y)*(*_p3y - *_p2y) / pow(length(*_p2x, *_p2y, *_p3x, *_p3y), 3);
		if (par == _k)
			return 2 * (*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y));
		return 0;
	}
};

#endif // CONSTRAINT_H