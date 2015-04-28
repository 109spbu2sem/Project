#ifndef CORE_
#define CORE_H
#include "structures.h"
#include "storages\storage_list.h"
#include "storages\storage_array.h"
#include "global.h"
#include "gui.h"
#include <string>

class GUI;
class Save;

class CORE
{
private:
	GUI* mygui;
	Save* mysave;

	Storage_List<double> _storage_of_parameters;
	Storage_List<double> _storage_of_constants;
	Storage_List<Point> _storage_of_points;
	Storage_List<Segment> _storage_of_segments;
	Storage_List<Circle> _storage_of_circles;
	Storage_List<IConstraint*> _storage_of_constraints;
	Storage_List<ObjectSkin*> _selected_objects;

	bool isInArea(double x, double y, double x1, double y1, double x2, double y2);
	void BuildFigure(IConstraint*, Storage_Array<double*>*);
	void BuildFigureNewton(IConstraint*, Storage_Array<double*>*);
	void BuildFigureGoldMethod(IConstraint*, Storage_Array < double* >*);
	void Redraw();

public:
	CORE();
	CORE(GUI* gui)
	{
		mygui = gui;
	}
	~CORE();
	void Connect(GUI* gui, Save* save)
	{
		mygui = gui;
		mysave = save;
	}

	void Calculate();

	void AddObject(double point_x, double point_y, unsigned color = COLORDEF); // add point
	void AddObject(double point_x1, double point_y1, double point_x2, double point_y2, unsigned color = COLORDEF); // add segment, automatical adds 2 points
	void AddObject(double point_x, double point_y, double radius, unsigned color = COLORDEF); // add circle, automatical add center of circle
	void ConcatenatePoints();

	void AddRule(unsigned type, double value);
	void AddRule(unsigned type);

	void ChangeStatus(unsigned char status_key); // need refine

	void Select(double x, double y);
	void Select(double x1, double y1, double x2, double y2);
	void ClearSelection();

	void DeleteSelected();

	void IWantSave();
	void IWantSaveAs(std::string fileway);
	void IWantLoad(std::string fileway);
};

#endif // CORE_H
