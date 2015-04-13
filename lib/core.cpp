#include "core.h"
#include "gui.h"
#include "constraints\Collector.h"
#include "constraints\DistancePoint-Point.h"
#include "constraints\DistancePoint-Section.h"
#include "constraints\DistanceToTheLine.h"
#include "constraints\AngleSegment-Segment.h"

CORE::CORE()
{
	
}

CORE::~CORE()
{
	
}

void CORE::Redraw()
{
	for (ArrayViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._x, *i.getValue()._y);
	}
	for (ArrayViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._p1->_x, *i.getValue()._p1->_y, *i.getValue()._p2->_x, *i.getValue()._p2->_y);
	}
	for (ArrayViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._o->_x, *i.getValue()._o->_y, *i.getValue()._r);
	}
	return;
}

void CORE::MainCalculate()
{
	ConstraintCollector collector;
	Storage_Array<double*> parameters;
	for (ListViewer<IConstraint> i; i.canMoveNext(); i.moveNext())
	{
		collector.addConstraint(&i.getValue());
	}
	BuildFigure(&collector, &parameters);
}

void CORE::BuildFigure(IConstraint* constraint, Storage_Array<double*>* parameters)
{
	if (!constraint || !parameters) return; // check for true work

	const double f_epsi = 1e-12;
	double current = constraint->error();
	double previous = 0;
	double *dx = new double[parameters->size()];

	do
	{
		previous = current;

		double step_min = 0.000001;
		double step_max = 1000;

		for (unsigned i = 0; i < parameters->size(); i++)
			dx[i] = -step_min * constraint->diff((*parameters)[i]); // calculate gradient
		for (unsigned i = 0; i < parameters->size(); i++)
			*(*parameters)[i] += dx[i];										 // change parametrs

		current = constraint->error();
	} while (abs(previous - current) > f_epsi);
	delete[] dx;
	return;
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

void CORE::AddRule(unsigned type, double value)
{
	switch (type)
	{
	case 1:
	{
		if (/*Picked only 2 Points*/)
		{
			Point2Point rule(/*point's parameters*/p1x, p1y, p2x, p2y, _storage_of_coordinates.add(value));
			_storage_of_constraints.add(rule);
		}
		return;
	}
	case 2:
	{
		if (/*Picked only Point and Segment*/)
		{
			DistanceFromPointToSection rule(/*point's and segment's parameters*/px, py, p1x, p1y, p2x, p2y, _storage_of_coordinates.add(value));
			_storage_of_constraints.add(rule);
		}
		return;
	}
	case 3:
	{
		if (/*Picked only 3 Points or Point and Segment*/)
		{
			DistanceToTheLine rule(/*point's and segment's parameters*/px, py, p1x, p1y, p2x, p2y, _storage_of_coordinates.add(value));
			_storage_of_constraints.add(rule);
		}
		return;
	}
	default:
		return;
	}
}

void CORE::ChangeStatus(double x, double y, unsigned char status_key)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 2;
	int min_i = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x, y) < min)
		{
			min = length(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x, y);
			min_i = i;
		}
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x, y) < min)
		{
			min = length(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x, y);
			min_j = i;
		}
	}
	size = _storage_of_circles.size();
	int min_k = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_circles[i]._o->_x, *_storage_of_circles[i]._o->_y, x, y) < min)
		{
			min = length(*_storage_of_circles[i]._o->_x, *_storage_of_circles[i]._o->_y, x, y);
			min_k = i;
		}
	}
	/*size = _storage_of_arcs.size();
	int min_k = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y) < min)
		{
			min = length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y);
			min_k = i;
		}
	}*/
	if (min_k >= 0)
	{
		_storage_of_circles[min_k].changeVisible();
	}
	else 
	{
		if (min_j >= 0)
		{
			_storage_of_segments[min_j].changeVisible();
		}
		else
		{
			if (min_i >= 0)
			{
				_storage_of_points[min_i].changeVisible();
			}
			else return;
		}
	}
	return;
}

void CORE::Select(double x, double y)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 2;
	int min_i = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x, y) < min)
		{
			min = length(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x, y);
			min_i = i;
		}
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x, y) < min)
		{
			min = length(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x, y);
			min_j = i;
		}
	}
	size = _storage_of_circles.size();
	int min_k = -1;
	for (unsigned i = 0; i < size; i++)
	{
		if (length(*_storage_of_circles[i]._o->_x, *_storage_of_circles[i]._o->_y, x, y) < min)
		{
			min = length(*_storage_of_circles[i]._o->_x, *_storage_of_circles[i]._o->_y, x, y);
			min_k = i;
		}
	}
	/*size = _storage_of_arcs.size();
	int min_k = -1;
	for (unsigned i = 0; i < size; i++)
	{
	if (length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y) < min)
	{
	min = length(_storage_of_arcs[i].o.x, _storage_of_arcs[i].o.y, x, y);
	min_k = i;
	}
	}*/
	if (min_k >= 0)
	{
		_storage_of_circles[min_k].changeSelect();
	}
	else
	{
		if (min_j >= 0)
		{
			_storage_of_segments[min_j].changeSelect();
		}
		else
		{
			if (min_i >= 0)
			{
				_storage_of_points[min_i].changeSelect();
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

void CORE::Select(double x1, double y1, double x2, double y2)
{
	// select points
	unsigned size = _storage_of_points.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x1, y1, x2, y2))
		{
			_storage_of_points[i].changeSelect();
			_selected_objects.add(_storage_of_points[i]);
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x1, y1, x2, y2) &&
			isInArea(*_storage_of_segments[i]._p2->_x, *_storage_of_segments[i]._p2->_y, x1, y1, x2, y2))
		{
			_storage_of_segments[i].changeSelect();
			_selected_objects.add(_storage_of_segments[i]);
		}
	}
	size = _storage_of_circles.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_circles[i]._o->_x, *_storage_of_circles[i]._o->_y, x1, y1, x2, y2))
		{
			_storage_of_circles[i].changeSelect();
			_selected_objects.add(_storage_of_circles[i]);
		}
	}
	return;
}

void CORE::ClearSelection()
{
	for (ListViewer<ObjectSkin> i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		i.getValue().changeSelect(false);
	}
}