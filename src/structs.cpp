#include <iostream>
#include "structs.h"

DynArray::DynArray(void)
{
	_points = 0;
	_size = 0;
}
void DynArray::store(Point p)
{
	if (_points == 0)
	{
		_points = new Point;
		(*_points).x = p.x;
		(*_points).y = p.y;
		_size = 1;
		return;
	}
	else
	{
		_size++;
		//copy old
		Point *newpoints = new Point[_size];
		for (unsigned i = 0; i < _size - 1; i++)
			newpoints[i] = _points[i];
		//erase old
		delete[] _points;
		//add new
		newpoints[_size - 1] = p;
		_points = newpoints;
		return;
	}
	return;
}
Point DynArray::get(int num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _points[num];
}