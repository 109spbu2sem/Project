#ifndef CONSTRAINT_H
#define CONSTRAINT_H
#include "global.h" 

	class InternalContactCircle :public IConstraint{
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
		 double error(){
			return ((*_r1 - *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));

		};
		 double diff(double *par)
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
		};
	class ExternalContactCircle :public IConstraint{
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
		double error(){
			return ((*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y))*(*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)));
			};
		double diff(double *par){
			if (par == _p1x)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2x - *_p1x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			if (par == _p2x)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1x - *_p2x) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			if (par == _p1y)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p2y - *_p1y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			if (par == _p2y)
			return 2 * (*_r1 + *_r2 - length(*_p1x, *_p1y, *_p2x, *_p2y)) * (*_p1y - *_p2y) / (length(*_p1x, *_p1y, *_p2x, *_p2y));
			}
	};
	

#endif 