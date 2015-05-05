#ifndef GUI_H
#define GUI_H

#include "core.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include "mycanvas.h"

class CORE;

enum GTool
{
	TOOL_Select,
	TOOL_Point,
	TOOL_ZoomPlus,
	TOOL_ZoomMinus
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
	
	bool DrawPoint(unsigned, double, double, Color = 0, unsigned = 0); // point (id, x, y, color)
	bool DrawSegment(unsigned, double, double, double, double, Color = 0, unsigned = 0); // segment (id, x1, y1, x2, y2, color)
	bool DrawCircle(unsigned, double, double, double, Color = 0, unsigned = 0); // circle (id, x, y, r, color)
	bool Clear();

	void WriteError(const char* ErrorText);
	void WriteStatus(const char* ErrorKey);

	//void setupObjectParameters(PRIMITIVE_TYPE, unsigned, double, double, double, double, Color);
	
private slots:	
	void on_openAddingBTN_clicked();
	
	void on_addBTN_clicked();
	
	void on_typesOfObjects_currentIndexChanged(int index);
	
	void on_calculateBTN_clicked();
	
	void on_ruleBox_currentIndexChanged(int index);
	
	void on_pushButton_clicked();
	
	void on_pushButton_2_clicked();
	
	void on_concatinateBTN_clicked();
	
	void on_selectTool_clicked();
	
	void on_pointTool_clicked();

	void on_zoomPlusTool_clicked();

	void on_zoomMinusTool_clicked();

	void on_saveButton_clicked();

	void on_saveAsButton_clicked();

	void on_deleteAllBTN_clicked();
	
private:
	Ui::MainWindow *ui;
	CORE* mycore;
	QGraphicsScene* mainscene;
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
