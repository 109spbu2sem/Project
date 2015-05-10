#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectSkin.h"

class Point: public ObjectSkin //<Point>
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
	~Point() 
	{
	}
	virtual PRIMITIVE_TYPE objectType()
	{
		return PRIMITIVE_POINT;
	}
};

class Segment : public ObjectSkin //<Segment>
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
	virtual PRIMITIVE_TYPE objectType()
	{
		return PRIMITIVE_SEGMENT;
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
	double operator* (const Vector &v);		// scalar
	Vector operator* (const double &a);
	Vector operator*= (const double &a);
	double length();		// returns length
	double module();		// returns length
	Vector unit_vector();// returns unit vector
};

/*class Angle : public ObjectSkin //<Angle>
{
public:
	double *angle;

	Angle() { angle = 0; }
	Angle(double a) { *angle = a; }
	double grads();			// returns angle in grads
	virtual unsigned objectType()
	{
		return 3;
	}
};*/

class Circle : public ObjectSkin //<Circle>
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

/*class Arc : public ObjectSkin //<Arc>
{
public:
	//----structure
	Point *_o;
	Vector _d;
	Angle _angle;
	//----functions
	Arc()
	{
		_o = 0;
		_d = Vector(0, 0);
		_angle = 0;
	};
	Arc(Point *p, Vector &z, Angle &a)
	{
		_o = p;
		_d = z;
		_angle = a;
	};
	double length(); // returns length of the arc
	double area();	  // returns area of the sector
	//Segment chord(); // returns chord of the sector
	virtual unsigned objectType()
	{
		return 4;
	}
};*/

#endif