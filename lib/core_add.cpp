#include "constraints\DistancePoint-Point.h"
#include "constraints\DistancePoint-Section.h"
#include "constraints\DistanceToTheLine.h"
#include "constraints\AngleSegment-Segment.h"
#include "constraints\ThreePointsOnTheLine.h"
#include "constraints\AspectRatio.h"
#include "constraints\Collector.h"
#include "constraints\CircleContact.h"

#include "core.h"

void CORE::AddObject(double point_x, double point_y, Color color, unsigned id)
{
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	p.color.setColor(color);
	_storage_of_points.add(p);
	mygui->WriteStatus("Point added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x, 2);
	writeToLog(point_y, 2);
	writeToLog(color.getColor(), 2);
	writeToLog(id, 2);
	writeToLog("< /add >", 2);
	Redraw();
}

void CORE::AddObject(double point_x1, double point_y1, double point_x2, double point_y2, Color color, unsigned id)
{
	Point p1(_storage_of_parameters.add(point_x1), _storage_of_parameters.add(point_y1));
	Point p2(_storage_of_parameters.add(point_x2), _storage_of_parameters.add(point_y2));
	Segment s(_storage_of_points.add(p1), _storage_of_points.add(p2));
	s.color.setColor(color);
	_storage_of_segments.add(s);
	mygui->WriteStatus("Segment added");
	writeToLog("< add > Point", 2);
	writeToLog(point_x1, 2);
	writeToLog(point_y1, 2);
	writeToLog(point_x2, 2);
	writeToLog(point_y2, 2);
	writeToLog(color.getColor(), 2);
	writeToLog(id, 2);
	writeToLog("< /add >", 2);
	Redraw();
}

void CORE::AddObject(double point_x, double point_y, double radius, Color color, unsigned id)
{
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	Circle c(_storage_of_points.add(p), _storage_of_constants.add(radius));
	c.color.setColor(color);
	_storage_of_circles.add(c);
	mygui->WriteStatus("Circle added");
	writeToLog("< add > Circle", 2);
	writeToLog(point_x, 2);
	writeToLog(point_y, 2);
	writeToLog(radius, 2);
	writeToLog(color.getColor(), 2);
	writeToLog(id, 2);
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
			Segment s(obj, obj1);
			s.color.setColor(COLORDEF);
			_storage_of_segments.add(s);
			writeToLog("Concatenate points", 2);
			Redraw();
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
				Point2Point* rule = new Point2Point(obj1->_x, obj1->_y, obj2->_x, obj2->_y, val );
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
			Circle* o1 = dynamic_cast<Circle*>(k.getValue());
			if (o1)
			{
				k.moveNext();
				Circle* o2 = dynamic_cast<Circle*>(k.getValue());
				if (o2)
				{

					ExternalContactCircle* rule = new ExternalContactCircle(o1->_o->_x, o1->_o->_y, o2->_o->_x,
						o2->_o->_y, o1->_r, o2->_r);
					_storage_of_constraints.add(rule);
					double* param[6] = { o1->_o->_x, o1->_o->_y, o2->_o->_x,
						o2->_o->_y, o1->_r, o2->_r };
					_storage_of_constraint.add(rule, *param);
					mygui->WriteStatus("Rule added");
					Calculate();
					return;

				}
			}
		}
		return;
	}
	case CONSTR_INCONTACT:
	{
							 if (_selected_objects.size() == 2)
							 {
								 ListViewer<ObjectSkin*> k(_selected_objects);
								 Circle* o1 = dynamic_cast<Circle*>(k.getValue());
								 if (o1)
								 {
									 k.moveNext();
									 Circle* o2 = dynamic_cast<Circle*>(k.getValue());
									 if (o2)
									 {
										 InternalContactCircle* rule = new InternalContactCircle(o1->_o->_x, o1->_o->_y, o2->_o->_x,
											 o2->_o->_y, o1->_r, o2->_r);
										 _storage_of_constraints.add(rule);
										 double* param[6] = { o1->_o->_x, o1->_o->_y, o2->_o->_x,
											 o2->_o->_y, o1->_r, o2->_r };
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
		mygui->WriteStatus("Wrong type of rule.");
		return;
	}

	}
}
