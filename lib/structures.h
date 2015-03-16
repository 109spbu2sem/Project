#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectSkin.h"

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
	double angle;

	Angle(double a = 0) { angle = a; }
	double grads();			// returns angle in grads
};

struct Point
{
	double x;
	double y;
};
struct Segment
{
	Point o;			// begin
	Vector d;		// direction
};

class Arc
{
public:
	//----structure
	Point o;
	Vector d;
	Angle angle;
	//----functions
	Arc()
	{
		o.x = 0;
		o.y = 0;
		d = { 0, 0 };
		angle = 0;
	};
	Arc(Point &p, Vector &z, Angle &a)
	{
		o = p;
		d = z;
		angle = a;
	};
	double length(); // returns length of the arc
	double area();	  // returns area of the sector
	Segment chord(); // returns chord of the sector
};

#endif