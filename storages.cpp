#include <iostream>
#include "storages.h"


void storagepoints::add(Point p)
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

Point& storagepoints::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _points[num];
}



void storagesegments::add(Segment s)
{
	
	if (_segments == 0)
	{
		_segments = new Segment;
		_segments[0] = s;
		_size = 1;
		return;
	}
	else
	{
		_size++;
		
		Segment *newseg = new Segment[_size];
		for (unsigned i = 0; i < _size - 1; i++)
			newseg[i] = _segments[i];
		
		delete[] _segments;
		
		newseg[_size - 1] = s;
		_segments = newseg;
		return;
	}
	return;
}

Segment& storagesegments::operator[] (unsigned num)
{
	if (num >= _size) throw std::invalid_argument("Bad array index");
	return _segments[num];
}
