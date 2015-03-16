#include "core.h"
#include <cmath>

double length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

CORE::CORE()
{
	
}

CORE::~CORE()
{
	
}

void CORE::AddObject(double point_x, double point_y)
{
	CORE::_storage_of_points.add(Point{ point_x, point_y });
}

void CORE::AddObject(double point_x, double point_y, double vector_x, double vector_y)
{
	CORE::_storage_of_segments.add(Segment{ Point{ point_x, point_y }, Vector{ vector_x, vector_y } });
}

void CORE::AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle)
{
	CORE::_storage_of_arcs.add(Arc{ Point{ point_x, point_y }, Vector{ vector_x, vector_y }, Angle{ angle } });
}

void CORE::ChangeStatus(double x, double y, unsigned char status_key)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 5;
	int min_i = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_points[i].x, _storage_of_points[i].y, x, y) < min)
		{
			min = length(_storage_of_points[i].x, _storage_of_points[i].y, x, y);
			min_i = i;
		}
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_segments[i].o.x, _storage_of_segments[i].o.y, x, y) < min)
		{
			min = length(_storage_of_segments[i].o.x, _storage_of_segments[i].o.y, x, y);
			min_j = i;
		}
	}
	size = _storage_of_arcs.size();
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
	{
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
	}
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
	unsigned size = _storage_of_points.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(_storage_of_points[i].x, _storage_of_points[i].y, x1, y1, x2, y2))
		{
			//change selection
		}
	}
	size = _storage_of_segments.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(_storage_of_segments[i].o.x, _storage_of_segments[i].o.y, x1, y1, x2, y2) &&
			 isInArea(_storage_of_segments[i].o.x + _storage_of_segments[i].d.x, _storage_of_segments[i].o.y + _storage_of_segments[i].d.y, x1, y1, x2, y2))
		{
			//change selection
		}
	}
	return;
}