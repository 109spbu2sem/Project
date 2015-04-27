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
	
	enum StreamState
	{
		STREAMISCLOSE,
		POINTCASE,
		SEGMENTCASE,
		CIRCLECASE,
		CONSTRAINT_TYPE,
		ENDOFSTREAM
	};

	ListViewer<Point> _pointstream;
	ListViewer<Segment> _segmentstream;
	ListViewer<Circle> _circlestream;
	ListViewer<IConstraint*> _constrstream;
	StreamState _streamstate;

	bool isInArea(double x, double y, double x1, double y1, double x2, double y2);
	void BuildFigure(IConstraint*, Storage_Array<double*>*);
	void BuildFigureNewton(IConstraint*, Storage_Array<double*>*);
	void BuildFigureGoldMethod(IConstraint*, Storage_Array < double* >*);

public:
	CORE();
	CORE(GUI* gui)
	{
		mygui = gui;
		_streamstate = STREAMISCLOSE;
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

	void IWantSave(std::string fileway);
	void IWantLoad(std::string fileway);

	struct Primitive
	{
		unsigned id;
		PRIMITIVE_TYPE type;
		double p1_x;
		double p1_y;
		double p2_x;
		double p2_y;
		double r;
		Color color;
		bool select;
	};

	bool OpenStream();
	bool StreamIsOpened();
	Primitive GetFromStream(); // if stream is closed return std::logic_error
	void CloseStream();
};

#endif // CORE_H
