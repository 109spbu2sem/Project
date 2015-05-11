#ifndef GUI_H
#define GUI_H

#include "core.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include "mycanvas.h"
#include <QButtonGroup>
#include <QAction>

class CORE;

enum GTool
{
	TOOL_Select,
	TOOL_Point,
	TOOL_Zoom
};

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow, public Interface
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	void ConnectCORE(CORE* core);
	
	bool DrawPoint(unsigned, double, double, Color = 0); // point (id, x, y, color)
	bool DrawSegment(unsigned, double, double, double, double, Color = 0); // segment (id, x1, y1, x2, y2, color)
	bool DrawCircle(unsigned, double, double, double, Color = 0); // circle (id, x, y, r, color)
	bool Clear();

	bool Set_properties_of_point(unsigned, double, double, Color = 0);
	bool Set_properties_of_segment(unsigned, double, double, double, double, Color = 0);
	bool Set_properties_of_circle(unsigned, double, double, double, Color = 0);

	void WriteError(const char* Text);
	void WriteStatus(const char* Text);
	void WriteMessage(const char* Text);
	void WriteText(const char* Short, const char* Long);

	//void setupObjectParameters(PRIMITIVE_TYPE, unsigned, double, double, double, double, Color);

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
	
private:
	Ui::MainWindow *ui;
	CORE* mycore;
	QGraphicsScene* mainscene;
	QButtonGroup* toolsbuttons;
	

};

class GUI : public MainWindow
{
	Q_OBJECT
public:
	/*GUI(CORE* core)
	{
		mycore = core;
		mainwindow = getUI();
	}
	void ConnectCORE(CORE* core)
	{
		mycore = core;
	}
	bool Redraw();
	void WriteError(unsigned ErrorKey);*/
	
private:
	/*CORE* mycore;
	QGraphicsScene* mainscene;
	Ui::MainWindow* mainwindow;*/
};

#endif // GUI_H
