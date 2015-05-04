#include "constraints\DistancePoint-Point.h"
#include "constraints\DistancePoint-Section.h"
#include "constraints\DistanceToTheLine.h"
#include "constraints\AngleSegment-Segment.h"
#include "constraints\ThreePointsOnTheLine.h"
#include "constraints\AspectRatio.h"
#include "constraints\Collector.h"
#include "constraints\CircleContact.h"

#include "core.h"

unsigned CORE::AddObject(double point_x, double point_y, Color color, unsigned id, bool wait)
{
	Point* p = new Point(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	p->color.setColor(color);
	_storage_of_points.add(*p);
	ID newid = _storage_of_objects.add(p, id);
	mygui->WriteStatus("Point added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x, "x= ", 2);
	writeToLog(point_y, "y= ", 2);
	writeToLog(color.getColor(), "color= ", 2);
	writeToLog(newid.getID(), "id= ", 2);
	writeToLog("< /add >", 2);
	if (!wait) Redraw();
	return newid.getID();
}
// add segment with current point's ids
unsigned CORE::AddObject(unsigned id1, unsigned id2, Color color, unsigned id, bool wait)
{
	Segment* s = new Segment(dynamic_cast<Point*>(_storage_of_objects.get(id1)), dynamic_cast<Point*>(_storage_of_objects.get(id2)));
	if (s->_p1 && s->_p2)
	{
		s->color.setColor(color);
		ID newid = _storage_of_objects.add(s, id);
		mygui->WriteStatus("Segment added");
		writeToLog("< add > Segment", 2);
		writeToLog(id1, "point 1 id= ", 2);
		writeToLog(id2, "point 2 id= ", 2);
		writeToLog(color.getColor(), "color= ", 2);
		writeToLog(newid.getID(), "id= ", 2);
		writeToLog("< /add >", 2);
		if (!wait) Redraw();
		return newid.getID();
	}
	writeToLog("Can't add segment with point's ids:", 2);
	writeToLog(id1, "point 1 id= ", 2);
	writeToLog(id2, "point 2 id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
}
// add circle with current point's id and radius
unsigned CORE::AddObject(unsigned pointid, double radius, Color color, unsigned id, bool wait)
{
	Circle* c = new Circle(dynamic_cast<Point*>(_storage_of_objects.get(pointid)), _storage_of_parameters.add(radius));
	if (c->_o)
	{
		c->color.setColor(color);
		ID newid = _storage_of_objects.add(c, id);
		mygui->WriteStatus("Circle added");
		writeToLog("< add > Circle", 2);
		writeToLog(pointid, "point id= ", 2);
		writeToLog(radius, "radius= ", 2);
		writeToLog(color.getColor(), "color= ", 2);
		writeToLog(newid.getID(), "id= ", 2);
		writeToLog("< /add >", 2);
		if (!wait) Redraw();
		return newid.getID();
	}
	writeToLog("Can't add circle with point's id:", 2);
	writeToLog(pointid, "point id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
}
void CORE::AddObject(double point_x1, double point_y1, double point_x2, double point_y2, Color color, unsigned id)
{
	Point* p1 = new Point(_storage_of_parameters.add(point_x1), _storage_of_parameters.add(point_y1));
	Point* p2 = new Point(_storage_of_parameters.add(point_x2), _storage_of_parameters.add(point_y2));
	Segment* s = new Segment(p1, p2);
	s->color.setColor(color);
	_storage_of_points.add(*p1);
	_storage_of_points.add(*p2);
	_storage_of_segments.add(*s);
	_storage_of_objects.add(p1);
	_storage_of_objects.add(p2);
	_storage_of_objects.add(s);
	mygui->WriteStatus("Segment added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x1, "x1= ", 2);
	writeToLog(point_y1, "y1= ", 2);
	writeToLog(point_x2, "x2= ", 2);
	writeToLog(point_y2, "y2= ", 2);
	writeToLog(color.getColor(), "color= ", 2);
	writeToLog(id, "id= ", 2);
	writeToLog("< /add >", 2);
	Redraw();
}

void CORE::AddObject(double point_x, double point_y, double radius, Color color, unsigned id)
{
	Point* p = new Point(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	Circle* c = new Circle(p, _storage_of_parameters.add(radius));
	c->color.setColor(color);
	_storage_of_points.add(*p);
	_storage_of_circles.add(*c);
	_storage_of_objects.add(p);
	_storage_of_objects.add(c);
	mygui->WriteStatus("Circle added");
	writeToLog("< add > Circle", 2);
	writeToLog(point_x, "x= ", 2);
	writeToLog(point_y, "y= ", 2);
	writeToLog(radius, "r= ", 2);
	writeToLog(color.getColor(), "color= ", 2);
	writeToLog(id, "id= ", 2);
	writeToLog("< /add >", 2);
	Redraw();
}

void CORE::ConcatenatePoints()
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Point* obj = dynamic_cast<Point*>(k.getValue());
		k.moveNext();
		Point* obj1 = dynamic_cast<Point*>(k.getValue());
		if (obj && obj1)
		{
			Segment* s = new Segment(obj, obj1);
			s->color.setColor(COLORDEF);
			_storage_of_objects.add(s);
			writeToLog("Concatenate points", 2);
			ClearSelection();
		}
	}
}

void CORE::AddRule(unsigned type, double value)
{
	switch (type)
	{
	case CONSTR_P2PDIST:
	{ // may add multiselect for points and segments
		switch (_selected_objects.size())
		{
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			k.moveNext();
			Point* obj2 = dynamic_cast<Point*>(k.getValue());
			if (obj1 && obj2)
			{
				double* val = _storage_of_constants.add(value);
				Point2Point* rule = new Point2Point(obj1->_x, obj1->_y, obj2->_x, obj2->_y, val);
				_storage_of_constraints.add(rule);
				double *param[5] = { obj1->_x, obj1->_y, obj2->_x, obj2->_y, val };
				_storage_of_constraint.add(rule, *param);
				mygui->WriteStatus("Rule added");
				Calculate();
			}
			return;
		}
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
	}
	case CONSTR_P2SECTDIST:
	{
		switch (_selected_objects.size())
		{
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			if (obj1)
			{
				k.moveNext();
				Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
				if (obj2)
				{
					double* val = _storage_of_constants.add(value);
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(
						obj1->_x, obj1->_y, obj2->_p1->_x, obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, val);
					_storage_of_constraints.add(rule);
					double *(param[7]) = { obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, val };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
			if (ob2)
			{
				k.moveNext();
				Point* ob1 = dynamic_cast<Point*>(k.getValue());
				if (ob1)
				{
					double* val = _storage_of_constants.add(value);
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, val);
					_storage_of_constraints.add(rule);
					double *param[7] = { ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, val };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			return;
		}
		case 3:

			return;
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
	}
	case CONSTR_P2LINEDIST:
	{
		switch (_selected_objects.size())
		{
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			if (obj1)
			{
				k.moveNext();
				Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
				if (obj2)
				{
					double* val = _storage_of_constants.add(value);
					DistanceToTheLine* rule = new DistanceToTheLine(obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, val);
					_storage_of_constraints.add(rule);
					double *param[7] = { obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, val };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
			if (ob2)
			{
				k.moveNext();
				Point* ob1 = dynamic_cast<Point*>(k.getValue());
				if (ob1)
				{
					double* val = _storage_of_constants.add(value);
					DistanceToTheLine* rule = new DistanceToTheLine(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, val);
					_storage_of_constraints.add(rule);
					double *param[7] = { ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, val };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			return;
		}
		case 3:

			return;
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
	}
	case CONSTR_L2LANGLE:
	{
		switch (_selected_objects.size())
		{
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Segment* obj1 = dynamic_cast<Segment*>(k.getValue());
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
			if (obj1 && obj2)
			{
				double* val = _storage_of_constants.add(value);
				AngleSegmentSegment* rule = new AngleSegmentSegment(
					obj1->_p1->_x, obj1->_p1->_y,
					obj1->_p2->_x, obj1->_p2->_y,
					obj2->_p1->_x, obj2->_p1->_y,
					obj2->_p2->_x, obj2->_p2->_y,
					val);
				_storage_of_constraints.add(rule);
				double* param[9] = {
					obj1->_p1->_x, obj1->_p1->_y,
					obj1->_p2->_x, obj1->_p2->_y,
					obj2->_p1->_x, obj2->_p1->_y,
					obj2->_p2->_x, obj2->_p2->_y,
					val };
				_storage_of_constraint.add(rule, *param);
				mygui->WriteStatus("Rule added");
				Calculate();
			}
			return;
		}
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
		/*Picked only 4 Points or 2 Points and Segment or 2 Segments*/
	}
	case CONSTR_3PRATIO:
	{
		switch (_selected_objects.size())
		{
		case 3:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* o1 = dynamic_cast<Point*>(k.getValue());
			if (o1)
			{
				k.moveNext();
				Point* o2 = dynamic_cast<Point*>(k.getValue());
				if (o2)
				{
					k.moveNext();
					Point* o3 = dynamic_cast<Point*>(k.getValue());
					if (o3)
					{
						double* val = _storage_of_constants.add(value);
						AspectRatio* rule = new AspectRatio(o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y, val);
						_storage_of_constraints.add(rule);
						double* param[7] = { o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y, val };
						_storage_of_constraint.add(rule, *param);
						mygui->WriteStatus("Rule added");
						Calculate();
						return;
					}
				}
			}
			return;
		}
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
	}
	default:
	{
		mygui->WriteStatus("Wrong type of rule.");
		return;
	}
	}
}

void CORE::AddRule(unsigned type)
{
	switch (type)
	{
	case CONSTR_3PONLINE:
	{
		switch (_selected_objects.size())
		{
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			if (obj1)
			{
				k.moveNext();
				Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
				if (obj2)
				{
					ThreePoints* rule = new ThreePoints(obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y);
					_storage_of_constraints.add(rule);
					double* param[6] = { obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
			if (ob2)
			{
				k.moveNext();
				Point* ob1 = dynamic_cast<Point*>(k.getValue());
				if (ob1)
				{
					ThreePoints* rule = new ThreePoints(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y);
					_storage_of_constraints.add(rule);
					double* param[6] = { ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;
				}
			}
			return;
		}
		case 3:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* o1 = dynamic_cast<Point*>(k.getValue());
			if (o1)
			{
				k.moveNext();
				Point* o2 = dynamic_cast<Point*>(k.getValue());
				if (o2)
				{
					k.moveNext();
					Point* o3 = dynamic_cast<Point*>(k.getValue());
					if (o3)
					{
						ThreePoints* rule = new ThreePoints(o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y);
						_storage_of_constraints.add(rule);
						double* param[6] = { o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y };
						_storage_of_constraint.add(rule, *param);
						mygui->WriteStatus("Rule added");
						Calculate();
						return;
					}
				}
			}
			return;
		}
		default:
		{
			mygui->WriteStatus("Wrong select.");
			return;
		}
		}
	}
	case CONSTR_EXCONTACT:
	{
		if (_selected_objects.size() == 2)
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* o1 = dynamic_cast<Point*>(k.getValue());
			if (o1)
			{
				k.moveNext();
				Point* o2 = dynamic_cast<Point*>(k.getValue());
				if (o2)
				{
					k.moveNext();
					Point* o3 = dynamic_cast<Point*>(k.getValue());
					if (o3)
					{
						ThreePoints* rule = new ThreePoints(o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y);
						_storage_of_constraints.add(rule);
						double* param[6] = { o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y };
						_storage_of_constraint.add(rule, *param);
						mygui->WriteStatus("Rule added");
						Calculate();
						return;
					}
				}
			}
		}
		return;
	}
	default:
	{
		mygui->WriteStatus("Wrong type of rule.");
		return;
	}
	}
}
