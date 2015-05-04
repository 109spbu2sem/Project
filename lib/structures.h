#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "ObjectSkin.h"

class Point: public ObjectSkin //<Point>
{
public:
	// pointer to 'x' coordinate of point
	double *_x;
	// pointer to 'y' coordinate of point
	double *_y;

	Point(double *xx = 0, double *yy = 0)
	{
		_x = xx;
		_y = yy;
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
	Point *_p1; // begin
	Point *_p2; // end

	Segment()
	{
		_p1 = 0;
		_p2 = 0;
	}

	Segment(Point *point1, Point *point2)
	{
		_p1 = point1;
		_p2 = point2;
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
		x = seg->_p1->_x - seg->_p2->_x;
		y = seg->_p1->_y - seg->_p2->_y;
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
	Point* _o;
	double* _r;

	//----functions
	Circle()
	{
		_o = 0;
		_r = 0;
	}
	Circle(Point *p, double *r)
	{
		_o = p;
		_r = r;
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