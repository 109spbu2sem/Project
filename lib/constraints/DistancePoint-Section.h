#ifndef DISTANCEPOINT_TO_SECTION_H
#define DISTANCEPOINT_TO_SECTION_H
#include "../global.h"
#include <cmath>

// (c) Anton // type CONSTR_P2SECTDIST

class DistanceFromPointToSection :public IConstraint
{
	double*_x, *_y, *_x1, *_y1, *_x2, *_y2, *_d;

	double GetX(double x, double y, double x1, double y1, double x2, double y2);
	double GetY(double x, double y, double x1, double y1, double x2, double y2);

public:
	double DistPointSection(double x, double y, double x1, double y1, double x2, double y2);
	DistanceFromPointToSection(double*x, double *y, double *x1, double *y1, double *x2, double *y2, double *d)
	{
		_x = x;
		_y = y;
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;
		_d = d;
	}
	virtual ~DistanceFromPointToSection()
	{

	}
		double error()
	{
		double err;
		if (((GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2)) >= *_x1) && ((GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2)) <= *_x2))
		{
			err = DistPointSection(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
			_XX = GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
			_YY = GetY(*_x, *_y, *_x1, *_y1, *_x2, *_y2);
		}
		else
		{
			if (length(*_x, *_y, *_x1, *_y1) < length(*_x, *_y, *_x2, *_y2))
			{
				err = length(*_x, *_y, *_x1, *_y1);
				_XX = *_x1;
				_YY = *_y1;
			}
			else
			{
				err = length(*_x, *_y, *_x2, *_y2);
				_XX = *_x2;
				_YY = *_y2;
			}
		}
		_STARTING_ERROR = err;
		return (err - *_d)*(err - *_d);
	};

	double diff(double *par)
	{ 
		if (_XX == GetX(*_x, *_y, *_x1, *_y1, *_x2, *_y2))
		{
			if (par == _x) return 2 * (*_d - _STARTING_ERROR)*(_XX - *_x) / _STARTING_ERROR;
			if (par == _y) return 2 * (*_d - _STARTING_ERROR)*(_YY - *_y) / _STARTING_ERROR;
			if (par == _x1) return 0;
			if (par == _y1) return 0;
			if (par == _x2) return 0;
			if (par == _y2) return 0;
			if (par == _d) return 2 * (*_d - _STARTING_ERROR);
		}
		if (_XX == *_x1)
		{
			if (par == _x) return 2 * (*_d - _STARTING_ERROR)*(_XX - *_x) / _STARTING_ERROR;
			if (par == _y) return 2 * (*_d - _STARTING_ERROR)*(_YY - *_y) / _STARTING_ERROR;
			if (par == _x1) return 2 * (*_d - _STARTING_ERROR)*(*_x - _XX) / _STARTING_ERROR;
			if (par == _y1) return 2 * (*_d - _STARTING_ERROR)*(*_y - _YY) / _STARTING_ERROR;
			if (par == _x2) return 0;
			if (par == _y2) return 0;
			if (par == _d) return 2 * (*_d - _STARTING_ERROR);
		}
		if (_XX == *_x2)
		{
			if (par == _x) return 2 * (*_d - _STARTING_ERROR)*(_XX - *_x) / _STARTING_ERROR;
			if (par == _y) return 2 * (*_d - _STARTING_ERROR)*(_YY - *_y) / _STARTING_ERROR;
			if (par == _x1) return 0;
			if (par == _y1) return 0;
			if (par == _x2) return 2 * (*_d - _STARTING_ERROR)*(*_x - _XX) / _STARTING_ERROR;
			if (par == _y2) return 2 * (*_d - _STARTING_ERROR)*(*_y - _YY) / _STARTING_ERROR;
			if (par == _d) return 2 * (*_d - _STARTING_ERROR);
		}
		return 0;
	};
	virtual CONSTR_TYPE type() const
	{
		return CONSTR_P2SECTDIST;
	}
	virtual double value() const
	{
		return *_d;
	}
private:
	double _XX;
	double _YY;
	double _STARTING_ERROR;
};
#endif // DISTANCEPOINT_TO_SECTION_H
