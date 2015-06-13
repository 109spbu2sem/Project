#include "mycanvas.h"
#include "gui.h"
#include "objectpropertieswindow.h"
#include "ui_gui.h"
#include <QPointF>
#include "qcolor.h"
#include "qpen.h"
#include "qbrush.h"

MyCanvas::MyCanvas(QWidget *parent) : QGraphicsView(parent)
{
	mainscene = new QGraphicsScene();
	setScene(mainscene);
	scale(2, 2);
	_tool = TOOL_Select;
	setSceneRect(-5000, -5000, 10000, 10000);
	_displaygrid = false;
	NewCanvas();	
	setupSelectRect();
	setupNewLineDraw();
}

void MyCanvas::setupSelectRect()
{
	QColor c(0x35, 0x60, 0xD6, 90); // 0x3560d6
	_selectionRectItem = new QGraphicsRectItem;
	_selectionRectItem->setVisible(false);
	_selectionRectItem->setPen(QPen(QBrush(c), 1, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
	c.setAlpha(40);
	_selectionRectItem->setBrush(QBrush(c));
	mainscene->addItem(_selectionRectItem);
}

void MyCanvas::setupNewLineDraw()
{
	_newSegmentItem = new QGraphicsLineItem;
	_newSegmentItem->setVisible(false);
	mainscene->addItem(_newSegmentItem);
}

MyCanvas::~MyCanvas()
{
	delete _selectionRectItem;
	delete _newSegmentItem;
	delete mainscene;
}

void MyCanvas::setGrid(bool b)
{
	_displaygrid = b;
}

void MyCanvas::NewCanvas()
{
	if (_displaygrid)
	{
		QPen pen(Qt::DotLine);
		pen.setCapStyle(Qt::RoundCap);
		pen.setJoinStyle(Qt::RoundJoin);
		const double r = 0.7;
		pen.setWidthF(r - 0.3);
		for (int x = -5000; x <= 5000; x += 100)
		{
			mainscene->addLine(x, -5000, x, 5000, pen);
			mainscene->addLine(-5000, x, 5000, x, pen);
		}
		/*pen.setWidthF(0.8);
		mainscene->addLine(0, -1000, 0, 1000, pen);
		mainscene->addLine(-1000, 0, 1000, 0, pen);*/
		QPen pen1;
		pen1.setWidthF(r + 0.4);
		QBrush brush(Qt::SolidPattern);
		for (int x = -5000; x <= 5000; x += 25)
		{
			mainscene->addEllipse(x - r / 2, -r / 2, r, r, pen1, brush);
			mainscene->addEllipse(-r / 2, x - r / 2, r, r, pen1, brush);
		}
	}
}

void MyCanvas::mouseDoubleClickEvent(QMouseEvent *event)
{
	QPointF pt = mapToScene(event->pos());
	if (mycore->Select(pt.x(), -pt.y()))
		doubleclick();
}

void MyCanvas::mouseMoveEvent(QMouseEvent* event)
{
	QPointF pt = mapToScene(event->pos());
	clickedx(pt.x());
	clickedy(-pt.y());
	if (_selectStatus)
	{
		switch (_tool)
		{
			case TOOL_Select:
			{
				_selectionRect.setBottomRight(pt);
				_selectionRectItem->setRect(_selectionRect.normalized());
				break;
			}
			case TOOL_Point:
			{
				_newSegment.setP2(pt);
				_newSegmentItem->setLine(_newSegment);
				break;
			}
			case TOOL_Zoom:
				break;
			default:
				break;
		}
	}
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
			{
				_selectStatus = true;
				_startSelectionPos = pt;
				_selectionRect.setTopLeft(pt);
				_selectionRect.setBottomRight(pt);
				_selectionRectItem->setRect(_selectionRect);
				_selectionRectItem->setVisible(true);
			}
			clickedx(pt.x());
			clickedy(-pt.y());
			break;
		}
		case TOOL_Point:
		{
			if (event->button() == Qt::LeftButton)
			{
				_selectStatus = true;
				_startSelectionPos = pt;
				_newSegment.setP1(_startSelectionPos);
				_newSegment.setP2(pt);
				_newSegmentItem->setLine(_newSegment);
				_newSegmentItem->setVisible(true);
			}
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

void MyCanvas::mouseReleaseEvent(QMouseEvent *event)
{
	_selectStatus = false;
	QPointF pt = mapToScene(event->pos());
	if (pt == _startSelectionPos)
	{
		switch (_tool)
		{
			case TOOL_Select:
			{
				mycore->Select(pt.x(), -pt.y());
				_selectionRectItem->setVisible(false);
				break;
			}
			case TOOL_Point:
			{
				mycore->AddObject(pt.x(), false, -pt.y(), false);
				_newSegmentItem->setVisible(false);
				break;
			}
		}		
	}
	else
	{
		switch (_tool)
		{
			case TOOL_Select:
			{
				mycore->Select(pt.x(), -pt.y(), _startSelectionPos.x(), -_startSelectionPos.y());
				_selectionRectItem->setVisible(false);
				break;
			}
			case TOOL_Point:
			{
				mycore->AddObject(mycore->AddObject(pt.x(), false, -pt.y(), false),
										mycore->AddObject(_startSelectionPos.x(), false, -_startSelectionPos.y(), false));
				_newSegmentItem->setVisible(false);
				break;
			}
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
