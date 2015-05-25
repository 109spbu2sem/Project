#include "core.h"
#include <string>


void CORE::Select(double x, double y)
{
	
	//Try to search points in small radius
	writeToLog("< clicking >", 3);
	writeToLog(x, "x= ", 3);
	writeToLog(y, "y= ", 3);
	writeToLog("< /clicking >", 3);
	double min = 4;
	unsigned min_id = 0;
	for (StorageOfObjects::viewer i(_storage_of_objects); i.valid(); i++)
	{
		if (i.key().getID())
		{
			switch (i.value()->objectType())
			{
			case PRIMITIVE_POINT:
			{
				Point* p = dynamic_cast<Point*>(i.value());
				if (length(*p->x, *p->y, x, y) < min)
				{
					min = length(*p->x, *p->y, x, y);
					min_id = p->id.getID();
				}
				break;
			}
			case PRIMITIVE_SEGMENT:
			{
				Segment* s = dynamic_cast<Segment*>(i.value());
				double A = *s->p2->y - *s->p1->y;
				double B = *s->p1->x - *s->p2->x;
				double C = *s->p1->y * *s->p2->x - *s->p1->x * *s->p2->y;
				if ((abs(A*x + B*y + C) / sqrt(A*A + B*B) < min) &&
					(pow(length(*s->p1->x, *s->p1->y, x, y),2) <=
					((A*x + B*y + C)*(A*x + B*y + C) / (A*A + B*B) +
					pow(length(*s->p1->x, *s->p1->y, *s->p2->x, *s->p2->y),2)))
					&& (pow(length(*s->p2->x, *s->p2->y, x, y),2) <=
					((A*x + B*y + C)*(A*x + B*y + C) / (A*A + B*B) +
					pow(length(*s->p1->x, *s->p1->y, *s->p2->x, *s->p2->y),2))) 
					&& length(*s->p1->x, *s->p1->y, x, y)>1.67 && 
					length(*s->p2->x, *s->p2->y, x, y)>1.67)
				{
					min = abs(A*x + B*y + C) / sqrt(A*A + B*B);
					min_id = s->id.getID();
				}
				break;
			}
			case PRIMITIVE_CIRCLE:
			{
				Circle* c = dynamic_cast<Circle*>(i.value());
				if ((length(*c->p->x, *c->p->y, x, y) < (*c->r + min)) &&
					 (length(*c->p->x, *c->p->y, x, y) > (*c->r - min)))
				{
					min = abs(length(*c->p->x, *c->p->y, x, y) - *c->r);
					min_id = c->id.getID();
				}
				break;
			}
			}
		}
	}
	Select(min_id);
	return;
}

bool CORE::Select(unsigned id)
{
	if (id)
	{
		ObjectBase* object = _storage_of_objects.get(id);
		if (object)
		{
			object->changeSelect();
			if (object->isSelected())
			{
				_selected_objects.insert(object->id.getID(), object);
				switch (object->objectType())
				{
					case PRIMITIVE_POINT:
					{
						Point* p = dynamic_cast<Point*>(object);
						mygui->Set_properties_of_point(p->id.getID(), *p->x, *p->y, p->color.getColor());
						break;
					}
					case PRIMITIVE_SEGMENT:
					{
						Segment* s = dynamic_cast<Segment*>(object);
						mygui->Set_properties_of_segment(s->id.getID(), *s->p1->x, *s->p1->y, *s->p2->x, *s->p2->y, s->color.getColor());
						break;
					}
					case PRIMITIVE_CIRCLE:
					{
						Circle* c = dynamic_cast<Circle*>(object);
						mygui->Set_properties_of_circle(c->id.getID(), *c->p->x, *c->p->y, *c->r, c->color.getColor());
						break;
					}
				}
			}
			else
			{
				_selected_objects.erase(object->id.getID());
			}
			writeToLog(id, "selection was changed for (ID) ", 2);
			Redraw(mygui);
			return object->isSelected();
		}
	}
	else
		ClearSelection();
	return false;
}

/*void CORE::Select(double x1, double y1, double x2, double y2)
{
	// select points
	unsigned size = _storage_of_points.size();
	for (ListViewer<Point> i(_storage_of_points); i.valid(); i++)
	{
		if (isInArea(*i.x, *i.y, x1, y1, x2, y2))
		{
			i.changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (ListViewer<Segment> i(_storage_of_segments); i.valid(); i++)
	{
		if (isInArea(*i.p1->x, *i.p1->y, x1, y1, x2, y2) &&
			isInArea(*i.p2->x, *i.p2->y, x1, y1, x2, y2))
		{
			i.changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}
	// select circles
	size = _storage_of_circles.size();
	for (ListViewer<Circle> i(_storage_of_circles); i.valid(); i++)
	{
		if ((isInArea(*i.p->x, *i.p->y, x1, y1, x2, y2)) &&
			(*i.p->x + *i.r) >= x1 && (*i.p->x + *i.r) <= x2 &&
			(*i.p->y + *i.r) >= y1 && (*i.p->y + *i.r) <= y2)
		{
			i.changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}
	Redraw();
	return;
}*/

void CORE::ClearSelection()
{
	for (myavltree<unsigned, ObjectBase*>::myiterator i(_selected_objects); i.valid(); i++)
	{
		i.value()->changeSelect(false);
	}
	_selected_objects.clear();
	writeToLog("Select was cleared", 2);
	Redraw(mygui);
	mygui->Clear_properties();
	mygui->WriteText(DONESTRING, EMPTYSTRING);
}

void CORE::DeleteAll()
{
	mygui->WriteText("Cleaning...", EMPTYSTRING);
	_selected_objects.clear();
	_storage_of_constraints.clear();
	mygui->WriteText("Cleaning...", "All rules were deleted");
	writeToLog("All rules were deleted");
	_storage_of_objects.clear();
	mygui->WriteText("Cleaning...", "All objects were deleted");
	writeToLog("All objects were deleted");
	_parameters.clear();
	mygui->WriteText("Cleaning...", "All parameters were deleted");
	writeToLog("All parameters were deleted");
	writeToLog("All clear");
	mygui->Clear();
	mygui->ClearRules();
	mygui->WriteText(DONESTRING, "All clear");
}

void CORE::DeleteSelectedObjects()
{
	unsigned cantdelete = 0;
	for (myavltree<unsigned, ObjectBase*>::myiterator i(_selected_objects); i.valid(); i++)
	{
		if (_storage_of_constraints.has(i.value()))
			cantdelete++;
		else 
		{
			switch (i.value()->objectType())
			{
				case PRIMITIVE_POINT:
				{
					Point* p = dynamic_cast<Point*>(i.value());
					if (_storage_of_objects.has_SorC_with_P(p))
						cantdelete++;
					else
					{
						_parameters.erase(p->x);
						_parameters.erase(p->y);
						delete p->x;
						delete p->y;
						_storage_of_objects.remove(i.value()->id);
						delete i.value();
					}
					break;
				}
				case PRIMITIVE_SEGMENT:
				{
					//Segment* s = dynamic_cast<Segment*>(i.getValue());
					_storage_of_objects.remove(i.value()->id);
					delete i.value();
					break;
				}
				case PRIMITIVE_CIRCLE:
				{
					Circle* c = dynamic_cast<Circle*>(i.value());
					_parameters.erase(c->r);
					delete c->r;
					_storage_of_objects.remove(i.value()->id);
					delete i.value();
					break;
				}	
			}
		}
	}
	_selected_objects.clear();
	Redraw(mygui);
	mygui->Clear_properties();
	mygui->WriteText(DONESTRING, EMPTYSTRING);
	if (cantdelete)
		mygui->WriteError("First, delete all constraints and objects wich associates with these objects.");
}

void CORE::IWantSave()
{
	Save mysave(_fileWay);
	StorageOfObjects::viewer i(_storage_of_objects);
	StorageOfConstraints::viewer j(_storage_of_constraints);
	while (i.valid())
	{
		mygui->UpdateWorkStatus(1); // draw :: on status
		if (i.key().getID() == 0)
		{
			i++;
			continue;
		}
		if (i.value()->objectType() == PRIMITIVE_POINT)
		{
			Point* v = dynamic_cast<Point*>(i.value());
			mysave.DrawPoint(v->id.getID(), *v->x, _parameters.get(v->x), *v->y,
				_parameters.get(v->y), v->color.getColor(), 0);
			i++;
			continue;
		}
		if (i.value()->objectType() == PRIMITIVE_SEGMENT)
		{
			Segment* v = dynamic_cast<Segment*>(i.value());
			mysave.DrawSegment(v->id.getID(), v->p1->id.getID(), v->p2->id.getID(), v->color.getColor(), 0);
			i++;
			continue;

		}
		if (i.value()->objectType() == PRIMITIVE_CIRCLE)
		{
			Circle* v = dynamic_cast<Circle*>(i.value());
			mysave.DrawCircle(v->id.getID(), v->p->id.getID(), *v->r, _parameters.get(v->r), v->color.getColor(), 0);
			i++;
			continue;
		}
	}
	while (j.valid()) {
		mygui->UpdateWorkStatus(1); // draw :: on status
		if (j.constraint()->type() == CONSTR_COLLECTOR) {
			j++;
			continue;
		}
		if (j.constraint()->type() == CONSTR_EXCONTACT || j.constraint()->type() == CONSTR_INCONTACT ||
			j.constraint()->type() == CONSTR_ORTHOGONALITY || j.constraint()->type() == CONSTR_PARALLELISM) {
			mysave.DrawRule(j.constraint()->type(), j.objects().front()->id.getID(), j.objects().back()->id.getID());
			j++;
			continue;
		}
		if (j.constraint()->type() == CONSTR_P2PDIST ||
			j.constraint()->type() == CONSTR_P2LINEDIST || j.constraint()->type() == CONSTR_L2LANGLE) {
			mysave.DrawRule(j.constraint()->type(), j.objects().front()->id.getID(), j.objects().back()->id.getID(),
				j.constraint()->value());
			j++;
			continue;
		}
		if (j.constraint()->type() == CONSTR_3PONLINE) {
			mylist<ObjectBase*>::myiterator i = j.objects().begin();
			unsigned id1 = (*i)->id.getID(); ++i;
			unsigned id2 = (*i)->id.getID(); ++i;
			unsigned id3 = (*i)->id.getID();
			mysave.DrawRule(j.constraint()->type(), id1, id2, id3);
			j++;
			continue;
		}
	}
	mygui->WorkStatusDone();
}

void CORE::IWantSaveAs(QString way) {
	_fileWay = way;
	IWantSave();
}

void CORE::IWantLoad(QString way)
{
	_fileWay = way;
	Load myload(this, _fileWay);
	myload.testPoints();
	myload.testBegin();
	if (myload.isCorrect())
		myload.begin();
	else
		mygui->WriteError("Incorrect file.");
}

bool CORE::DeleteRule(unsigned id)
{
	if (_storage_of_constraints.has(id))
	{
		IConstraint* constraint = _storage_of_constraints.get(id);
		mylist<ObjectBase*> objlist = _storage_of_constraints.get(constraint);
		for (mylist<ObjectBase*>::myiterator iter = objlist.begin(); iter.valid(); iter++)
		{
			try
			{
				_storage_of_constraints.remove(*iter, constraint);
			}
			catch (...) { }
		}
		_storage_of_constraints.remove(id);
		Redraw(mygui);
		TransmitRules(mygui);
		mygui->WriteText(DONESTRING,"Rule deleted");
		return true;
	}
	mygui->WriteError("FATAL ERROR\nPlease, restart program or click on button \"Clear all\".");
	return false;
}
