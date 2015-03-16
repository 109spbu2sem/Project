#include <iostream>
#include "storages.h"

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

Vector Vector::unit_v()
{
	Vector result(x / length(), y / length());
	return result;
}
//----------------------------------------------------------------------
