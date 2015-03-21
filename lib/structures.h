#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectSkin.h"

class Point
{
public:
	double *_x;
	double *_y;

	Point(double *xx = 0, double *yy = 0)
	{
		_x = xx;
		_y = yy;
	}
	Point(double xx, double yy)
	{
		_x = new double;
		*_x = xx;
		_y = new double;
		*_y = yy;
	}
	~Point() 
	{
		delete _x;
		delete _y;
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

	Segment(Point *point1, Point *point2)
	{
		p1 = point1;
		p2 = point2;
	}
	~Segment() {}
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
		x = seg->p1->_x - seg->p2->_x;
		y = seg->p1->_y - seg->p2->_y;
	};
	Vector operator+ (const Vector &v);
	void operator+= (const Vector &v);
	Vector operator- (const Vector &v);
	void operator-= (const Vector &v);
	double operator* (const Vector &v);		// scalar
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
		o->_x = 0;
		o->_y = 0;
		d = { 0, 0 };
		angle = 0;
	};
	Arc(Point &p, Vector &z, Angle &a)
	{
		o->_x = p._x;
		o->_y = p._y;
		d = z;
		angle = a;
	};
	double length(); // returns length of the arc
	double area();	  // returns area of the sector
	//Segment chord(); // returns chord of the sector
};

#endif