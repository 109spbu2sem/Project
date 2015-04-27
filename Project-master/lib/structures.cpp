#include "structures.h"
#include "global.h"
#include <cmath>

//----------------------------------------------------------------------
//--------------------------------VECTOR-------------------------------
//----------------------------------------------------------------------
Vector Vector::operator+ (const Vector &v)
{
	Vector result(x + v.x, y + v.y);
	return result;
}

void Vector::operator+= (const Vector &v)
{
	x += v.x;
	y += v.y;
}

Vector Vector::operator- (const Vector &v)
{
	Vector result(x - v.x, y - v.y);
	return result;
}

void Vector::operator-= (const Vector &v)
{
	x -= v.x;
	y -= v.y;
}

double Vector::operator* (const Vector &v)
{
	return x * v.x + y * v.y;
}

Vector Vector::operator* (const double &a)
{
	Vector result(x * a, y * a);
	return result;
}

Vector Vector::operator*= (const double &a)
{
	Vector result(x * a, y * a);
	return result;
}

double Vector::length()
{
	return sqrt(x*x + y*y);
}

double Vector::module()
{
	return sqrt(x*x + y*y);
}

Vector Vector::unit_vector()
{
	Vector result(x / length(), y / length());
	return result;
}
//---------------------------------------------------------------------

double Angle::grads()
{
	return *angle / PI * 180;
}

//----------------------------------------------------------------------
//-------------------------------ARC-----------------------------------
//---------------------------------------------------------------------

double Arc::area()
{
	return *_angle.angle * _d.length() * _d.length() / 2;
}

double Arc::length()
{
	return _d.length() * *_angle.angle;
}

/*Segment Arc::chord()
{
	Segment s;
	double a;
	s->p1->x = *(o->x) + d.x;
	s.p2->y = o->y + d.y;
	s.p2->x = d.x * (cos(angle.angle) - 1);
	s.p2->y = d.y * (sin(angle.angle) - 1);
	return s;
}*/