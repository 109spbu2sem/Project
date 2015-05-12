#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWidget>
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

public slots:
	void mousePressEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	void keyPressEvent(QKeyEvent *event);
private:
	QGraphicsScene* mainscene;
	CORE* mycore;
	GTool _tool;
};

#endif // MYCANVAS_H
