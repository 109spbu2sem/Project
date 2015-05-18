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
	for (StorageOfObjects::viewer i(_storage_of_objects); i.canMoveNext(); i.moveNext())
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
	if (min_id)
	{
		try
		{
			ObjectBase* object = _storage_of_objects.get(min_id);
			object->changeSelect();
			if (object->isSelected())
			{
				_selected_objects.add(object);
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
				for (ListViewer<ObjectBase*> j(_selected_objects); j.canMoveNext(); j.moveNext())
				{
					if (object == j.getValue())
					{
						_selected_objects.remove(&j);
						break;
					}
				}
			}
			writeToLog(min_id, "selection was changed for (ID) ", 2);
			Redraw(mygui);
		}
		catch (...)
		{
		}
	}
	else
		ClearSelection();
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
				_selected_objects.add(object);
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
				for (ListViewer<ObjectBase*> j(_selected_objects); j.canMoveNext(); j.moveNext())
				{
					if (object == j.getValue())
					{
						_selected_objects.remove(&j);
						break;
					}
				}
			}
			writeToLog(id, "selection was changed for (ID) ", 2);
			Redraw(mygui);
			return object->isSelected();
		}
	}
	return false;
}

/*void CORE::Select(double x1, double y1, double x2, double y2)
{
	// select points
	unsigned size = _storage_of_points.size();
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
	{
		if (isInArea(*i.getValue().x, *i.getValue().y, x1, y1, x2, y2))
		{
			i.getValue().changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}

	// select segments
	size = _storage_of_segments.size();
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext())
	{
		if (isInArea(*i.getValue().p1->x, *i.getValue().p1->y, x1, y1, x2, y2) &&
			isInArea(*i.getValue().p2->x, *i.getValue().p2->y, x1, y1, x2, y2))
		{
			i.getValue().changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}
	// select circles
	size = _storage_of_circles.size();
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext())
	{
		if ((isInArea(*i.getValue().p->x, *i.getValue().p->y, x1, y1, x2, y2)) &&
			(*i.getValue().p->x + *i.getValue().r) >= x1 && (*i.getValue().p->x + *i.getValue().r) <= x2 &&
			(*i.getValue().p->y + *i.getValue().r) >= y1 && (*i.getValue().p->y + *i.getValue().r) <= y2)
		{
			i.getValue().changeSelect(true);
			_selected_objects.add(&i.getValue());
		}
	}
	Redraw();
	return;
}*/

void CORE::ClearSelection()
{
	for (ListViewer< ObjectBase* > i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		i.getValue()->changeSelect(false);
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
	for (ListViewer< ObjectBase* > i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		if (_storage_of_constraints.has(i.getValue()))
			cantdelete++;
		else 
		{
			switch (i.getValue()->objectType())
			{
				case PRIMITIVE_POINT:
				{
					Point* p = dynamic_cast<Point*>(i.getValue());
					if (_storage_of_objects.has_SorC_with_P(p))
						cantdelete++;
					else
					{
						_parameters.remove(p->x);
						_parameters.remove(p->y);
						delete p->x;
						delete p->y;
						_storage_of_objects.remove(i.getValue()->id);
						delete i.getValue();
					}
					break;
				}
				case PRIMITIVE_SEGMENT:
				{
					//Segment* s = dynamic_cast<Segment*>(i.getValue());
					_storage_of_objects.remove(i.getValue()->id);
					delete i.getValue();
					break;
				}
				case PRIMITIVE_CIRCLE:
				{
					Circle* c = dynamic_cast<Circle*>(i.getValue());
					_parameters.remove(c->r);
					delete c->r;
					_storage_of_objects.remove(i.getValue()->id);
					delete i.getValue();
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
	while (i.canMoveNext())
	{
		if (i.key().getID() == 0)
		{
			i.moveNext();
			continue;
		}
		if (i.value()->objectType() == PRIMITIVE_POINT)
		{
			Point* v = dynamic_cast<Point*>(i.value());
			mysave.DrawPoint(v->id.getID(), *v->x, _parameters.getValuebyKey(v->x), *v->y,
				_parameters.getValuebyKey(v->y), v->color.getColor(), 0);
			i.moveNext();
			continue;
		}
		if (i.value()->objectType() == PRIMITIVE_SEGMENT)
		{
			Segment* v = dynamic_cast<Segment*>(i.value());
			mysave.DrawSegment(v->id.getID(), v->p1->id.getID(), v->p2->id.getID(), v->color.getColor(), 0);
			i.moveNext();
			continue;

		}
		if (i.value()->objectType() == PRIMITIVE_CIRCLE)
		{
			Circle* v = dynamic_cast<Circle*>(i.value());
			mysave.DrawCircle(v->id.getID(), v->p->id.getID(), *v->r, _parameters.getValuebyKey(v->r), v->color.getColor(), 0);
			i.moveNext();
			continue;
		}
	}
	while (j.canMoveNext()) {
		if (j.constraint()->type() == CONSTR_COLLECTOR) {
			j.moveNext();
			continue;
		}
		if (j.constraint()->type() == CONSTR_EXCONTACT || j.constraint()->type() == CONSTR_INCONTACT ||
			j.constraint()->type() == CONSTR_ORTHOGONALITY || j.constraint()->type() == CONSTR_PARALLELISM) {
			mysave.DrawRule(j.constraint()->type(), j.objects().front()->id.getID(), j.objects().back()->id.getID());
			j.moveNext();
			continue;
		}
		if (j.constraint()->type() == CONSTR_P2PDIST || j.constraint()->type() == CONSTR_P2SECTDIST ||
			j.constraint()->type() == CONSTR_P2LINEDIST || j.constraint()->type() == CONSTR_L2LANGLE ||
			j.constraint()->type() == CONSTR_SPRATIO) {
			mysave.DrawRule(j.constraint()->type(), j.objects().front()->id.getID(), j.objects().back()->id.getID(),
				j.constraint()->value());
			j.moveNext();
			continue;
		}
		if (j.constraint()->type() == CONSTR_3PRATIO) {
			std::list<ObjectBase*>::iterator i = j.objects().begin();
			unsigned id1 = (*i)->id.getID(); ++i;
			unsigned id2 = (*i)->id.getID(); ++i;
			unsigned id3 = (*i)->id.getID();
			mysave.DrawRule(j.constraint()->type(), id1, id2, id3, j.constraint()->value());
			j.moveNext();
			continue;
		}
		if (j.constraint()->type() == CONSTR_3PONLINE) {
			std::list<ObjectBase*>::iterator i = j.objects().begin();
			unsigned id1 = (*i)->id.getID(); ++i;
			unsigned id2 = (*i)->id.getID(); ++i;
			unsigned id3 = (*i)->id.getID();
			mysave.DrawRule(j.constraint()->type(), id1, id2, id3);
			j.moveNext();
			continue;
		}
	}
}

void CORE::IWantSaveAs(QString way) {
	_fileWay = way;
	IWantSave();
}

void CORE::IWantLoad(QString way)
{
	_fileWay = way;
	Load myload(this, _fileWay);
	myload.begin();
}

bool CORE::DeleteRule(unsigned id)
{
	if (_storage_of_constraints.has(id))
	{
		IConstraint* constraint = _storage_of_constraints.get(id);
		std::list<ObjectBase*> objlist = _storage_of_constraints.get(constraint);
		for (std::list<ObjectBase*>::iterator iter = objlist.begin(); iter != objlist.end(); iter++)
		{
			_storage_of_constraints.remove(*iter, constraint);
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
