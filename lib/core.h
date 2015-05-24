#ifndef CORE_H
#define CORE_H
#include "structures.h"
#include "storages/mylist.h"
#include "storages/myvector.h"
#include "global.h"
#include "gui.h"
#include "Save.h"
#include "Load.h"
#include <string>
#include <QString>
#include <fstream>
#include "settings.h"
#include <ctime>
#include "storages/mytree.h"
#include "storageofobjects.h"
#include "enums.h"
#include "storageofconstraints.h"


class Save;
class Load;

class CORE
{
private:
	GraphicsInterface* mygui;
	QString _fileWay;

	myavltree<double*, bool> _parameters;
	StorageOfConstraints _storage_of_constraints;
	myavltree<unsigned, ObjectBase*> _selected_objects;
	StorageOfObjects _storage_of_objects;

	bool isInArea(double x, double y, double x1, double y1, double x2, double y2);
	void BuildFigure(IConstraint*, myvector<double*>*);
	void BuildFigureGoldMethod(IConstraint*, myvector < double* >*);
	void Redraw(Interface*);
	void TransmitRules(Interface*);
	
	Settings mysettings;
	std::fstream _logfile;

	std::string GenerateTimeString(const char*, const char*);

	bool addc_p2pdist(double);
	bool addc_p2sdist(double);
	bool addc_p2ldist(double);
	bool addc_l2langle(double);
	bool addc_3pratio(double);
	bool addc_3ponline();
	bool addc_excontact();
	bool addc_incontact();
	bool addc_spratio(double);
	bool addc_parallelism();
	bool addc_orthogonality();
	bool addc_ponc();
	
	const char* DONESTRING;
	const char* WORKSTRING;
	const char* EMPTYSTRING;

public:
	CORE();
	CORE(GraphicsInterface* gui);
	~CORE();
	void Connect(GraphicsInterface* gui)
	{
		mygui = gui;
		writeToLog("GUI connected to CORE", 2);
	}

	void writeToLog(std::string, unsigned = 1);
	void writeToLog(int, unsigned = 1);
	void writeToLog(double, unsigned = 1);
	void writeToLog(unsigned, unsigned = 1);
	void writeToLog(long long, unsigned = 1);
	void writeToLog(int, std::string, unsigned = 1);
	void writeToLog(unsigned, std::string, unsigned = 1);
	void writeToLog(double, std::string, unsigned = 1);

	void Calculate();

	unsigned AddObject(double point_x, bool isconstx,
							 double point_y, bool isconsty,
							 Color color = COLORDEF,
							 unsigned id = 0, bool wait = false); // add point
	unsigned AddObject(unsigned point1_id, unsigned point2_id,
							 Color color = COLORDEF,
							 unsigned id = 0, bool wait = false); // add segment for 2 points
	unsigned AddObject(unsigned point_id,
							 double radius, bool isconst,
							 Color color = COLORDEF,
							 unsigned id = 0, bool wait = false);
	void CreateSegment();
	void CreateCircle(double, bool);

	void AddRule(unsigned type, double value = 0);
	bool AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2);
	bool AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, double value);
	bool AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3);
	bool AddRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3, double value);

	bool ChangePoint(unsigned id,
						  double point_x, bool isconstx,
						  double point_y, bool isconsty,
						  Color color);
	bool ChangeSegment(unsigned id,
							 double point_x1, bool isconstx1,
							 double point_y1, bool isconsty1,
							 double point_x2, bool isconstx2,
							 double point_y2, bool isconsty2,
							 Color color);
	bool ChangeCircle(unsigned id,
							double point_x, bool isconstx,
							double point_y, bool isconsty,
							double radius, bool isconst,
							Color color);

	void Select(double x, double y);
	void Select(double x1, double y1, double x2, double y2);
	bool Select(unsigned id);
	void ClearSelection();

	void DeleteSelectedObjects();
	void DeleteAll();
	bool DeleteRule(unsigned);

	void IWantSave();
	void IWantSaveAs(QString fileway);
	void IWantLoad(QString fileway);
};

#endif // CORE_H
