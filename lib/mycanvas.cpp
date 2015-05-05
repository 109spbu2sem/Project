#include "mycanvas.h"
#include "gui.h"
#include "objectpropertieswindow.h"
#include "ui_gui.h"
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
	case TOOL_ZoomPlus:
	{
		scale(2, 2);
		break;
	}
	case TOOL_ZoomMinus:
	{
		scale(0.5, 0.5);
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
		setTool(TOOL_ZoomPlus);
		break;
	}
	case Qt::Key_6:
	{
		setTool(TOOL_ZoomMinus);
		break;
	}
	default:
		break;
	}
}

void MyCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{	
	/*switch (_tool)
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
	}*/
}

void MyCanvas::wheelEvent(QWheelEvent *event)
{
	if (event->delta() > 0)
	{
		scale(1.2, 1.2);
	}
	else
		scale(1/1.2, 1/1.2);
}

void MyCanvas::setTool(GTool t)
{
	_tool = t;
}
