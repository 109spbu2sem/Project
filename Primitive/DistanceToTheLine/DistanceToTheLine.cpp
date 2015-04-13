#include <iostream>
#include "DistanceToTheLine.h"


double DistanceToTheLine::length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double DistanceToTheLine::GetX(double x, double y, double x1, double y1, double x2, double y2)
{
	double X, Y;
	Y = (-x*x2*y2 + y*y1*y2 + x*x2*y1 - y*y1*y1 + x1*x2*y2 - x2*x2*y1) / (y1*y2 - y1*y1 + x1*x2 - x2*x2);
	X = (y1*Y + x*x2 - y*y1) / x2;
	return X;
}
double DistanceToTheLine::GetY(double x, double y, double x1, double y1, double x2, double y2)
{
	double Y;
	Y = (-x*x2*y2 + y*y1*y2 + x*x2*y1 - y*y1*y1 + x1*x2*y2 - x2*x2*y1) / (y1*y2 - y1*y1 + x1*x2 - x2*x2);
	return Y;
}
double DistanceToTheLine::DistPointLine(double x, double y, double x1, double y1, double x2, double y2)
{
	double X = GetX(x, y, x1, y1, x2, y2);
	double Y = GetY(x, y, x1, y1, x2, y2);
	return length(X, Y, x, y);
}

int main()
{
	return 0;
}