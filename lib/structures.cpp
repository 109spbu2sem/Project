#include "structures.h"
#include <cmath>

#define PI 3.1415926535897932384

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

Vector Vector::operator* (const Vector &v)
{
	Vector result(x * v.x, y * v.y);
	return result;
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
	return angle / PI * 180;
}

//----------------------------------------------------------------------
//-------------------------------ARC-----------------------------------
//---------------------------------------------------------------------

double Arc::area()
{
	return angle.angle * d.length() * d.length() / 2;
}

double Arc::length()
{
	return d.length() * angle.angle;
}

Segment Arc::chord()
{
	Segment s;
	s.o = { o.x + d.x, o.y + d.y };
	s.d = { d.x * (cos(angle.angle) - 1), d.y * (sin(angle.angle) - 1) };
	return s;
}