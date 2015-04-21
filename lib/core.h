#ifndef CORE_H
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
	
	ListViewer<Point> _pointstream;
	ListViewer<Segment> _segmentstream;
	ListViewer<Circle> _circlestream;
	ListViewer<IConstraint*> _constrstream;
	unsigned _streamstate;

	void Redraw();
	void BuildFigure(IConstraint*, Storage_Array<double*>*);
	void BuildFigureNewton(IConstraint*, Storage_Array<double*>*);

public:
	CORE();
	CORE(GUI* gui)
	{
		mygui = gui;
		_streamstate = 0;
	}
	~CORE();
	void Connect(GUI* gui, Save* save)
	{
		mygui = gui;
		mysave = save;
	}

	void Calculate();

	void AddObject(double point_x, double point_y); // add point
	void AddObject(double point_x1, double point_y1, double point_x2, double point_y2); // add segment, automatical adds 2 points
	void AddObject(double point_x, double point_y, double radius); // add circle, automatical add center of circle
	void AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle);

	void AddRule(unsigned type, double value);
	void AddRule(unsigned type);

	void ChangeStatus(double x, double y, unsigned char status_key); // need refine
	void ChangeStatus(double x1, double y1, double x2, double y2, unsigned char status_key); // need refine

	void Select(double x, double y);
	void Select(double x1, double y1, double x2, double y2);
	void ClearSelection();

	void ChangeProperty(unsigned property_key, ...);

	void IWantSave(std::string fileway);

	bool OpenStream();
	bool StreamIsOpened();
	double GetFromStream(); // if stream is closed return std::logic_error
	void CloseStream();
};

#endif // CORE_H
