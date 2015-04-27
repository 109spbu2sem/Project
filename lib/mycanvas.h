#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWidget>
#include "core.h"
#include "gui.h"

class CORE;
class MainWindow;

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

public slots:
	void mousePressEvent(QMouseEvent *event);
private:
	QGraphicsScene* mainscene;
	CORE* mycore;
};

#endif // MYCANVAS_H
