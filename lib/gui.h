#ifndef GUI_H
#define GUI_H

#include "core.h"
#include "QtWidgets/qmainwindow.h"
#include "QtWidgets/qgraphicsscene.h"
#include "mycanvas.h"
#include "QtWidgets/qbuttongroup.h"
#include "QtWidgets/qaction.h"
#include "enums.h"
#include "qregexp.h"
#include "qvalidator.h"
#include "qresource.h"

class CORE;

namespace Ui
{
	class GUI;
}

class GUI : public QMainWindow, public GraphicsInterface
{
	Q_OBJECT
	
public:
	explicit GUI(QWidget *parent = 0);
	~GUI();
	
	void ConnectCORE(CORE* core);
	
	virtual bool SetNameOfWindow(std::string);

	virtual bool DrawPoint(unsigned, double, double, Color, bool); // point (id, x, y, color)
	virtual bool DrawSegment(unsigned, double, double, double, double, Color, bool); // segment (id, x1, y1, x2, y2, color)
	virtual bool DrawCircle(unsigned, double, double, double, Color, bool); // circle (id, x, y, r, color)
	virtual bool Clear();

	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE);
	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE, double);
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE);
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE, double);
	virtual bool ClearRules();

	virtual bool Set_properties_of_point(unsigned, double, double, Color);
	virtual bool Set_properties_of_segment(unsigned, double, double, double, double, Color);
	virtual bool Set_properties_of_circle(unsigned, double, double, double, Color);
	virtual void Clear_properties();

	virtual void WriteError(const char* Text);
	virtual void WriteText(const char* Short, const char* Long);

	virtual void UpdateWorkStatus(unsigned);
	virtual void WorkStatusDone();

private slots:
	void on_openAddingBTN_clicked();
	
	void on_ruleBox_currentIndexChanged(int index);
	
	void on_pushButton_clicked();
	
	void on_createSegmentBTN_clicked();
	
	void on_selectBTNTool_clicked();
	
	void on_pointBTNTool_clicked();
	
	void on_ZoomBTNTool_clicked();

	void on_actionRedraw_all_triggered();

	void on_actionClose_triggered();

	void on_actionSave_triggered();

	void on_actionSave_As_triggered();

	void on_actionClear_all_triggered();

	void on_actionLoad_triggered();
	
	void on_objectsList_clicked(const QModelIndex &index);

	void on_rulesList_clicked(const QModelIndex &index);
	
	void on_openChangingDialog_clicked();
	
	void on_deleteObjBTN_clicked();

	void on_deleteRuleBTN_clicked();

	void on_createCircleBTN_clicked();

	void on_redrawBTN_clicked();

	void on_clearallBTN_clicked();

	void on_gridBTN_clicked();

	void on_saveBTN_clicked();
	void on_saveasBTN_clicked();
	void on_openBTN_clicked();
	void on_closeBTN_clicked();
	
private:
    bool flag;
	Ui::GUI *ui;
	CORE* mycore;
	QGraphicsScene* mainscene;
	QButtonGroup* toolsbuttons;
	QRegExpValidator *doubvalid;
	QResource resourse;
	
	const char* ConstrTypeToString(CONSTR_TYPE);
	void setupIconsForVS();
	unsigned selectedRuleId;

	int workstatus;
};

#endif // GUI_H
