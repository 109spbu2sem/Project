#include "mycanvas.h"
#include "gui.h"
#include "objectpropertieswindow.h"
#include "ui_gui.h"
#include <QPointF>

MyCanvas::MyCanvas(QWidget *parent) : QGraphicsView(parent)
{
	mainscene = new QGraphicsScene();
	setScene(mainscene);
	scale(2, 2);
	_tool = TOOL_Select;
	NewCanvas();
}

MyCanvas::~MyCanvas()
{
	delete mainscene;
}

void MyCanvas::NewCanvas()
{
	QPen pen(Qt::DotLine);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
	const double r = 0.4;
	pen.setWidthF(r - 0.3);
	mainscene->addLine(0, -1000, 0, 1000, pen);
	mainscene->addLine(-1000, 0, 1000, 0, pen);
	QPen pen1;
	pen1.setWidthF(r - 0.2);
	QBrush brush(Qt::SolidPattern);
	for (int x = -200; x <= 200; x += 25)
	{
		mainscene->addEllipse(x - r / 2, -r / 2, r, r, pen1, brush);
	}
	for (int y = -200; y <= 200; y += 25)
	{
		mainscene->addEllipse(-r / 2, y - r / 2, r, r, pen1, brush);
	}
}

void MyCanvas::mouseMoveEvent(QMouseEvent* event)
{
	QPointF pt = mapToScene(event->pos());
	clickedx(pt.x());
	clickedy(-pt.y());
}

void MyCanvas::mousePressEvent(QMouseEvent *event)
{
	QPointF pt = mapToScene(event->pos());
	switch (_tool)
	{
	case TOOL_Select:
	{
		if (event->button() == Qt::RightButton)
			mycore->ClearSelection();
		if (event->button() == Qt::LeftButton)
			mycore->Select(pt.x(), -pt.y());
		clickedx(pt.x());
		clickedy(-pt.y());
		break;
	}
	case TOOL_Point:
	{
		if (event->button() == Qt::LeftButton)
			mycore->AddObject(pt.x(), false, -pt.y(), false);
		if (event->button() == Qt::RightButton)
			mycore->ClearSelection();
		clickedx(pt.x());
		clickedy(-pt.y());
		break;
	}
	case TOOL_Zoom:
	{
		if (event->button() == Qt::RightButton)
			scale(0.5, 0.5);
		if (event->button() == Qt::LeftButton)
			scale(2, 2);
		clickedx(pt.x());
		clickedy(-pt.y());
		break;
	}
	}
}

void MyCanvas::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_1:
	{
		setTool(TOOL_Select);
		break;
	}
	case Qt::Key_2:
	{
		setTool(TOOL_Point);
		break;
	}
	case Qt::Key_5:
	{
		setTool(TOOL_Zoom);
		break;
	}
	case Qt::Key_6:
	{
		setTool(TOOL_Zoom);
		break;
	}
	default:
		break;
	}
}

void MyCanvas::wheelEvent(QWheelEvent *event)
{
	if (event->delta() > 0)
	{
		scale(1.2, 1.2);
	}
	else
		scale(1 / 1.2, 1 / 1.2);
}

void MyCanvas::setTool(GTool t)
{
	_tool = t;
}
