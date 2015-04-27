#include "constraints\DistancePoint-Point.h"
#include "constraints\DistancePoint-Section.h"
#include "constraints\DistanceToTheLine.h"
#include "constraints\AngleSegment-Segment.h"
#include "constraints\ThreePointsOnTheLine.h"
#include "constraints\AspectRatio.h"
#include "constraints\Collector.h"
#include "constraints\CircleContact.h"

#include "core.h"

void CORE::AddObject(double point_x, double point_y, unsigned color)
{
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	p.color.setColor(color);
	_storage_of_points.add(p);
	mygui->WriteStatus("Point added");
	mygui->Redraw();
}

void CORE::AddObject(double point_x1, double point_y1, double point_x2, double point_y2, unsigned color)
{
	Point p1(_storage_of_parameters.add(point_x1), _storage_of_parameters.add(point_y1));
	Point p2(_storage_of_parameters.add(point_x2), _storage_of_parameters.add(point_y2));
	Segment s(_storage_of_points.add(p1), _storage_of_points.add(p2));
	s.color.setColor(color);
	_storage_of_segments.add(s);
	mygui->WriteStatus("Segment added");
	mygui->Redraw();
}

void CORE::AddObject(double point_x, double point_y, double radius, unsigned color)
{
	Point p(_storage_of_parameters.add(point_x), _storage_of_parameters.add(point_y));
	Circle c(_storage_of_points.add(p), _storage_of_parameters.add(radius));
	c.color.setColor(color);
	_storage_of_circles.add(c);
	mygui->WriteStatus("Circle added");
	mygui->Redraw();
}

void CORE::AddRule(unsigned type, double value)
{
	switch (type)
	{
	case CONSTR_P2PDIST:
	{ // may add multiselect for points and segments
		switch (_selected_objects.size())
		{
		case 1:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Segment* obj = dynamic_cast<Segment*>(k.getValue());
			if (obj)
			{
				Point2Point* rule = new Point2Point(obj->_p1->_x, obj->_p1->_y, obj->_p2->_x, obj->_p2->_y, _storage_of_constants.add(value));
				_storage_of_constraints.add(rule);
				mygui->WriteStatus("Rule added");
			}
			return;
		}
		case 2:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			k.moveNext();
			Point* obj2 = dynamic_cast<Point*>(k.getValue());
			if (obj1 && obj2)
			{
				Point2Point* rule = new Point2Point(obj1->_x, obj1->_y, obj2->_x, obj2->_y, _storage_of_constants.add(value));
				_storage_of_constraints.add(rule);
				mygui->WriteStatus("Rule added");
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
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, _storage_of_constants.add(value));
					_storage_of_constraints.add(rule);
					mygui->WriteStatus("Rule added");
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
					DistanceFromPointToSection* rule = new DistanceFromPointToSection(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, _storage_of_constants.add(value));
					_storage_of_constraints.add(rule);
					mygui->WriteStatus("Rule added");
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
					DistanceToTheLine* rule = new DistanceToTheLine(obj1->_x, obj1->_y, obj2->_p1->_x,
						obj2->_p1->_y, obj2->_p2->_x, obj2->_p2->_y, _storage_of_constants.add(value));
					_storage_of_constraints.add(rule);
					mygui->WriteStatus("Rule added");
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
					DistanceToTheLine* rule = new DistanceToTheLine(ob1->_x, ob1->_y, ob2->_p1->_x,
						ob2->_p1->_y, ob2->_p2->_x, ob2->_p2->_y, _storage_of_constants.add(value));
					_storage_of_constraints.add(rule);
					mygui->WriteStatus("Rule added");
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
				AngleSegmentSegment* rule = new AngleSegmentSegment(
					obj1->_p1->_x, obj1->_p1->_y,
					obj1->_p2->_x, obj1->_p2->_y,
					obj2->_p1->_x, obj2->_p1->_y,
					obj2->_p2->_x, obj2->_p2->_y,
					_storage_of_constants.add(value));
				_storage_of_constraints.add(rule);
				mygui->WriteStatus("Rule added");
			}
			return;
		}
		case 3:
			return;
		case 4:
		{
			ListViewer<ObjectSkin*> k(_selected_objects);
			Point* obj1 = dynamic_cast<Point*>(k.getValue());
			k.moveNext();
			Point* obj2 = dynamic_cast<Point*>(k.getValue());
			k.moveNext();
			Point* obj3 = dynamic_cast<Point*>(k.getValue());
			k.moveNext();
			Point* obj4 = dynamic_cast<Point*>(k.getValue());
			if (obj1 && obj2 && obj3 && obj4)
			{
				AngleSegmentSegment* rule = new AngleSegmentSegment(
					obj1->_x, obj1->_y,
					obj2->_x, obj2->_y,
					obj3->_x, obj3->_y,
					obj4->_x, obj4->_y,
					_storage_of_parameters.add(value));
				_storage_of_constraints.add(rule);
				mygui->WriteStatus("Rule added");
			} else mygui->WriteStatus("Wrong select.");
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
						AspectRatio* rule = new AspectRatio(o1->_x, o1->_y, o2->_x,
							o2->_y, o3->_x, o3->_y, _storage_of_constants.add(value));
						_storage_of_constraints.add(rule);
						mygui->WriteStatus("Rule added");
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
					mygui->WriteStatus("Rule added");
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
					mygui->WriteStatus("Rule added");
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
						mygui->WriteStatus("Rule added");
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
