#ifndef GUI_H
#define GUI_H

#include "core.h"
#include "QtWidgets\qmainwindow.h"
#include "QtWidgets\qgraphicsscene.h"
#include "mycanvas.h"
#include "QtWidgets\qbuttongroup.h"
#include "QtWidgets\qaction.h"
#include "enums.h"

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

	virtual bool Set_properties_of_point(unsigned, double, double, Color);
	virtual bool Set_properties_of_segment(unsigned, double, double, double, double, Color);
	virtual bool Set_properties_of_circle(unsigned, double, double, double, Color);
	virtual void Clear_properties();

	virtual void WriteError(const char* Text);
	virtual void WriteStatus(const char* Text);
	virtual void WriteMessage(const char* Text);
	virtual void WriteText(const char* Short, const char* Long);

private slots:
	void on_openAddingBTN_clicked();
	
	void on_ruleBox_currentIndexChanged(int index);
	
	void on_pushButton_clicked();
	
	void on_concatinateBTN_clicked();
	
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
	
	void on_openChangingDialog_clicked();
	
	void on_deleteObjBTN_clicked();
	
private:
	bool flag = false;
	Ui::GUI *ui;
	CORE* mycore;
	QGraphicsScene* mainscene;
	QButtonGroup* toolsbuttons;
	

};

#endif // GUI_H
