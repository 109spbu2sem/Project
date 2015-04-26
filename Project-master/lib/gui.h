#ifndef GUI_H
#define GUI_H

#include "core.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include "mycanvas.h"

class CORE;

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	void ConnectCORE(CORE* core);
	
	bool Redraw();
	void WriteError(unsigned ErrorKey);
	void WriteStatus(const char* ErrorKey);
	
private slots:	
	void on_openAddingBTN_clicked();
	
	void on_addBTN_clicked();
	
	void on_typesOfObjects_currentIndexChanged(int index);
	
	void on_calculateBTN_clicked();
	
	void on_ruleBox_currentIndexChanged(int index);
	
	void on_pushButton_clicked();
	
	void on_pushButton_2_clicked();

	void on_saveButton_clicked();
	
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
