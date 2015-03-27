#include "global.h"
#include "structures.h"
#include <cmath>


class Point2PointDistance :public iConstraint
{
private:
	double *p1x, *p1y, *p2x, *p2y;
	double *dist;
public:
	Point2PointDistance(Point& p1, Point& p2, double *dist)
	{

	}
	virtual double error()
	{
		double err = sqrt((*p1x - *p2x)*(*p1x - *p2x) + (*p1y - *p2y)*(*p1y - *p2y));
		return (err - *dist)*(err - *dist);
	}
	virtual double diff(double *par)
	{

	}
};