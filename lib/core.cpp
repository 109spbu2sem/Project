#include "core.h"
#include "gui.h"

CORE::CORE()
{
	
}

CORE::~CORE()
{
	
}

void CORE::AddObject(double point_x, double point_y)
{
	Point p(_storage_of_coordinates.add(point_x), _storage_of_coordinates.add(point_y));
	_storage_of_points.add(p);
}

void CORE::AddObject(double point_x1, double point_y1, double point_x2, double point_y2)
{
	Point p1(_storage_of_coordinates.add(point_x1), _storage_of_coordinates.add(point_y1));
	Point p2(_storage_of_coordinates.add(point_x2), _storage_of_coordinates.add(point_y2));
	Segment s(_storage_of_points.add(p1), _storage_of_points.add(p2));
	_storage_of_segments.add(s);
}

void CORE::AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle)
{
	//CORE::_storage_of_arcs.add(Arc{ Point{ point_x, point_y }, Vector{ vector_x, vector_y }, Angle{ angle } });
}

void CORE::AddObject(double point_x, double point_y, double radius)
{
	Point p(_storage_of_coordinates.add(point_x), _storage_of_coordinates.add(point_y));
	Circle c(_storage_of_points.add(p), _storage_of_coordinates.add(radius));
	_storage_of_circles.add(c);
}

void CORE::ChangeStatus(double x, double y, unsigned char status_key)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 5;
	int min_i = -1;
	/*for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_points[i].x, _storage_of_points[i].y, x, y) < min)
		{
			min = length(_storage_of_points[i].x, _storage_of_points[i].y, x, y);
			min_i = i;
		}
	}*/
	size = _storage_of_segments.size();
	int min_j = -1;
	/*for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_segments[i].o.x, _storage_of_segments[i].o.y, x, y) < min)
		{
			min = length(_storage_of_segments[i].o.x, _storage_of_segments[i].o.y, x, y);
			min_j = i;
		}
	}*/
	/*size = _storage_of_arcs.size();
	int min_k = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y) < min)
		{
			min = length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y);
			min_k = i;
		}
	}
	if (min_k >= 0)
	{
		//change picking
	}
	else 
	{*/
		if (min_j >= 0)
		{
			//change picking
		}
		else
		{
			if (min_i >= 0)
			{
				//change picking
			}
			else return;
		}
	//}
	return;
}

bool isInArea(double x, double y, double x1, double y1, double x2, double y2)
{
	if (x2 < x1)
	{
		double temp = x2;
		x2 = x1;
		x1 = temp;
	}
	if (y2 < y1)
	{
		double temp = y2;
		y2 = y1;
		y1 = temp;
	}
	if (x1 < x && x < x2 && y1 < y && y < y2)
	{
		return true;
	}
	return false;
}

void CORE::ChangeStatus(double x1, double y1, double x2, double y2, unsigned char status_key)
{
	// select points
	unsigned size = _storage_of_points.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x1, y1, x2, y2))
		{
			//change selection
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x1, y1, x2, y2) &&
			 isInArea(*_storage_of_segments[i]._p2->_x, *_storage_of_segments[i]._p2->_y, x1, y1, x2, y2))
		{
			//change selection
		}
	}
	return;
}