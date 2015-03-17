#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectSkin.h"

class Point
{
public:
	double *x;
	double *y;

	Point(double *xx = 0, double *yy = 0)
	{
		x = xx;
		y = yy;
	}
	Point(double xx, double yy)
	{
		x = new double;
		*x = xx;
		y = new double;
		*y = yy;
	}
	~Point()
	{
		delete x;
		delete y;
	}
};

class Segment
{
public:
	Point *p1; // begin
	Point *p2; // end

	Segment()
	{
		p1 = 0;
		p2 = 0;
	}

	Segment(double x1, double y1, double x2, double y2)
	{
		p1 = new Point;
		*p1->x = x1;
		*p1->y = y1;
		p2 = new Point;
		*p2->x = x2;
		*p2->y = y2;
	}

	Segment(Point *point1, Point *point2)
	{
		p1 = point1;
		p2 = point2;
	}
	~Segment()
	{
		delete p1;
		delete p2;
	}
};

class Vector
{
public:
	//----structure
	double x;
	double y;
	//----functions
	Vector(double _x, double _y)
	{
		x = _x;
		y = _y;
	};
	Vector()
	{
		x = 0;
		y = 0;
	};
	Vector(Segment *seg)
	{
		x = seg->p1->x - seg->p2->x;
		y = seg->p1->y - seg->p2->y;
	};
	Vector operator+ (const Vector &v);
	void operator+= (const Vector &v);
	Vector operator- (const Vector &v);
	void operator-= (const Vector &v);
	Vector operator* (const Vector &v);		// scalar
	Vector operator* (const double &a);
	Vector operator*= (const double &a);
	double length();		// returns length
	double module();		// returns length
	Vector unit_vector();// returns unit vector
};

class Angle
{
public:
	double *angle;

	Angle() { angle = 0; }
	Angle(double a) { *angle = a; }
	double grads();			// returns angle in grads
};

class Arc
{
public:
	//----structure
	Point *o;
	Vector d;
	Angle angle;
	//----functions
	Arc()
	{
		o->x = 0;
		o->y = 0;
		d = { 0, 0 };
		angle = 0;
	};
	Arc(Point &p, Vector &z, Angle &a)
	{
		o->x = p.x;
		o->y = p.y;
		d = z;
		angle = a;
	};
	double length(); // returns length of the arc
	double area();	  // returns area of the sector
	//Segment chord(); // returns chord of the sector
};

#endif