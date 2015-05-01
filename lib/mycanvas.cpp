#include "mycanvas.h"
#include "gui.h"
#include "objectpropertieswindow.h"
#include <QPointF>

MyCanvas::MyCanvas(QWidget *parent) : QGraphicsView(parent)
{
	mainscene = new QGraphicsScene();
	this->setScene(mainscene);
	_tool = TOOL_Select;
}

MyCanvas::~MyCanvas()
{
	delete mainscene;
}

void MyCanvas::mousePressEvent(QMouseEvent *event)
{
	QPointF pt = mapToScene(event->pos());
	switch (_tool)
	{
	case TOOL_Select:
	{
		mycore->Select(pt.x(), -pt.y());
		break;
	}
	case TOOL_Point:
	{
		mycore->AddObject(pt.x(), -pt.y());
		break;
	}
	}
}

void MyCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{	
	switch (_tool)
	{
	case TOOL_Select:
	{
		QPointF pt = mapToScene(event->pos());
		objectPropertiesWindow ob(this);
		ob.exec();
		return;
	}
	default:
		return;
	}
}

void MyCanvas::setTool(GTool t)
{
	_tool = t;
}
