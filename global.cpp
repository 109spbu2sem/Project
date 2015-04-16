#include "global.h"
#include <cmath>

double length(double x1, double y1, double x2, double y2)

{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double error_angle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double a)
{
	return pow(cos(a) - ((x1 - x2)*(x3 - x4) + (y1 - y2)*(y3 - y4)) /
		(length(x1, y1, x2, y2)*length(x3, y3, x4, y4)), 2);
}

double _angle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double a)
{
	return 2 * sqrt(error_angle(x1,y1,x2,y2,x3,y3,x4,y4,a))* ((x4 - x3)*(pow(length(x1, y1, x2, y2), 2)) +
		((x1 - x2)*((x1 - x2)*(x3 - x4) + (y1 - y2) * (y3 - y4)))) /
		(length(x3, y3, x4, y4)*(pow(length(x1, y1, x2, y2), 3)));
}