#ifndef ANGLE_SEGMENT_SEGMENT_H
#define ANGLE_SEGMENT_SEGMENT_H
#include "..\global.h"
#include <cmath>

// (c) Alena // type = 4

class AngleSegmentSegment :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_p4x, *_p4y, *_a;
	double _angle(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y, double *a)
	{
		return 2 * sqrt(error())* ((*_p4x - *_p3x)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 2)) +
			((*_p1x - *_p2x)*((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y) * (*_p3y - *_p4y)))) /
			(length(*_p3x, *_p3y, *_p4x, *_p4y)*(pow(length(*_p1x, *_p1y, *_p2x, *_p2y), 3)));
	}
public:
	AngleSegmentSegment(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y, double *a)
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
		if (par == _p2x)
			return -(_angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y, _a));
		if (par == _p3x)
			return _angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a);
		if (par == _p4x)
			return -(_angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a));
		if (par == _p1y)
			return _angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a);
		if (par == _p2y)
			return -(_angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a));
		if (par == _p3y)
			return _angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a);
		if (par == _p4y)
			return -(_angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a));
		return 0;
	}
	virtual CONSTR_TYPE type()
	{
		return CONSTR_L2LANGLE;
	}
};
#endif // ANGLE_SEGMENT_SEGMENT_H