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

void CORE::ChangeStatus(double x, double y)
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
		//change status
	}
	else
	{
		if (min_j >= 0)
		{
			//change status
		}
		else
		{
			if (min_i >= 0)
			{
				//change status
			}
			else return;
		}
	}
	return;
}