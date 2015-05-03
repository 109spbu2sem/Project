#ifndef CORE_H
#define CORE_H
#include "structures.h"
#include "storages\storage_list.h"
#include "storages\storage_array.h"
#include "global.h"
#include "gui.h"
#include "Save.h"
#include "Load.h"
#include <string>
#include <QString>
#include <fstream>
#include "settings.h"
#include <ctime>
#include "storages\heshtable.h"

class GUI;
class Save;
class Load;

class CORE
{
private:
	//friend class Save;
	GUI* mygui;
	Save* mysave;
	Load* myload;

	Storage_List<double> _storage_of_parameters;
	Storage_List<double> _storage_of_constants;
	Storage_List<Point> _storage_of_points;
	Storage_List<Segment> _storage_of_segments;
	Storage_List<Circle> _storage_of_circles;
	Storage_List<IConstraint*> _storage_of_constraints;
	HashTable<IConstraint*, double*> _storage_of_constraint;
	Storage_List<ObjectSkin*> _selected_objects;

	bool isInArea(double x, double y, double x1, double y1, double x2, double y2);
	void BuildFigure(IConstraint*, Storage_Array<double*>*);
	void BuildFigureNewton(IConstraint*, Storage_Array<double*>*);
	void BuildFigureGoldMethod(IConstraint*, Storage_Array < double* >*);
	void Redraw();
	
	Settings mysettings;
	std::fstream _logfile;

	void writeToLog(std::string, char = 1);
	void writeToLog(int, char = 1);
	void writeToLog(double, char = 1);
	void writeToLog(unsigned, char = 1);
	void writeToLog(long long, char = 1);

public:
	CORE();
	CORE(GUI* gui);
	~CORE();
	void Connect(GUI* gui, Save* save, Load* load)
	{
		mygui = gui;
		mysave = save;
		myload = load;
		writeToLog("GUI connected to CORE", 2);
		writeToLog("SAVE connected to CORE", 2);
	}

	void Calculate();

	void AddObject(double point_x, double point_y, Color color = COLORDEF, unsigned id = 0); // add point
	void AddObject(double point_x1, double point_y1, double point_x2, double point_y2, Color color = COLORDEF, unsigned id = 0); // add segment, automatical adds 2 points
	void AddObject(double point_x, double point_y, double radius, Color color = COLORDEF, unsigned id = 0); // add circle, automatical add center of circle
	void ConcatenatePoints();

	void AddRule(unsigned type, double value);
	void AddRule(unsigned type);

	void ChangeStatus(unsigned char status_key); // need refine

	void Select(double x, double y);
	void Select(double x1, double y1, double x2, double y2);
	void ClearSelection();

	void DeleteSelected();

	void IWantSave();
	void IWantSaveAs(QString fileway);
	void IWantLoad(QString fileway);
};

#endif // CORE_H
