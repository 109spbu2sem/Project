#include "core.h"


void CORE::ChangeStatus(double x, double y, unsigned char status_key)
{
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
		mygui->Redraw();
		return;
	}
	size = _storage_of_segments.size();
	int min_j = -1;
	j = 0;
	double A = 0, B = 0, C = 0;
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext(), j++)
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
		mygui->Redraw();
		return;
	}
	size = _storage_of_circles.size();
	int min_k = -1;
	j = 0;
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext(), j++)
	{
		if ((length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) < (*i.getValue()._r + min)) &&
			(length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) > (*i.getValue()._r - min)))
		{
			min = abs(length(*i.getValue()._o->_x, *i.getValue()._o->_y, x, y) - *i.getValue()._r);
			min_k = j;
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
		mygui->Redraw();
		return;
	}
	return;
}
//{
/*Try to search points in small radius*/
/*unsigned size = _storage_of_points.size();
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
Redraw();
return;
}*/


void CORE::ChangeStatus(double x1, double y1, double x2, double y2, unsigned char status_key)
{
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
	mygui->Redraw();
	return;
}

void CORE::ClearSelection()
{
	for (ListViewer< ObjectSkin* > i(_selected_objects); i.canMoveNext(); i.moveNext())
	{
		i.getValue()->changeSelect(false);
		i.getValue()->color.setColor(COLORDEF);
	}
	mygui->Redraw();
}
