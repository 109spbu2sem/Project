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
	return *angle / PI * 180;
}

//----------------------------------------------------------------------
//-------------------------------ARC-----------------------------------
//---------------------------------------------------------------------

double Arc::area()
{
	return *angle.angle * d.length() * d.length() / 2;
}

double Arc::length()
{
	return d.length() * *angle.angle;
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