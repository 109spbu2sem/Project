#include "core.h"
#include "gui.h"
#include "constraints/Collector.h"
#include <fstream>
#include <string>
#include <ctime>
#include <string>
#include <direct.h>

CORE::CORE()
{
	mygui = 0;
	WORKSTRING = "Working";
	DONESTRING = "Done";
	EMPTYSTRING = "";
	Settings::SettingsLoader::setupSettings(&mysettings);
	if (mysettings.WritelogMode() >= 1)
	{
		_mkdir("logfiles");
		_logfile.open(GenerateTimeString("logfiles/logfile", ".log").c_str(), std::ios_base::out | std::ios_base::trunc);
		if (!_logfile.is_open()) mysettings.setWritelogMode(0);
	}
	writeToLog("--------------------------------------\nOPEN at ");
	writeToLog(GenerateTimeString(const_cast<char*>(EMPTYSTRING), const_cast<char*>(EMPTYSTRING)).c_str());
	writeToLog("--------------------------------------");
	writeToLog("Settings = ok", 2);
	writeToLog(mysettings.WritelogMode(), "Logfile level");
	writeToLog("GUI was not connected to CORE", 2);
}

CORE::CORE(GraphicsInterface* gui)
{
	mygui = gui;
	WORKSTRING = "Working";
	DONESTRING = "Done";
	EMPTYSTRING = "";
	Settings::SettingsLoader::setupSettings(&mysettings);
	if (mysettings.WritelogMode() >= 1)
	{
		_mkdir("logfiles");
		_logfile.open(GenerateTimeString("logfiles/logfile", ".log").c_str(), std::ios_base::out | std::ios_base::trunc);
		if (!_logfile.is_open()) mysettings.setWritelogMode(0);
	}
	writeToLog("--------------------------------------\nOPEN at ");
	writeToLog(GenerateTimeString(const_cast<char*>(EMPTYSTRING), const_cast<char*>(EMPTYSTRING)).c_str());
	writeToLog("--------------------------------------");
	writeToLog("Settings = ok", 2);
	writeToLog(mysettings.WritelogMode(), "Logfile level");
	writeToLog("GUI connected to CORE", 2);
}

CORE::~CORE()
{
	writeToLog("--------------------------------------\n CLOSE at ");
	writeToLog(GenerateTimeString(const_cast<char*>(EMPTYSTRING), const_cast<char*>(EMPTYSTRING)).c_str());
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

void CORE::TransmitRules(Interface* infa)
{
	if (infa)
	{
		infa->ClearRules();
		for (StorageOfConstraints::viewer iter(_storage_of_constraints); iter.canMoveNext(); iter.moveNext())
		{
			switch (iter.constraint()->type())
			{
				case CONSTR_COLLECTOR:
				{
					continue;
				}
				case CONSTR_P2PDIST:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_P2SECTDIST:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_P2LINEDIST:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_3PONLINE:
				{
					std::list<ObjectBase*>::iterator i = iter.objects().begin();
					unsigned id1 = (*i)->id.getID(); i++;
					unsigned id2 = (*i)->id.getID(); i++;
					unsigned id3 = (*i)->id.getID();
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  id1, id2, id3,
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_L2LANGLE:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_3PRATIO:
				{
					std::list<ObjectBase*>::iterator i = iter.objects().begin();
					unsigned id1 = (*i)->id.getID(); i++;
					unsigned id2 = (*i)->id.getID(); i++;
					unsigned id3 = (*i)->id.getID();
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  id1, id2, id3,
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_EXCONTACT:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_INCONTACT:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_ORTHOGONALITY:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
				case CONSTR_PARALLELISM:
				{
					mygui->WriteRule(_storage_of_constraints.getid(iter.constraint()).getID(),
										  iter.objects().front()->id.getID(), iter.objects().back()->id.getID(),
										  iter.constraint()->type(), iter.constraint()->value());
					break;
				}
			}
		}
	}
	else
	{
		writeToLog("Interface is invalid.");
	}
}

void CORE::Calculate()
{
	writeToLog("**********************Start calculating******************");
	mygui->WriteText(EMPTYSTRING, "Start redrawing");
	ConstraintCollector collector;
	Storage_Array< double* > parameters;
	writeToLog("Generating graphs");

	/*Here place graph partition*/

	for (StorageOfConstraints::viewer i(_storage_of_constraints); i.canMoveNext(); i.moveNext())
	{
		try
		{
			collector.addConstraint(i.constraint());
		}
		catch (std::logic_error err)
		{
			writeToLog("End of constraints or viewer damaged", 1);
			break;
		}
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
	mygui->WriteText(EMPTYSTRING, "Redrawing...");
	BuildFigureGoldMethod(&collector, &parameters);
	writeToLog("---------------------Success build-----------------------");
	Redraw(mygui);
	TransmitRules(mygui);
	mygui->WriteText(DONESTRING, EMPTYSTRING);
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
		writeToLog((aright + aleft) / 2, "step= ", 2);
		for (unsigned k = 0; k < parameters->size(); k++)
			*(*parameters)[k] = old_para[k] - (aright + aleft) / 2 * grad[k];
		f_current = constr->error();
		nf_eval++;
		writeToLog(f_current, "f = ", 2);
		writeToLog(abs(f_prev - f_current) /*/ abs(f_prev)*/, "delta f= ", 2);
	//} while (abs(f_prev - f_current) > f_epsi);
	} while (abs(f_prev - f_current) /*/ abs(f_prev)*/ > f_epsi && f_count < f_Epsi && f_current > f_epsi);
	writeToLog(f_count, "iterations= ", 2);
	writeToLog(nf_eval, "updates= ", 2);
	/*if (constr->error() >= f_epsi)
		mygui->WriteError("Can't build true figure.");*/
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
void CORE::writeToLog(std::string s, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{ 
		_logfile << s << std::endl;
	}
}
// Description:
// write to log file int value if current 'logmode' >= mode
void CORE::writeToLog(int value, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file double value if current 'logmode' >= mode
void CORE::writeToLog(double value, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file uint if current 'logmode' >= mode
void CORE::writeToLog(unsigned value, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file long long int if current 'logmode' >= mode
void CORE::writeToLog(long long value, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << value << std::endl;
	}
}
// Description:
// write to log file int after string if current 'logmode' >= mode
void CORE::writeToLog(int value, std::string s, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << s << value << std::endl;
	}
}
// Description:
// write to log file uint after string if current 'logmode' >= mode
void CORE::writeToLog(unsigned value, std::string s, unsigned mode)
{
	if (mysettings.WritelogMode() >= mode && _logfile.is_open())
	{
		_logfile << s << value << std::endl;
	}
}
// Description:
// write to log file double after string if current 'logmode' >= mode
void CORE::writeToLog(double value, std::string s, unsigned mode)
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
