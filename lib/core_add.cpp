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
	double* x = new double;
	_parameters.add(x, false);
	double* y = new double;
	_parameters.add(y, false);
	*x = point_x;
	*y = point_y;
	Point* p = new Point(x, y);
	p->color.setColor(color);
	// _storage_of_points.add(*p);
	ID newid = _storage_of_objects.add(p, id);
	mygui->WriteStatus("Done");
	mygui->WriteMessage("Point added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x, "x= ", 2);
	writeToLog(point_y, "y= ", 2);
	writeToLog(color.getColor(), "color= ", 2);
	writeToLog(newid.getID(), "id= ", 2);
	writeToLog("< /add >", 2);
	if (!wait) mygui->DrawPoint(newid.getID(), point_x, point_y, color);

	return newid.getID();
}
// add segment with current point's ids
unsigned CORE::AddObject(unsigned id1, unsigned id2, Color color, unsigned id, bool wait)
{
	Segment* s = new Segment(dynamic_cast<Point*>(_storage_of_objects.get(id1)), dynamic_cast<Point*>(_storage_of_objects.get(id2)));
	if (s->p1 && s->p2)
	{
		s->color.setColor(color);
		ID newid = _storage_of_objects.add(s, id);
		mygui->WriteStatus("Done");
		mygui->WriteMessage("Segment added");
		writeToLog("< add > Segment", 2);
		writeToLog(id1, "point 1 id= ", 2);
		writeToLog(id2, "point 2 id= ", 2);
		writeToLog(color.getColor(), "color= ", 2);
		writeToLog(newid.getID(), "id= ", 2);
		writeToLog("< /add >", 2);
		if (!wait) mygui->DrawSegment(newid.getID(), *s->p1->x, *s->p1->y, *s->p2->x, *s->p2->y, color);

		return newid.getID();
	}
	else
		delete s;
	writeToLog("Can't add segment with point's ids:", 2);
	writeToLog(id1, "point 1 id= ", 2);
	writeToLog(id2, "point 2 id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
}
// add circle with current point's id and radius
unsigned CORE::AddObject(unsigned pointid, double radius, Color color, unsigned id, bool wait)
{
	double *r = new double;
	*r = radius;
	Circle* c = new Circle(dynamic_cast<Point*>(_storage_of_objects.get(pointid)), r);
	if (c->p)
	{
		_parameters.add(r, false);
		c->color.setColor(color);
		ID newid = _storage_of_objects.add(c, id);
		mygui->WriteStatus("Done");
		mygui->WriteMessage("Circle added");
		writeToLog("< add > Circle", 2);
		writeToLog(pointid, "point id= ", 2);
		writeToLog(radius, "radius= ", 2);
		writeToLog(color.getColor(), "color= ", 2);
		writeToLog(newid.getID(), "id= ", 2);
		writeToLog("< /add >", 2);
		if (!wait) mygui->DrawCircle(newid.getID(), *c->p->x, *c->p->y, radius, color);

		return newid.getID();
	}
	else
	{
		delete c;
		delete r;
	}
	writeToLog("Can't add circle with point's id:", 2);
	writeToLog(pointid, "point id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
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
		{
			if (addc_p2pdist(value))
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_P2SECTDIST:
		{
			if (addc_p2sdist(value))
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_P2LINEDIST:
		{
			if (addc_p2ldist(value))
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_L2LANGLE:
		{
			if (addc_l2langle(value))
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_3PRATIO:
		{
			if (addc_3pratio(value))
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_3PONLINE:
		{
			if (addc_3ponline())
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		case CONSTR_EXCONTACT:
		{
			if (addc_excontact())
			{
				mygui->WriteStatus("Done");
				mygui->WriteMessage("Rule added");
			}
			else
			{
				mygui->WriteStatus("Error");
				mygui->WriteMessage("Can't add rule to these objects.");
			}
		}
		default:
		{
			mygui->WriteStatus("FATAL ERROR");
			mygui->WriteMessage("Wrong type of rule.");
			return;
		}
	}
}

void CORE::AddRule(unsigned type, unsigned id1, unsigned id2, unsigned id3, double value)
{

}

bool CORE::addc_p2pdist(double value)
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue());
		k.moveNext();
		Point* obj2 = dynamic_cast<Point*>(k.getValue());
		if (obj1 && obj2)
		{
			double* val = new double;
			*val = value;
			_parameters.add(val, true);
			Point2Point* rule = new Point2Point(obj1->x, obj1->y, obj2->x, obj2->y, val);
			double *param[5] = { obj1->x, obj1->y, obj2->x, obj2->y, val };
			_storage_of_constraint.add(rule, *param);
			return true;
		}
	}
	return false;
}
bool CORE::addc_3ponline()
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue());
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
			if (obj2)
			{
				ThreePoints* rule = new ThreePoints(obj1->x, obj1->y, obj2->p1->x,
																obj2->p1->y, obj2->p2->x, obj2->p2->y);
				double* param[6] = { obj1->x, obj1->y, obj2->p1->x,
					obj2->p1->y, obj2->p2->x, obj2->p2->y };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue());
			if (ob1)
			{
				ThreePoints* rule = new ThreePoints(ob1->x, ob1->y, ob2->p1->x,
																ob2->p1->y, ob2->p2->x, ob2->p2->y);
				double* param[6] = { ob1->x, ob1->y, ob2->p1->x,
					ob2->p1->y, ob2->p2->x, ob2->p2->y };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
		}
		return false;
	}
	else if (_selected_objects.size() == 3)
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
					ThreePoints* rule = new ThreePoints(o1->x, o1->y, o2->x,
																	o2->y, o3->x, o3->y);
					double* param[6] = { o1->x, o1->y, o2->x,
						o2->y, o3->x, o3->y };
					_storage_of_constraint.add(rule, *param);
					return true;
				}
			}

		}
	}
	return false;
}
bool CORE::addc_3pratio(double value)
{
	if (_selected_objects.size() == 3)
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
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					AspectRatio* rule = new AspectRatio(o1->x, o1->y, o2->x,
																	o2->y, o3->x, o3->y, val);
					double* param[7] = { o1->x, o1->y, o2->x,
						o2->y, o3->x, o3->y, val };
					_storage_of_constraint.add(rule, *param);
					return true;
				}
			}
		}
	}
	return false;
}
bool CORE::addc_excontact()
{
	return false;
}
bool CORE::addc_l2langle(double value)
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Segment* obj1 = dynamic_cast<Segment*>(k.getValue());
		k.moveNext();
		Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
		if (obj1 && obj2)
		{
			double* val = new double;
			*val = value;
			_parameters.add(val, true);
			AngleSegmentSegment* rule = new AngleSegmentSegment(
				obj1->p1->x, obj1->p1->y,
				obj1->p2->x, obj1->p2->y,
				obj2->p1->x, obj2->p1->y,
				obj2->p2->x, obj2->p2->y,
				val);
			double* param[9] = {
				obj1->p1->x, obj1->p1->y,
				obj1->p2->x, obj1->p2->y,
				obj2->p1->x, obj2->p1->y,
				obj2->p2->x, obj2->p2->y,
				val };
			_storage_of_constraint.add(rule, *param);
			return true;
		}
	}
	return false;
}
bool CORE::addc_p2ldist(double value)
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue());
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
			if (obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceToTheLine* rule = new DistanceToTheLine(obj1->x, obj1->y, obj2->p1->x,
																				obj2->p1->y, obj2->p2->x, obj2->p2->y, val);
				double *param[7] = { obj1->x, obj1->y, obj2->p1->x,
					obj2->p1->y, obj2->p2->x, obj2->p2->y, val };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
			return false;
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue());
			if (ob1)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceToTheLine* rule = new DistanceToTheLine(ob1->x, ob1->y, ob2->p1->x,
																				ob2->p1->y, ob2->p2->x, ob2->p2->y, val);
				double *param[7] = { ob1->x, ob1->y, ob2->p1->x,
					ob2->p1->y, ob2->p2->x, ob2->p2->y, val };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
		}
	}
	return false;
}
bool CORE::addc_p2sdist(double value)
{
	if (_selected_objects.size() == 2)
	{
		ListViewer<ObjectSkin*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue());
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue());
			if (obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceFromPointToSection* rule = new DistanceFromPointToSection(
					obj1->x, obj1->y, obj2->p1->x, obj2->p1->y, obj2->p2->x, obj2->p2->y, val);
				double *(param[7]) = { obj1->x, obj1->y, obj2->p1->x,
					obj2->p1->y, obj2->p2->x, obj2->p2->y, val };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
			return false;
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue());
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue());
			if (ob1)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->x, ob1->y, ob2->p1->x,
																										ob2->p1->y, ob2->p2->x, ob2->p2->y, val);
				double *param[7] = { ob1->x, ob1->y, ob2->p1->x,
					ob2->p1->y, ob2->p2->x, ob2->p2->y, val };
				_storage_of_constraint.add(rule, *param);
				return true;
			}
		}
	}
	return false;
}