#include "global.h"
#include <cmath>

double length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double min(double a, double b)
{
	if (a <= b)
		return a;
	else
		return b;
}
