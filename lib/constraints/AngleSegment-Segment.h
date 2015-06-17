#ifndef ANGLE_SEGMENT_SEGMENT_H
#define ANGLE_SEGMENT_SEGMENT_H
#include "../global.h"
#include <cmath>

// (c) Alena // type CONSTR_L2LANGLE

class AngleSegmentSegment :public IConstraint
{
	double *_p1x, *_p1y, *_p2x, *_p2y, *_p3x, *_p3y, *_p4x, *_p4y, *_a;
	/*double _angle(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y)
	{
		return 2 * sqrt(error()) * ((*p4x - *p3x)*(pow(length(*p1x, *p1y, *p2x, *p2y), 2)) +
			((*p1x - *p2x)*((*p1x - *p2x)*(*p3x - *p4x) + (*p1y - *p2y) * (*p3y - *p4y)))) /
			(length(*p3x, *p3y, *p4x, *p4y)*(pow(length(*p1x, *p1y, *p2x, *p2y), 3)));
	}*/
	double _angle(double *p1x, double *p1y, double *p2x, double *p2y, double *p3x, double *p3y, double *p4x, double *p4y, double *a)
	{
		return 2 * sqrt(error()) *
			(*p4x - *p3x + (cos(*a)*length(*p3x, *p3y, *p4x, *p4y)*(2 * *p1x - 2 * *p2x)) / (2 * length(*p1x, *p1y, *p2x, *p2y)));
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
	virtual ~AngleSegmentSegment()
	{

	}
	double error()
	{
		/*return pow(cos(*_a) - ((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y)*(*_p3y - *_p4y)) /
			(length(*_p1x, *_p1y, *_p2x, *_p2y)*length(*_p3x, *_p3y, *_p4x, *_p4y)), 2);*/
		return pow((*_p1x - *_p2x)*(*_p3x - *_p4x) + (*_p1y - *_p2y)*(*_p3y - *_p4y) -
				  cos(*_a)*(length(*_p1x, *_p1y, *_p2x, *_p2y)*length(*_p3x, *_p3y, *_p4x, *_p4y)), 2);
	}
	/*double diff(double *par)
	{
		if (par == _p1x)
			return _angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y);
		if (par == _p2x)
			return -(_angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y));
		if (par == _p3x)
			return _angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y);
		if (par == _p4x)
			return -(_angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y));
		if (par == _p1y)
			return _angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x);
		if (par == _p2y)
			return -(_angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x));
		if (par == _p3y)
			return _angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x);
		if (par == _p4y)
			return -(_angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x));
		if (par == _a)
			return -2 * sqrt(error())*sin(*_a);
		return 0;
	}*/
	double diff(double *par)
	{
		if (par == _p1x)
			return -_angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y, _a);
		if (par == _p2x)
			return _angle(_p1x, _p1y, _p2x, _p2y, _p3x, _p3y, _p4x, _p4y, _a);
		if (par == _p3x)
			return -_angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a);
		if (par == _p4x)
			return _angle(_p3x, _p3y, _p4x, _p4y, _p1x, _p1y, _p2x, _p2y, _a);
		if (par == _p1y)
			return -_angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a);
		if (par == _p2y)
			return _angle(_p1y, _p1x, _p2y, _p2x, _p3y, _p3x, _p4y, _p4x, _a);
		if (par == _p3y)
			return -_angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a);
		if (par == _p4y)
			return _angle(_p3y, _p3x, _p4y, _p4x, _p1y, _p1x, _p2y, _p2x, _a);
		if (par == _a)
			return 2 * error() * sin(*_a) * (length(*_p1x, *_p1y, *_p2x, *_p2y)*length(*_p3x, *_p3y, *_p4x, *_p4y));
		return 0;
	}
	virtual CONSTR_TYPE type() const
	{
		return CONSTR_L2LANGLE;
	}
	virtual double value() const
	{
		return *_a / PI * 180;
	}
};
#endif // ANGLE_SEGMENT_SEGMENT_H
