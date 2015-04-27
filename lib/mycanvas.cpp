#include "mycanvas.h"
#include "ui_gui.h"
#include <QPointF>

MyCanvas::MyCanvas(QWidget *parent) : QGraphicsView(parent)
{
	mainscene = new QGraphicsScene();
	this->setScene(mainscene);
}

MyCanvas::~MyCanvas()
{
	delete mainscene;
}

void MyCanvas::mousePressEvent(QMouseEvent *event)
{
	QPointF pt = mapToScene(event->pos());
	mycore->Select(pt.x(), pt.y());
}
