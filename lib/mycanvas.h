#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "QtWidgets\qgraphicsview.h"
#include <QMouseEvent>
#include "core.h"
#include "enums.h"

class CORE;



class MyCanvas : public QGraphicsView
{
	Q_OBJECT
public:
	explicit MyCanvas(QWidget *parent = 0);
	~MyCanvas();

	QGraphicsScene* getScene()
	{
		return mainscene;
	}

	void connectCORECanvas(CORE* core)
	{
		mycore = core;
	}
	
	void setTool(GTool);
	void NewCanvas();
	void setGrid(bool);

public slots:
	void mousePressEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mouseMoveEvent(QMouseEvent* event);
signals:
	void clickedx(double);
	void clickedy(double);
private:
	QGraphicsScene* mainscene;
	CORE* mycore;
	GTool _tool;
	bool _displaygrid;
};

#endif // MYCANVAS_H
