#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include < cmath >
double length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
	class IConstraint{
	public:
		virtual double error() = 0;
		virtual double diff(double *par) = 0;

	};
	class ContactCircle :public IConstraint{
		double *_p1x, *_p1y, *_r1, *_p2x, *_p2y, *_r2;

	public:
		ContactCircle(double *p1x, double *p1y, double *p2x, double *p2y, double *r1, double *r2)
		{
			_p1x = p1x;
			_p1y = p1y;
			_p2x = p2x;
			_p2y = p2y;
			_r1 = r1;
			_r2 = r2;
		}
		virtual double error(){
			if (*_r1 + *_r2 == length(*_p1x, *_p1y, *_p2x, *_p2y))
				return ((*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));
			if (*_r1 - *_r2 == length(*_p1x, *_p1y, *_p2x, *_p2y))
				return ((*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));

		};
		virtual double diff(double *par){
			if (*_r1 + *_r2 == length(*_p1x, *_p1y, *_p2x, *_p2y))
			{
				if (par == _p1x)
					return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p2x)
					return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p1y)
					return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p2y)
					return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			}
			if (*_r1 - *_r2 == length(*_p1x, *_p1y, *_p2x, *_p2y))
			{
				if (par == _p1x)
					return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p2x)
					return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p1y)
					return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
				if (par == _p2y)
					return 2 * (*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			
			}
		}
		};
	

#endif 