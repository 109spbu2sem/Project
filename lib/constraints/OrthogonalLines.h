#ifndef ORTHOGONAL_LINES_H
#define ORTHOGONAL_LINES_H
#include "..\global.h"

// (c) Alena // type CONSTR_ORTHOGONALITY

class OrthogonalLines :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_p4x, *_p4y;
public:
	OrthogonalLines(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y)
	{
		_p1x = p1x;
		_p1y = p1y;
		_p2x = p2x;
		_p2y = p2y;
		_p3x = p3x;
		_p3y = p3y;
		_p4x = p4x;
		_p4y = p4y;
	}
	virtual ~OrthogonalLines()
	{

	}
	virtual double error()
	{
		return pow((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x), 2);
	}
	virtual double diff(double *par)
	{
		if (par == _p1x)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p3x - *_p4x);
		if (par == _p2x)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p4x - *_p3x);
		if (par == _p3x)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p1x - *_p2x);
		if (par == _p4x)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p2x - *_p1x);
		if (par == _p1y)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p3y - *_p4y);
		if (par == _p2y)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p4y - *_p3y);
		if (par == _p3y)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p1y - *_p2y);
		if (par == _p4y)
			return 2 * ((*_p2y - *_p1y)*(*_p4y - *_p3y) + (*_p1x - *_p2x)*(*_p3x - *_p4x))*(*_p2y - *_p1y);
		return 0;
	}
	virtual CONSTR_TYPE type() const
	{
		return CONSTR_ORTHOGONALITY;
	}
	virtual double value() const
	{
		return NAN;
	}
};


	
#endif // ORTHOGONAL_LINES_H