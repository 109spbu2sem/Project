#include "core.h"
#include "gui.h"
#include "constraints\Collector.h"
#include "constraints\DistancePoint-Point.h"
#include "constraints\DistancePoint-Section.h"
#include "constraints\DistanceToTheLine.h"
#include "constraints\AngleSegment-Segment.h"
#include "constraints\ThreePointsOnTheLine.h"

CORE::CORE()
{
	
}

CORE::~CORE()
{
	
}

void CORE::Redraw()
{
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._x, *i.getValue()._y);
	}
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._p1->_x, *i.getValue()._p1->_y, *i.getValue()._p2->_x, *i.getValue()._p2->_y);
	}
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext())
	{
		mygui->Draw(*i.getValue()._o->_x, *i.getValue()._o->_y, *i.getValue()._r);
	}
	return;
}

void CORE::Calculate()
{
	ConstraintCollector collector;
	Storage_Array< double* > parameters;
	for (ListViewer< IConstraint* > i(_storage_of_constraints); i.canMoveNext(); i.moveNext())
	{
		collector.addConstraint(i.getValue());
	}
	for (ListViewer< double > i(_storage_of_parameters); i.canMoveNext(); i.moveNext())
	{
		parameters.add(&i.getValue());
	}
	BuildFigure(&collector, &parameters);
	Redraw();
	return;
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
	/*double *x = _storage_of_parameters.add(point_x);
	double *y = _storage_of_parameters.add(point_y);
	Point p(x,y);*/
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	_storage_of_points.add(p);
}

void CORE::AddObject(double point_x1, double point_y1, double point_x2, double point_y2)
{
	Point p1(_storage_of_parameters.add(point_x1), _storage_of_parameters.add(point_y1));
	Point p2(_storage_of_parameters.add(point_x2), _storage_of_parameters.add(point_y2));
	Segment s(_storage_of_points.add(p1), _storage_of_points.add(p2));
	_storage_of_segments.add(s);
}

void CORE::AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle)
{
	//CORE::_storage_of_arcs.add(Arc{ Point{ point_x, point_y }, Vector{ vector_x, vector_y }, Angle{ angle } });
}

void CORE::AddObject(double point_x, double point_y, double radius)
{
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	Circle c(_storage_of_points.add(p), _storage_of_parameters.add(radius));
	_storage_of_circles.add(c);
}

void CORE::AddRule(unsigned type, double value)
{
	switch (type)
	{
	case P2P_DIST:
	{ // may add multiselect for points and segments
			  switch (_selected_objects.size())
			  {
			  case 1:
			  {
						_selected_objects.rewind();
						Segment* obj = dynamic_cast<Segment*>(_selected_objects.get());
						if (obj)
						{
							Point2Point* rule = new Point2Point(obj->_p1->_x, obj->_p1->_y, obj->_p2->_x, obj->_p2->_y, _storage_of_constants.add(value));
							_storage_of_constraints.add(rule);
						}
						return;
			  }
			  case 2:
			  {
						_selected_objects.rewind();
						Point* obj1 = dynamic_cast<Point*>(_selected_objects.get());
						_selected_objects.moveNext();
						Point* obj2 = dynamic_cast<Point*>(_selected_objects.get());
						if (obj1 && obj2)
						{
							Point2Point* rule = new Point2Point(obj1->_x, obj1->_y, obj2->_x, obj2->_y, _storage_of_constants.add(value));
							_storage_of_constraints.add(rule);
						}
						return;
			  }
			  default:
				  return;
			  }
	}
	case P2S_DIST:
	{
			  switch (_selected_objects.size())
			  {
			  case 2:
			  {
						_selected_objects.rewind();
						Point* obj1 = dynamic_cast<Point*>(_selected_objects.get());
						if (obj1)
						{
							_selected_objects.moveNext();
							Segment* obj2 = dynamic_cast<Segment*>(_selected_objects.get());
							if (obj2)
							{
								DistanceFromPointToSection* rule = new DistanceFromPointToSection(obj1->_x, obj1->_y, obj2->_p1->_x,
									obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, _storage_of_constants.add(value));
								_storage_of_constraints.add(rule);
								return;
							}
						}
						Segment* ob2 = dynamic_cast<Segment*>(_selected_objects.get());
						if (ob2)
						{
							_selected_objects.moveNext();
							Point* ob1 = dynamic_cast<Point*>(_selected_objects.get());
							if (ob1)
							{
								DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->_x, ob1->_y, ob2->_p1->_x,
									ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, _storage_of_constants.add(value));
								_storage_of_constraints.add(rule);
								return;
							}
						}
						return;
			  }
			  case 3:

				  return;
			  default:
				  return;
			  }
	}
	case P2L_DIST:
	{
			  switch (_selected_objects.size())
			  {
			  case 2:
			  {
						_selected_objects.rewind();
						Point* obj1 = dynamic_cast<Point*>(_selected_objects.get());
						if (obj1)
						{
							_selected_objects.moveNext();
							Segment* obj2 = dynamic_cast<Segment*>(_selected_objects.get());
							if (obj2)
							{
								DistanceToTheLine* rule = new DistanceToTheLine(obj1->_x, obj1->_y, obj2->_p1->_x,
									obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, _storage_of_constants.add(value));
								_storage_of_constraints.add(rule);
								return;
							}
						}
						Segment* ob2 = dynamic_cast<Segment*>(_selected_objects.get());
						if (ob2)
						{
							_selected_objects.moveNext();
							Point* ob1 = dynamic_cast<Point*>(_selected_objects.get());
							if (ob1)
							{
								DistanceToTheLine* rule = new DistanceToTheLine(ob1->_x, ob1->_y, ob2->_p1->_x,
									ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, _storage_of_constants.add(value));
								_storage_of_constraints.add(rule);
								return;
							}
						}
						return;
			  }
			  case 3:

				  return;
			  default:
				  return;
			  }
	}
	case LL_ANGLE:
	{
			  switch (_selected_objects.size())
			  {
			  case 2:
				  return;
			  case 3:
				  return;
			  case 4:
			  {
						_selected_objects.rewind();
						Point* obj1 = dynamic_cast<Point*>(_selected_objects.get());
						_selected_objects.moveNext();
						Point* obj2 = dynamic_cast<Point*>(_selected_objects.get());
						_selected_objects.moveNext();
						Point* obj3 = dynamic_cast<Point*>(_selected_objects.get());
						_selected_objects.moveNext();
						Point* obj4 = dynamic_cast<Point*>(_selected_objects.get());
						if (obj1 && obj2 && obj3 && obj4)
						{
							AngleSegmentSegment* rule = new AngleSegmentSegment(
								obj1->_x, obj1->_y,
								obj2->_x, obj2->_y,
								obj3->_x, obj3->_y,
								obj4->_x, obj4->_y,
								_storage_of_parameters.add(value));
							_storage_of_constraints.add(rule);
						}
						return;
			  }
			  default:
				  return;
			  }
		/*Picked only 4 Points or 2 Points and Segment or 2 Segments*/
	}
	default:
		return;
	}
}

void CORE::AddRule(unsigned type)
{
	switch (type)
	{
	case PPPONL:
	{
		switch (_selected_objects.size())
		{
		case 2:
		{
			_selected_objects.rewind();
			Point* obj1 = dynamic_cast<Point*>(_selected_objects.get());
			if (obj1)
			{
				_selected_objects.moveNext();
				Segment* obj2 = dynamic_cast<Segment*>(_selected_objects.get());
				if (obj2)
				{
					ThreePoints* rule = new ThreePoints(obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y);
					_storage_of_constraints.add(rule);
					return;
				}
			}
			Segment* ob2 = dynamic_cast<Segment*>(_selected_objects.get());
			if (ob2)
			{
				_selected_objects.moveNext();
				Point* ob1 = dynamic_cast<Point*>(_selected_objects.get());
				if (ob1)
				{
					ThreePoints* rule = new ThreePoints(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y);
					_storage_of_constraints.add(rule);
					return;
				}
			}
			return;
		}
		case 3:
		{
			_selected_objects.rewind();
			Point* o1 = dynamic_cast<Point*>(_selected_objects.get());
			if (o1)
			{
				_selected_objects.moveNext();
				Point* o2 = dynamic_cast<Point*>(_selected_objects.get());
				if (o2)
				{
					_selected_objects.moveNext();
					Point* o3 = dynamic_cast<Point*>(_selected_objects.get());
					if (o3)
					{
						ThreePoints* rule = new ThreePoints(o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y);
						_storage_of_constraints.add(rule);
						return;
					}
				}
			}
			return;
		}
		default:
			return;
		}
	}
	default:
		return;
	}
}

void CORE::ChangeStatus(double x, double y, unsigned char status_key)
{
	/*Try to search points in small radius*/
	/*unsigned size = _storage_of_points.size();
	double min = 2;
	int min_i = -1;
	//for (unsigned i = 0; i < size; i++)
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
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
	/*if (min_k >= 0)
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
	return;*/
}

void CORE::Select(double x, double y)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 2;
	int min_i = -1;
	unsigned j = 0;
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext(), j++)
	{
		if (length(*i.getValue()._x, *i.getValue()._y, x, y) < min)
		{
			min = length(*i.getValue()._x, *i.getValue()._y, x, y);
			min_i = j;
		}
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	j = 0;
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext(), j++)
	{
		if (length(*i.getValue()._p1->_x, *i.getValue()._p1->_y, x, y) < min)
		{
			min = length(*i.getValue()._p1->_x, *i.getValue()._p1->_y, x, y);
			min_j = j;
		}
	}
	size = _storage_of_circles.size();
	int min_k = -1;
	j = 0;
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext(), j++)
	{
		if (length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) < min)
		{
			min = length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y);
			min_k = j;
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
	if (min_i >= 0)
	{
		unsigned j = 0;
		ListViewer<Point> i(_storage_of_points);
		for (; j < min_i; i.moveNext())
		{
			j++;
		}
		i.getValue().changeSelect();
		_selected_objects.add(&i.getValue());
	}
	else
	{
		if (min_j >= 0)
		{
			unsigned j = 0;
			ListViewer<Segment> i(_storage_of_segments);
			for (; j < min_i; i.moveNext())
			{
				j++;
			}
			i.getValue().changeSelect();
			_selected_objects.add(&i.getValue());
		}
		else
		{
			if (min_k >= 0)
			{
				unsigned j = 0;
				ListViewer<Circle> i(_storage_of_circles);
				for (; j < min_i; i.moveNext())
				{
					j++;
				}
				i.getValue().changeSelect();
				_selected_objects.add(&i.getValue());
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
	/*unsigned size = _storage_of_points.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_points[i]._x, *_storage_of_points[i]._y, x1, y1, x2, y2))
		{
			//change status
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (unsigned i = 0; i < size; i++)
	{
		if (isInArea(*_storage_of_segments[i]._p1->_x, *_storage_of_segments[i]._p1->_y, x1, y1, x2, y2) &&
			 isInArea(*_storage_of_segments[i]._p2->_x, *_storage_of_segments[i]._p2->_y, x1, y1, x2, y2))
		{
			//change status
		}
	}
	return;*/
}

void CORE::Select(double x1, double y1, double x2, double y2)
{
	// select points
	unsigned size = _storage_of_points.size();
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
	{
		if (isInArea(*i.getValue()._x, *i.getValue()._y, x1, y1, x2, y2))
		{
			i.getValue().changeSelect();
			_selected_objects.add(&i.getValue());
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext())
	{
		if (isInArea(*i.getValue()._p1->_x, *i.getValue()._p1->_y, x1, y1, x2, y2) &&
			isInArea(*i.getValue()._p2->_x, *i.getValue()._p2->_y, x1, y1, x2, y2))
		{
			i.getValue().changeSelect();
			_selected_objects.add(&i.getValue());
		}
	}
	// select circles
	size = _storage_of_circles.size();
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext())
	{
		if (isInArea(*i.getValue()._o->_x, *i.getValue()._o->_y, x1, y1, x2, y2))
		{
			i.getValue().changeSelect();
			_selected_objects.add(&i.getValue());
		}
	}
	return;
}

void CORE::ClearSelection()
{
	for (ListViewer< ObjectSkin* > i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		i.getValue()->changeSelect(false);
	}
}