#include "constraints/DistancePoint-Point.h"
#include "constraints/DistancePoint-Section.h"
#include "constraints/DistanceToTheLine.h"
#include "constraints/AngleSegment-Segment.h"
#include "constraints/ThreePointsOnTheLine.h"
#include "constraints/AspectRatio.h"
#include "constraints/Collector.h"
#include "constraints/CircleContact.h"
#include "constraints/ParallelLines.h"
#include "constraints/OrthogonalLines.h"

#include "core.h"
#include "qstring.h"

unsigned CORE::AddObject(double point_x, bool isconstx, double point_y, bool isconsty, Color color, unsigned id, bool wait)
{
	double* x = new double;
	_parameters.add(x, isconstx);
	double* y = new double;
	_parameters.add(y, isconsty);
	*x = point_x;
	*y = point_y;
	Point* p = new Point(x, y);
	p->color.setColor(color);
	ID newid = _storage_of_objects.add(p, id);
	mygui->WriteText(DONESTRING, "Point added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x, "x= ", 2);
	writeToLog(point_y, "y= ", 2);
	writeToLog(color.getColor(), "color= ", 2);
	writeToLog(newid.getID(), "id= ", 2);
	writeToLog("< /add >", 2);
	if (!wait) mygui->DrawPoint(newid.getID(), point_x, point_y, color, false);
	return newid.getID();
}
// add segment with current point's ids
unsigned CORE::AddObject(unsigned id1, unsigned id2, Color color, unsigned id, bool wait)
{
	Point* p1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
	if (p1)
	{
		Point* p2 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
		if (p2)
		{
			Segment* s = new Segment(p1, p2);
			s->color.setColor(color);
			ID newid = _storage_of_objects.add(s, id);
			mygui->WriteText(DONESTRING, "Segment added");
			writeToLog("< add > Segment", 2);
			writeToLog(id1, "point 1 id= ", 2);
			writeToLog(id2, "point 2 id= ", 2);
			writeToLog(color.getColor(), "color= ", 2);
			writeToLog(newid.getID(), "id= ", 2);
			writeToLog("< /add >", 2);
			if (!wait)	mygui->DrawSegment(newid.getID(), *s->p1->x, *s->p1->y, *s->p2->x, *s->p2->y, color, false);

			return newid.getID();
		}
	}
	writeToLog("Can't add segment with point's ids:", 2);
	writeToLog(id1, "point 1 id= ", 2);
	writeToLog(id2, "point 2 id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
}
// add circle with current point's id and radius
unsigned CORE::AddObject(unsigned pointid, double radius, bool isconst, Color color, unsigned id, bool wait)
{
	Point* p = dynamic_cast<Point*>(_storage_of_objects.get(pointid));
	if (p)
	{
		double *r = new double;
		*r = radius;
		Circle* c = new Circle(p, r);
		_parameters.add(r, isconst);
		c->color.setColor(color);
		ID newid = _storage_of_objects.add(c, id);
		mygui->WriteText(DONESTRING, "Circle added");
		writeToLog("< add > Circle", 2);
		writeToLog(pointid, "point id= ", 2);
		writeToLog(radius, "radius= ", 2);
		writeToLog(color.getColor(), "color= ", 2);
		writeToLog(newid.getID(), "id= ", 2);
		writeToLog("< /add >", 2);
		if (!wait)	mygui->DrawCircle(newid.getID(), *c->p->x, *c->p->y, radius, color, false);

		return newid.getID();
	}
	writeToLog("Can't add circle with point's id:", 2);
	writeToLog(pointid, "point id= ", 2);
	writeToLog("return id= 0", 2);
	return 0;
}

void CORE::CreateSegment()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj = dynamic_cast<Point*>(k.getValue().value);
		k.moveNext();
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		if (obj && obj1)
		{
			Segment* s = new Segment(obj, obj1);
			s->color.setColor(COLORDEF);
			_storage_of_objects.add(s);
			writeToLog("Concatenate points", 2);
			mygui->WriteText(DONESTRING, "Segment added");
			ClearSelection();
		}
		else
		{
			mygui->WriteError("Select two points before creating segment.");
		}
	}
	else
	{
		mygui->WriteError("Select two points before creating segment.");
	}
}

void CORE::CreateCircle(double value, bool isconst)
{
	if (_selected_objects.size() == 1)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj = dynamic_cast<Point*>(k.getValue().value);
		if (obj)
		{
			double* val = new double;
			*val = value;
			_parameters.add(val, isconst);
			Circle* c = new Circle(obj, val);
			c->color.setColor(COLORDEF);
			_storage_of_objects.add(c);
			mygui->WriteText(DONESTRING, "Circle added");
			ClearSelection();
		}
	}
	else
	{
		mygui->WriteError("Select point before creating circle.");
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
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_P2SECTDIST:
		{
			if (addc_p2sdist(value))
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_P2LINEDIST:
		{
			if (addc_p2ldist(value))
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_L2LANGLE:
		{
			if (addc_l2langle(value))
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_3PRATIO:
		{
			if (addc_3pratio(value))
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_3PONLINE:
		{
			if (addc_3ponline())
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_EXCONTACT:
		{
			if (addc_excontact())
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_INCONTACT:
		{
			if (addc_incontact())
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_SPRATIO:
		{
			if (addc_spratio(value))
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_PARALLELISM:
		{
			if (addc_parallelism())
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		case CONSTR_ORTHOGONALITY:
		{
			if (addc_orthogonality())
			{
				mygui->WriteText(DONESTRING, "Rule added");
			}
			else
			{
				mygui->WriteText("Error", "Can't add rule to these objects.");
				mygui->WriteError("Can't add rule to these objects.");
				return;
			}
			break;
		}
		default:
		{
			mygui->WriteText("FATAL ERROR", "Wrong type of rule.");
			mygui->WriteError("FATAL ERROR: Wrong type of rule");
			return;
		}
	}
}

bool CORE::AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2)
{
	switch (type)
	{
		case CONSTR_EXCONTACT:
		{
			Circle* o1 = dynamic_cast<Circle*>(_storage_of_objects.get(id1));
			if (o1)
			{
				Circle* o2 = dynamic_cast<Circle*>(_storage_of_objects.get(id2));
				if (o2)
				{

					ExternalContactCircle* rule = new ExternalContactCircle(o1->p->x, o1->p->y,
																							  o2->p->x, o2->p->y,
																							  o1->r, o2->r);
					
					_storage_of_constraints.add(o1, rule);
					_storage_of_constraints.add(o2, rule);
					return true;
				}
			}
			break;
		}
		case CONSTR_INCONTACT:
		{
			Circle* o1 = dynamic_cast<Circle*>(_storage_of_objects.get(id1));
			if (o1)
			{
				Circle* o2 = dynamic_cast<Circle*>(_storage_of_objects.get(id2));
				if (o2)
				{

					InternalContactCircle* rule = new InternalContactCircle(o1->p->x, o1->p->y,
																							  o2->p->x, o2->p->y,
																							  o1->r, o2->r);
					
					_storage_of_constraints.add(o1, rule);
					_storage_of_constraints.add(o2, rule);
					return true;
				}
			}
			break;
		}
		case CONSTR_ORTHOGONALITY:
		{
			Segment* obj1 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
			if (obj1 && obj2)
			{
				OrthogonalLines* rule = new OrthogonalLines(obj1->p1->x, obj1->p1->y,
																		  obj1->p2->x, obj1->p2->y,
																		  obj2->p1->x, obj2->p1->y,
																		  obj2->p2->x, obj2->p2->y);

				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			break;
		}
		case CONSTR_PARALLELISM:
		{
			Segment* obj1 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
			if (obj1 && obj2)
			{
				ParallelLines* rule = new ParallelLines(obj1->p1->x, obj1->p1->y,
																	 obj1->p2->x, obj1->p2->y,
																	 obj2->p1->x, obj2->p1->y,
																	 obj2->p2->x, obj2->p2->y);

				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			break;
		}

	}
	return false;
}

bool CORE::AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, double value)
{
	switch (type)
	{
		case CONSTR_P2PDIST:
		{
			Point* obj1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			Point* obj2 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
			if (obj1 && obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				Point2Point* rule = new Point2Point(obj1->x, obj1->y,
																obj2->x, obj2->y,
																val);
				
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			break;
		}
		case CONSTR_P2SECTDIST:
		{
			Point* obj1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			if (obj1)
			{
				Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
				if (obj2)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(obj1->x, obj1->y,
																											obj2->p1->x, obj2->p1->y,
																											obj2->p2->x, obj2->p2->y,
																											val);
					
					_storage_of_constraints.add(obj1, rule);
					_storage_of_constraints.add(obj2, rule);
					return true;
				}
				return false;
			}
			Segment* ob2 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			if (ob2)
			{
				Point* ob1 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
				if (ob1)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->x, ob1->y,
																											ob2->p1->x, ob2->p1->y,
																											ob2->p2->x, ob2->p2->y,
																											val);
					
					_storage_of_constraints.add(ob1, rule);
					_storage_of_constraints.add(ob2, rule);
					return true;
				}
			}
			break;
		}
		case CONSTR_P2LINEDIST:
		{
			Point* obj1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			if (obj1)
			{
				Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
				if (obj2)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					DistanceToTheLine* rule = new DistanceToTheLine(obj1->x, obj1->y,
																					obj2->p1->x, obj2->p1->y,
																					obj2->p2->x, obj2->p2->y,
																					val);
					
					_storage_of_constraints.add(obj1, rule);
					_storage_of_constraints.add(obj2, rule);
					return true;
				}
				return false;
			}
			Segment* ob2 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			if (ob2)
			{
				Point* ob1 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
				if (ob1)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					DistanceToTheLine* rule = new DistanceToTheLine(ob1->x, ob1->y,
																					ob2->p1->x, ob2->p1->y,
																					ob2->p2->x, ob2->p2->y,
																					val);
					
					_storage_of_constraints.add(ob1, rule);
					_storage_of_constraints.add(ob2, rule);
					return true;
				}
			}
			break;
		}
		case CONSTR_L2LANGLE:
		{
			Segment* obj1 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
			if (obj1 && obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				AngleSegmentSegment* rule = new AngleSegmentSegment(obj1->p1->x, obj1->p1->y,
																					 obj1->p2->x, obj1->p2->y,
																					 obj2->p1->x, obj2->p1->y,
																					 obj2->p2->x, obj2->p2->y,
																					 val);
				
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			break;
		}
		case CONSTR_SPRATIO:
		{
			Point* obj1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			if (obj1)
			{
				Segment* obj2 = dynamic_cast<Segment*>(_storage_of_objects.get(id2));
				if (obj2)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					AspectRatio* rule = new AspectRatio(obj2->p1->x, obj2->p1->y,
																	obj1->x, obj1->y,
																	obj2->p2->x, obj2->p2->y,
																	val);
					
					_storage_of_constraints.add(obj1, rule);
					_storage_of_constraints.add(obj2, rule);
					return true;
				}
			}
			Segment* ob2 = dynamic_cast<Segment*>(_storage_of_objects.get(id1));
			if (ob2)
			{
				Point* ob1 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
				if (ob1)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					AspectRatio* rule = new AspectRatio(ob2->p1->x, ob2->p1->y,
																	ob1->x, ob1->y,
																	ob2->p2->x, ob2->p2->y,
																	val);
					
					_storage_of_constraints.add(ob1, rule);
					_storage_of_constraints.add(ob2, rule);
					return true;
				}
			}
			break;
		}
	}
	return false;
}

bool CORE::AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3, double value)
{
	switch (type)
	{
		case CONSTR_3PRATIO:
		{
			Point* o1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			if (o1)
			{
				Point* o2 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
				if (o2)
				{
					Point* o3 = dynamic_cast<Point*>(_storage_of_objects.get(id3));
					if (o3)
					{
						double* val = new double;
						*val = value;
						_parameters.add(val, true);
						AspectRatio* rule = new AspectRatio(o1->x, o1->y,
																		o2->x, o2->y,
																		o3->x, o3->y,
																		val);
						
						_storage_of_constraints.add(o1, rule);
						_storage_of_constraints.add(o2, rule);
						_storage_of_constraints.add(o3, rule);
						return true;
					}
				}
			}
			break;
		}
	}
	return false;
}

bool CORE::AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3)
{
	switch (type)
	{
		case CONSTR_3PONLINE:
		{
			Point* o1 = dynamic_cast<Point*>(_storage_of_objects.get(id1));
			if (o1)
			{
				Point* o2 = dynamic_cast<Point*>(_storage_of_objects.get(id2));
				if (o2)
				{
					Point* o3 = dynamic_cast<Point*>(_storage_of_objects.get(id3));
					if (o3)
					{
						ThreePoints* rule = new ThreePoints(o1->x, o1->y,
																		o2->x, o2->y,
																		o3->x, o3->y);
						
						_storage_of_constraints.add(o1, rule);
						_storage_of_constraints.add(o2, rule);
						_storage_of_constraints.add(o3, rule);
						return true;
					}
				}

			}
			break;
		}
	}
	return false;
}

bool CORE::ChangePoint(unsigned id, 
							  double point_x, bool isconstx,
							  double point_y, bool isconsty,
							  Color color)
{
	Point* p = dynamic_cast<Point*>(_storage_of_objects.get(id));
	if (p)
	{
		writeToLog(id, "Change point properties ", 2);
		*p->x = point_x;
		*p->y = point_y;
		_parameters.getValuebyKey(p->x) = isconstx;
		_parameters.getValuebyKey(p->y) = isconsty;
		p->color = color;
		Redraw(mygui);
		return true;
	}
	return false;
}

bool CORE::ChangeSegment(unsigned id,
								 double point_x1, bool isconstx1,
								 double point_y1, bool isconsty1,
								 double point_x2, bool isconstx2,
								 double point_y2, bool isconsty2,
								 Color color)
{
	Segment* s = dynamic_cast<Segment*>(_storage_of_objects.get(id));
	if (s)
	{
		writeToLog(id, "Change segment properties ", 2);
		*s->p1->x = point_x1;
		*s->p1->y = point_y1;
		*s->p2->x = point_x2;
		*s->p2->y = point_y2;
		_parameters.getValuebyKey(s->p1->x) = isconstx1;
		_parameters.getValuebyKey(s->p1->y) = isconsty1;
		_parameters.getValuebyKey(s->p2->x) = isconstx2;
		_parameters.getValuebyKey(s->p2->y) = isconsty2;
		s->color = color;
		Redraw(mygui);
		return true;
	}
	return false;
}

bool CORE::ChangeCircle(unsigned id,
								double point_x, bool isconstx,
								double point_y, bool isconsty,
								double radius, bool isconst,
								Color color)
{
	Circle* c = dynamic_cast<Circle*>(_storage_of_objects.get(id));
	if (c)
	{
		writeToLog(id, "Change segment properties ", 2);
		*c->p->x = point_x;
		*c->p->y = point_y;
		*c->r = radius;
		_parameters.getValuebyKey(c->p->x) = isconstx;
		_parameters.getValuebyKey(c->p->y) = isconsty;
		_parameters.getValuebyKey(c->r) = isconst;
		c->color = color;
		Redraw(mygui);
		return true;
	}
	return false;
}

bool CORE::addc_p2pdist(double value)
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		k.moveNext();
		Point* obj2 = dynamic_cast<Point*>(k.getValue().value);
		if (obj1 && obj2)
		{
			double* val = new double;
			*val = value;
			_parameters.add(val, true);
			Point2Point* rule = new Point2Point(obj1->x, obj1->y, 
															obj2->x, obj2->y,
															val);
			
			_storage_of_constraints.add(obj1, rule);
			_storage_of_constraints.add(obj2, rule);
			return true;
		}
	}
	return false;
}
bool CORE::addc_3ponline()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
			if (obj2)
			{
				ThreePoints* rule = new ThreePoints(obj1->x, obj1->y,
																obj2->p1->x, obj2->p1->y,
																obj2->p2->x, obj2->p2->y);
				
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue().value);
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue().value);
			if (ob1)
			{
				ThreePoints* rule = new ThreePoints(ob1->x, ob1->y,
																ob2->p1->x, ob2->p1->y,
																ob2->p2->x, ob2->p2->y);
				
				_storage_of_constraints.add(ob1, rule);
				_storage_of_constraints.add(ob2, rule);
				return true;
			}
		}
		return false;
	}
	else if (_selected_objects.size() == 3)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* o1 = dynamic_cast<Point*>(k.getValue().value);
		if (o1)
		{
			k.moveNext();
			Point* o2 = dynamic_cast<Point*>(k.getValue().value);
			if (o2)
			{
				k.moveNext();
				Point* o3 = dynamic_cast<Point*>(k.getValue().value);
				if (o3)
				{
					ThreePoints* rule = new ThreePoints(o1->x, o1->y,
																	o2->x, o2->y,
																	o3->x, o3->y);
					
					_storage_of_constraints.add(o1, rule);
					_storage_of_constraints.add(o2, rule);
					_storage_of_constraints.add(o3, rule);
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
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* o1 = dynamic_cast<Point*>(k.getValue().value);
		if (o1)
		{
			k.moveNext();
			Point* o2 = dynamic_cast<Point*>(k.getValue().value);
			if (o2)
			{
				k.moveNext();
				Point* o3 = dynamic_cast<Point*>(k.getValue().value);
				if (o3)
				{
					double* val = new double;
					*val = value;
					_parameters.add(val, true);
					AspectRatio* rule = new AspectRatio(o1->x, o1->y,
																	o2->x, o2->y,
																	o3->x, o3->y,
																	val);
					
					_storage_of_constraints.add(o1, rule);
					_storage_of_constraints.add(o2, rule);
					_storage_of_constraints.add(o3, rule);
					return true;
				}
			}
		}
	}
	return false;
}
bool CORE::addc_excontact()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Circle* o1 = dynamic_cast<Circle*>(k.getValue().value);
		if (o1)
		{
			k.moveNext();
			Circle* o2 = dynamic_cast<Circle*>(k.getValue().value);
			if (o2)
			{

				ExternalContactCircle* rule = new ExternalContactCircle(o1->p->x, o1->p->y,
																						  o2->p->x, o2->p->y,
																						  o1->r, o2->r);
				
				_storage_of_constraints.add(o1, rule);
				_storage_of_constraints.add(o2, rule);
				return true;
			}
		}
	}
	return false;
}
bool CORE::addc_incontact()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Circle* o1 = dynamic_cast<Circle*>(k.getValue().value);
		if (o1)
		{
			k.moveNext();
			Circle* o2 = dynamic_cast<Circle*>(k.getValue().value);
			if (o2)
			{

				InternalContactCircle* rule = new InternalContactCircle(o1->p->x, o1->p->y,
																						  o2->p->x, o2->p->y,
																						  o1->r, o2->r);
				
				_storage_of_constraints.add(o1, rule);
				_storage_of_constraints.add(o2, rule);
				return true;
			}
		}
	}
	return false;
}
bool CORE::addc_l2langle(double value)
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Segment* obj1 = dynamic_cast<Segment*>(k.getValue().value);
		k.moveNext();
		Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
		if (obj1 && obj2)
		{
			double* val = new double;
			*val = value;
			_parameters.add(val, true);
			AngleSegmentSegment* rule = new AngleSegmentSegment(obj1->p1->x, obj1->p1->y,
																				 obj1->p2->x, obj1->p2->y,
																				 obj2->p1->x, obj2->p1->y,
																				 obj2->p2->x, obj2->p2->y,
																				 val);
			
			_storage_of_constraints.add(obj1, rule);
			_storage_of_constraints.add(obj2, rule);
			return true;
		}
	}
	return false;
}
bool CORE::addc_p2ldist(double value)
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
			if (obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceToTheLine* rule = new DistanceToTheLine(obj1->x, obj1->y,
																				obj2->p1->x, obj2->p1->y,
																				obj2->p2->x, obj2->p2->y,
																				val);
				
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			return false;
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue().value);
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue().value);
			if (ob1)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceToTheLine* rule = new DistanceToTheLine(ob1->x, ob1->y,
																				ob2->p1->x, ob2->p1->y,
																				ob2->p2->x, ob2->p2->y,
																				val);
				
				_storage_of_constraints.add(ob1, rule);
				_storage_of_constraints.add(ob2, rule);
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
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
			if (obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceFromPointToSection* rule = new DistanceFromPointToSection(obj1->x, obj1->y,
																										obj2->p1->x, obj2->p1->y,
																										obj2->p2->x, obj2->p2->y,
																										val);
				
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2, rule);
				return true;
			}
			return false;
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue().value);
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue().value);
			if (ob1)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->x, ob1->y,
																										ob2->p1->x, ob2->p1->y,
																										ob2->p2->x, ob2->p2->y,
																										val);
				
				_storage_of_constraints.add(ob1, rule);
				_storage_of_constraints.add(ob2, rule);
				return true;
			}
		}
	}
	return false;
}
bool CORE::addc_spratio(double value)
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Point* obj1 = dynamic_cast<Point*>(k.getValue().value);
		if (obj1)
		{
			k.moveNext();
			Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
			if (obj2)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				AspectRatio* rule = new AspectRatio(obj2->p1->x, obj2->p1->y,
																obj1->x, obj1->y,
																obj2->p2->x, obj2->p2->y,
																val);
				
				_storage_of_constraints.add(obj2->p1, rule);
				_storage_of_constraints.add(obj1, rule);
				_storage_of_constraints.add(obj2->p2, rule);
				return true;
			}
		}
		Segment* ob2 = dynamic_cast<Segment*>(k.getValue().value);
		if (ob2)
		{
			k.moveNext();
			Point* ob1 = dynamic_cast<Point*>(k.getValue().value);
			if (ob1)
			{
				double* val = new double;
				*val = value;
				_parameters.add(val, true);
				AspectRatio* rule = new AspectRatio(ob2->p1->x, ob2->p1->y,
																ob1->x, ob1->y,
																ob2->p2->x, ob2->p2->y,
																val);
				
				_storage_of_constraints.add(ob1, rule);
				_storage_of_constraints.add(ob2, rule);
				return true;
			}
		}	
	}
    return false;
}
bool CORE::addc_parallelism()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Segment* obj1 = dynamic_cast<Segment*>(k.getValue().value);
		k.moveNext();
		Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
		if (obj1 && obj2)
		{
			ParallelLines* rule = new ParallelLines(obj1->p1->x, obj1->p1->y,
				obj1->p2->x, obj1->p2->y,
				obj2->p1->x, obj2->p1->y,
				obj2->p2->x, obj2->p2->y);
			
			_storage_of_constraints.add(obj1, rule);
			_storage_of_constraints.add(obj2, rule);
			return true;
		}
	}
	return false;
}
bool CORE::addc_orthogonality()
{
	if (_selected_objects.size() == 2)
	{
		AVLVeiwer<unsigned, ObjectBase*> k(_selected_objects);
		Segment* obj1 = dynamic_cast<Segment*>(k.getValue().value);
		k.moveNext();
		Segment* obj2 = dynamic_cast<Segment*>(k.getValue().value);
		if (obj1 && obj2)
		{
			OrthogonalLines* rule = new OrthogonalLines(obj1->p1->x, obj1->p1->y,
				obj1->p2->x, obj1->p2->y,
				obj2->p1->x, obj2->p1->y,
				obj2->p2->x, obj2->p2->y);
			
			_storage_of_constraints.add(obj1, rule);
			_storage_of_constraints.add(obj2, rule);
			return true;
		}
	}
	return false;
}
