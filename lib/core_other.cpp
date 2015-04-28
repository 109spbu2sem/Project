#include "core.h"


void CORE::ChangeStatus(unsigned char status_key)
{
}

void CORE::Select(double x, double y)
{
	/*Try to search points in small radius*/
	unsigned size = _storage_of_points.size();
	double min = 4;
	int min_i = -1;
	unsigned j = 0;
	for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext(), j++)
	{
		if (!i.getValue().isSelected())
		{
			if (length(*i.getValue()._x, *i.getValue()._y, x, y) < min)
			{
				min = length(*i.getValue()._x, *i.getValue()._y, x, y);
				min_i = j;
			}
		}
	}
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
		Redraw();
		return;
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	j = 0;
	double A = 0, B = 0, C = 0;
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext(), j++)
	{
		if (!i.getValue().isSelected())
		{
			A = *i.getValue()._p2->_y - *i.getValue()._p1->_y;
			B = *i.getValue()._p1->_x - *i.getValue()._p2->_x;
			C = *i.getValue()._p1->_y * *i.getValue()._p2->_x - *i.getValue()._p1->_x * *i.getValue()._p2->_y;
			if ((abs(A*x + B*y + C) / sqrt(A*A + B*B) < min) &&
				(length(*i.getValue()._p1->_x, *i.getValue()._p1->_y, x, y) <
				((A*x + B*y + C)*(A*x + B*y + C) / (A*A + B*B) +
				length(*i.getValue()._p1->_x, *i.getValue()._p1->_y, *i.getValue()._p2->_x, *i.getValue()._p2->_y)))
				&& (length(*i.getValue()._p2->_x, *i.getValue()._p2->_y, x, y) <
				((A*x + B*y + C)*(A*x + B*y + C) / (A*A + B*B) +
				length(*i.getValue()._p1->_x, *i.getValue()._p1->_y, *i.getValue()._p2->_x, *i.getValue()._p2->_y))))
			{
				min = abs(A*x + B*y + C) / sqrt(A*A + B*B);
				min_j = j;
			}
		}
	}
	if (min_j >= 0)
	{
		unsigned j = 0;
		ListViewer<Segment> i(_storage_of_segments);
		for (; j < min_j; i.moveNext())
		{
			j++;
		}
		i.getValue().changeSelect();
		_selected_objects.add(&i.getValue());
		Redraw();
		return;
	}
	size = _storage_of_circles.size();
	int min_k = -1;
	j = 0;
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext(), j++)
	{
		if (!i.getValue().isSelected())
		{
			if ((length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) < (*i.getValue()._r + min)) &&
				(length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) > (*i.getValue()._r - min)))
			{
				min = abs(length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) - *i.getValue()._r);
				min_k = j;
			}
		}
	}
	if (min_k >= 0)
	{
		unsigned j = 0;
		ListViewer<Circle> i(_storage_of_circles);
		for (; j < min_k; i.moveNext())
		{
			j++;
		}
		i.getValue().changeSelect();
		_selected_objects.add(&i.getValue());
		Redraw();
		return;
	}
	return;
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
		if ((isInArea(*i.getValue()._o->_x, *i.getValue()._o->_y, x1, y1, x2, y2)) &&
			(*i.getValue()._o->_x + *i.getValue()._r) >= x1 && (*i.getValue()._o->_x + *i.getValue()._r) <= x2 &&
			(*i.getValue()._o->_y + *i.getValue()._r) >= y1 && (*i.getValue()._o->_y + *i.getValue()._r) <= y2)
		{
			i.getValue().changeSelect();
			_selected_objects.add(&i.getValue());
		}
	}
	Redraw();
	return;
}

void CORE::ClearSelection()
{
	for (ListViewer< ObjectSkin* > i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		i.getValue()->changeSelect(false);
	}
	_selected_objects.clear();
	Redraw();
	mygui->WriteStatus("Done");
}

void CORE::DeleteSelected()
{
	Redraw();
}

void CORE::IWantSave()
{
	mysave->begin();
	if (_storage_of_points.size() != 0) {
		ListViewer<Point> v(_storage_of_points);
		while (v.canMoveNext()) {
			Color c;
			mysave->DrawPoint(v.getValue().id.getID(), *v.getValue()._x, *v.getValue()._y, v.getValue().color.getColor());
			v.moveNext();
		}
	}
	if (_storage_of_segments.size() != 0) {
		ListViewer<Segment> v(_storage_of_segments);
		while (v.canMoveNext()) {
			Color c;
			mysave->DrawSegment(v.getValue().id.getID(), *v.getValue()._p1->_x, *v.getValue()._p1->_y,
				*v.getValue()._p2->_x, *v.getValue()._p2->_y, v.getValue().color.getColor());
			v.moveNext();
		}
	}
	if (_storage_of_circles.size() != 0) {
		ListViewer<Circle> v(_storage_of_circles);
		while (v.canMoveNext()) {
			Color c;
			mysave->DrawCircle(v.getValue().id.getID(), *v.getValue()._o->_x, *v.getValue()._o->_y,
				*v.getValue()._r, v.getValue().color.getColor());
			v.moveNext();
		}
	}
	mysave->end();
}

void CORE::IWantSaveAs(QString way) {
	mysave->fileWay(way);
	IWantSave();
}

void CORE::IWantLoad(std::string fileway)
{

}
