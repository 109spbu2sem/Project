#ifndef ASPECT_RATIO_H
#define ASPECT_RATIO_H
#include "..\global.h"
#include <cmath>

// (c) Alena // type CONSTR_3PRATIO

class AspectRatio :public IConstraint
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
	virtual ~AspectRatio()
	{

	}
	double error()
	{
		return pow(*_k - length(*_p1x, *_p1y, *_p2x, *_p2y) / length(*_p2x, *_p2y, *_p3x, *_p3y), 2);
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
	CONSTR_TYPE type() const
	{
		return CONSTR_3PRATIO;
	}
	virtual double value() const
	{
		return *_k;
	}
};

#endif