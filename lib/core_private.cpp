#include "core.h"
#include "gui.h"
#include "constraints\Collector.h"

CORE::CORE()
{
	_streamstate = STREAMISCLOSE;
	mygui = 0;
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
	//BuildFigure(&collector, &parameters);
	BuildFigureGoldMethod(&collector, &parameters);
	mygui->Redraw();
	mygui->WriteStatus("Done");
	return;
}

void CORE::BuildFigureGoldMethod(IConstraint *constr, Storage_Array<double*>* parameters)
{
	const double f_epsi = 1e-12;
	if (constr->error() < f_epsi) return;
	double f_cur = constr->error();
	double f_prev = 0;
	double *grad = new double[parameters->size()];
	double *old_para = new double[parameters->size()];
	unsigned nf_eval = 0;
	do
	{
		f_prev = f_cur;
		for (unsigned k = 0; k < parameters->size(); ++k)
			grad[k] = constr->diff((*parameters)[k]);

		double alpha1 = 1;
		for (unsigned k = 0; k < parameters->size(); ++k)
			old_para[k] = *(*parameters)[k];
		for (unsigned k = 0; k < parameters->size(); ++k)
			*(*parameters)[k] -= alpha1*grad[k];
		double f_alpha1 = constr->error();
		nf_eval++;

		while (f_alpha1 <= f_prev)
		{
			alpha1 *= 2;
			for (unsigned k = 0; k < parameters->size(); ++k)
				*(*parameters)[k] = old_para[k] - alpha1*grad[k];
			f_alpha1 = constr->error();
			nf_eval++;
		}
		const double gold = 0.5 + sqrt(5.0 / 4);
		double alpha0 = 0;
		double f_alpha0 = f_prev;
		double alphal = alpha1 - (alpha1 - alpha0) / gold;
		double alphar = alpha0 + (alpha1 - alpha0) / gold;
		for (unsigned k = 0; k < parameters->size(); ++k)
			*(*parameters)[k] = old_para[k] - alphal*grad[k];
		double f_alphal = constr->error();
		nf_eval++;
		for (unsigned k = 0; k < parameters->size(); ++k)
			*(*parameters)[k] = old_para[k] - alphar*grad[k];
		double f_alphar = constr->error();
		nf_eval++;
		unsigned gold_count = 0;
		while (abs(f_alphal - f_alphar) > f_epsi)
		{
			gold_count++;
			if (f_alphal < f_alphar)
			{
				alpha1 = alphar; f_alpha1 = f_alphar;
				alphar = alphal; f_alphar = f_alphal;
				alphal = alpha1 - (alpha1 - alpha0) / gold;
				for (unsigned k = 0; k < parameters->size(); ++k)
					*(*parameters)[k] = old_para[k] - alphal*grad[k];
				f_alphal = constr->error();
				nf_eval++;
			}
			else
			{
				alpha0 = alphal; f_alpha0 = f_alphal;
				alphal = alphar; f_alphal = f_alphar;
				alphar = alpha0 + (alpha1 - alpha0) / gold;
				for (unsigned k = 0; k < parameters->size(); ++k)
					*(*parameters)[k] = old_para[k] - alphar*grad[k];
				f_alphar = constr->error();
				nf_eval++;
			}
		}
		for (unsigned k = 0; k < parameters->size(); ++k)
			*(*parameters)[k] = old_para[k] - (alphar + alphal) / 2 * grad[k];
		f_cur = constr->error();
		nf_eval++;
	} while (abs(f_prev - f_cur) > f_epsi);
	delete[] grad;
	delete[] old_para;
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
		//double step_max = 1000;

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
