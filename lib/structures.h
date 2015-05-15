#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectBase.h"

class Point : public ObjectBase //<Point>
{
public:
	// pointer to 'x' coordinate of point
	double *x;
	// pointer to 'y' coordinate of point
	double *y;

	Point(double *xx = 0, double *yy = 0)
	{
		x = xx;
		y = yy;
	}
	virtual ~Point()
	{
	}
	virtual PRIMITIVE_TYPE objectType()
	{
		return PRIMITIVE_POINT;
	}
};

class Segment : public ObjectBase //<Segment>
{
public:
	Point *p1; // begin
	Point *p2; // end

	Segment()
	{
		p1 = 0;
		p2 = 0;
	}

	Segment(Point *point1, Point *point2)
	{
		p1 = point1;
		p2 = point2;
	}
	virtual ~Segment()
	{
	}
	virtual PRIMITIVE_TYPE objectType()
	{
		return PRIMITIVE_SEGMENT;
	}
};

class Circle : public ObjectBase //<Circle>
{
public:
	//----structure
	Point* p;
	double* r;

	//----functions
	Circle()
	{
		p = 0;
		r = 0;
	}
	virtual ~Circle()
	{

	}
	Circle(Point *point, double *radius)
	{
		p = point;
		r = radius;
	}
	virtual PRIMITIVE_TYPE objectType()
	{
		return PRIMITIVE_CIRCLE;
	}
};

#endif