#include "core.h"
#include "gui.h"
#include "constraints\Collector.h"
#include <fstream>
#include <string>
#include <ctime>
#include <string>
#include <direct.h>

CORE::CORE()
{
	mygui = 0;
	Settings::SettingsLoader::setupSettings(&mysettings);
	if (mysettings.WritelogMode() >= 1)
	{
		_mkdir("logfiles");
		_logfile.open(GenerateTimeString("logfiles/logfile", ".log").c_str(), std::ios_base::out | std::ios_base::trunc);
		if (!_logfile.is_open()) mysettings.setWritelogMode(0);
	}
	writeToLog("--------------------------------------\nOPEN at ");
	writeToLog(GenerateTimeString("", "").c_str());
	writeToLog("--------------------------------------");
	writeToLog("Settings = ok", 2);
	writeToLog("GUI was not connected to CORE", 2);
}

CORE::CORE(GraphicsInterface* gui)
{
	mygui = gui;
	Settings::SettingsLoader::setupSettings(&mysettings);
	if (mysettings.WritelogMode() >= 1)
	{
		_logfile.open("logfile.txt", std::ios_base::out | std::ios_base::app);
		if (!_logfile.is_open())
			_logfile.open("logfile.txt", std::ios_base::out | std::ios_base::trunc);
	}
	writeToLog("--------------------------------------\nOPEN at ");
	writeToLog(static_cast<int>(time(0)));
	writeToLog("--------------------------------------");
	writeToLog("Settings = ok", 2);
	writeToLog("GUI connected to CORE", 2);
}

CORE::~CORE()
{
	writeToLog("--------------------------------------\n CLOSE at ");
	writeToLog(GenerateTimeString("", "").c_str());
	writeToLog("--------------------------------------");
	if (mysettings.WritelogMode() >= 1)
		_logfile.close();
}

void CORE::Redraw(Interface* infa)
{
	if (infa)
	{
		writeToLog("*******Redrawing*******");
		infa->Clear();
		// new method for tree
		for (StorageOfObjects::viewer i(_storage_of_objects); i.canMoveNext(); i.moveNext())
		{
			if (i.key().getID() == 0) continue;
			switch (i.value()->objectType())
			{
			case PRIMITIVE_POINT:
			{
				Point* p = dynamic_cast<Point*>(i.value());
				writeToLog("<point>", 3);
				writeToLog(*p->x, "x= ", 3);
				writeToLog(*p->y, "y= ", 3);
				writeToLog(p->color.getColor(), "color= ", 3);
				writeToLog(p->id.getID(), "id= ", 3);
				writeToLog("</point>", 3);
				infa->DrawPoint(p->id.getID(), *p->x, *p->y, p->color, p->isSelected());
				break;
			}
			case PRIMITIVE_SEGMENT:
			{
				Segment* s = dynamic_cast<Segment*>(i.value());
				writeToLog("<segment>", 3);
				writeToLog(*s->p1->x, "x1= ", 3);
				writeToLog(*s->p1->y, "y1= ", 3);
				writeToLog(*s->p2->x, "x2= ", 3);
				writeToLog(*s->p2->y, "y2= ", 3);
				writeToLog(s->color.getColor(), "color= ", 3);
				writeToLog(s->id.getID(), "id= ", 3);
				writeToLog("</segment>", 3);
				infa->DrawSegment(s->id.getID(), *s->p1->x, *s->p1->y,
										*s->p2->x, *s->p2->y, s->color, s->isSelected());
				break;
			}
			case PRIMITIVE_CIRCLE:
			{
				Circle* c = dynamic_cast<Circle*>(i.value());
				writeToLog("<circle>", 3);
				writeToLog(*c->p->x, "x= ", 3);
				writeToLog(*c->p->y, "y= ", 3);
				writeToLog(*c->r, "r= ", 3);
				writeToLog(c->color.getColor(), "color= ", 3);
				writeToLog(c->id.getID(), "id= ", 3);
				writeToLog("</circle>", 3);
				infa->DrawCircle(c->id.getID(), *c->p->x, *c->p->y,
									  *c->r, c->color, c->isSelected());
				break;
			}
			}
		}
		writeToLog("*******Redrawed*******", 3);
	}
	else
	{
		writeToLog("Interface is invalid.");
	}
	return;
}

void CORE::Calculate()
{
	writeToLog("**********************Start calculating******************");
	mygui->WriteText("Work", "Start redrawing");
	ConstraintCollector collector;
	Storage_Array< double* > parameters;
	writeToLog("Generating graphs");

	/*Here for Anton's graphs*/

	for (ListViewer<IConstraint*> i(_storage_of_constraints); i.canMoveNext(); i.moveNext())
	{
		try
		{
			collector.addConstraint(i.getValue());
		}
		catch (...) {}
	}
	for (AVLVeiwer< double*, bool > i(_parameters); i.canMoveNext(); i.moveNext())
	{
		if (!i.getValue().value)
		{
			parameters.add(i.getValue().key);
		}
	}
	//BuildFigure(&collector, &parameters);
	writeToLog("---------------------Building new figure-----------------");
	mygui->WriteText("Work", "Redrawing...");
	BuildFigureGoldMethod(&collector, &parameters);
	writeToLog("---------------------Success build-----------------------");
	Redraw(mygui);
	mygui->WriteText("Done", "");
	writeToLog("**********************Success calculate******************");
	return;
}

void CORE::BuildFigureGoldMethod(IConstraint *constr, Storage_Array<double*>* parameters)
{
	// small value
	const double f_epsi = 1e-6;
	if (constr->error() < f_epsi) return;
	// great value
	const double f_Epsi = 1e+6;
	// amount of iterations
	unsigned f_count = 0;
	// current value of function
	double f_current = constr->error();
	// value of function on previous iteration
	double f_prev = 0;
	// gradient of function
	double *grad = new double[parameters->size()];
	// value of parameters on previous iteration
	double *old_para = new double[parameters->size()];
	unsigned nf_eval = 0;
	do
	{
		f_count++;
		f_prev = f_current;
		for (unsigned k = 0; k < parameters->size(); k++)
			grad[k] = constr->diff((*parameters)[k]);

		double a1 = 1;
		for (unsigned k = 0; k < parameters->size(); k++)
			old_para[k] = *(*parameters)[k];
		for (unsigned k = 0; k < parameters->size(); k++)
			*(*parameters)[k] -= a1*grad[k];
		double f_a1 = constr->error();
		nf_eval++;

		while (f_a1 <= f_prev)
		{
			a1 *= 2; // 1.5
			for (unsigned k = 0; k < parameters->size(); k++)
				*(*parameters)[k] = old_para[k] - a1*grad[k];
			f_a1 = constr->error();
			nf_eval++;
		}
		// ratio of the golden section
		const double gold = 0.5 + sqrt(5.0 / 4);
		double a0 = 0;
		double f_a0 = f_prev;
		double aleft = a1 - (a1 - a0) / gold;
		double aright = a0 + (a1 - a0) / gold;
		for (unsigned k = 0; k < parameters->size(); k++)
			*(*parameters)[k] = old_para[k] - aleft*grad[k];
		double f_al = constr->error();
		nf_eval++;
		for (unsigned k = 0; k < parameters->size(); k++)
			*(*parameters)[k] = old_para[k] - aright*grad[k];
		double f_ar = constr->error();
		nf_eval++;
		// amount of interations of the golden section
		unsigned gold_count = 0;
		while (abs(f_al - f_ar) > f_epsi && gold_count < f_Epsi)
		{
			gold_count++;
			if (f_al < f_ar)
			{
				a1 = aright; f_a1 = f_ar;
				aright = aleft; f_ar = f_al;
				aleft = a1 - (a1 - a0) / gold;
				for (unsigned k = 0; k < parameters->size(); k++)
					*(*parameters)[k] = old_para[k] - aleft*grad[k];
				f_al = constr->error();
				nf_eval++;
			}
			else
			{
				a0 = aleft; f_a0 = f_al;
				aleft = aright; f_al = f_ar;
				aright = a0 + (a1 - a0) / gold;
				for (unsigned k = 0; k < parameters->size(); k++)
					*(*parameters)[k] = old_para[k] - aright*grad[k];
				f_ar = constr->error();
				nf_eval++;
			}
		}
		writeToLog(gold_count, "golden iterations= ", 2);
		for (unsigned k = 0; k < parameters->size(); k++)
			*(*parameters)[k] = old_para[k] - (aright + aleft) / 2 * grad[k];
		f_current = constr->error();
		nf_eval++;
		writeToLog(f_current, "f = ", 2);
		writeToLog(abs(f_prev - f_current) /*/ abs(f_prev)*/, "delta f= ", 2);
	//} while (abs(f_prev - f_current) > f_epsi);
	} while (abs(f_prev - f_current) /*/ abs(f_prev)*/ > f_epsi && f_count < f_Epsi);
	writeToLog(f_count, "iterations= ", 2);
	writeToLog(nf_eval, "Steps= ", 2);
	if (constr->error() >= f_epsi)
		mygui->WriteError("Can't build true figure.");
	delete[] grad;
	delete[] old_para;
}

void CORE::BuildFigure(IConstraint* constraint, Storage_Array<double*>* parameters)
{
	if (!constraint || !parameters) return; // check for true work

	const double f_epsi = 1e-6;
	double current = constraint->error();
	double previous = 0;
	double *dx = new double[parameters->size()];
	writeToLog(current, "f = ", 2);
	writeToLog(abs(previous - current) /*/ abs(f_prev)*/, "delta f= ", 2);
	do
	{
		previous = current;

		double step_min = 0.0001;
		//double step_max = 1000;

		for (unsigned i = 0; i < parameters->size(); i++)
			dx[i] = -step_min * constraint->diff((*parameters)[i]); // calculate gradient
		for (unsigned i = 0; i < parameters->size(); i++)
			*(*parameters)[i] += dx[i];										 // change parameters

		current = constraint->error();
		writeToLog(current, "f = ", 2);
		writeToLog(abs(previous - current) /*/ abs(f_prev)*/, "delta f= ", 2);
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
// Description:
// write to log file std::string if current 'logmode' >= mode
void CORE::writeToLog(std::string s, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{ 
		_logfile << s << std::endl;
	}
}
// Description:
// write to log file int value if current 'logmode' >= mode
void CORE::writeToLog(int value, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file double value if current 'logmode' >= mode
void CORE::writeToLog(double value, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file uint if current 'logmode' >= mode
void CORE::writeToLog(unsigned value, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file long long int if current 'logmode' >= mode
void CORE::writeToLog(long long value, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file int after string if current 'logmode' >= mode
void CORE::writeToLog(int value, std::string s, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << s << value << std::endl;
	}
}
// Description:
// write to log file uint after string if current 'logmode' >= mode
void CORE::writeToLog(unsigned value, std::string s, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << s << value << std::endl;
	}
}
// Description:
// write to log file double after string if current 'logmode' >= mode
void CORE::writeToLog(double value, std::string s, char mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << s << value << std::endl;
	}
}
// Description:
// add current time in format (1996-03-15)[23_59_59] between 2 strings
std::string CORE::GenerateTimeString(char* first_str, char* last_str)
{
	std::string output_str(first_str);
	time_t current_time = time(0);
	struct tm * timeinfo = localtime(&current_time);
	char timetext[80];
	// (1996-03-15)[23_59_59]
	strftime(timetext, 80, "(%Y-%m-%d)[%H_%M_%S]", timeinfo);
	output_str.append(timetext);
	output_str.append(last_str);
	return output_str;
}
