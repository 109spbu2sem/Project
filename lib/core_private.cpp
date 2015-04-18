#include "core.h"
#include "gui.h"
#include "constraints\Collector.h"

CORE::CORE()
{
	_streamstate = 0;
}

CORE::~CORE()
{
	
}

void Redraw()
{
	/*for (ListViewer<Point> i(_storage_of_points); i.canMoveNext(); i.moveNext())
	{
		if (i.getValue().isVisible())
			mygui->Draw(*i.getValue()._x, *i.getValue()._y, i.getValue().isSelected() ? SELECTEDCOLOR : i.getValue().color.getColor());
	}
	for (ListViewer<Segment> i(_storage_of_segments); i.canMoveNext(); i.moveNext())
	{
      if (i.getValue().isVisible())
			mygui->Draw(*i.getValue()._p1->_x, *i.getValue()._p1->_y, *i.getValue()._p2->_x, *i.getValue()._p2->_y, i.getValue().isSelected() ? SELECTEDCOLOR : i.getValue().color.getColor());
	}
	for (ListViewer<Circle> i(_storage_of_circles); i.canMoveNext(); i.moveNext())
	{
		if (i.getValue().isVisible())
			mygui->Draw(*i.getValue()._o->_x, *i.getValue()._o->_y, *i.getValue()._r, i.getValue().isSelected() ? SELECTEDCOLOR : i.getValue().color.getColor());
	}*/
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
	mygui->Redraw();
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
			*(*parameters)[i] += dx[i];										 // change parameters

		current = constraint->error();
	} while (abs(previous - current) > f_epsi);
	delete[] dx;
	return;
}

bool CORE::isInArea(double x, double y, double x1, double y1, double x2, double y2)
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

void CORE::IWantSave(std::string fileway)
{

}