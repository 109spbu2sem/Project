#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include "QtWidgets/qgraphicssceneevent.h"
#include "mycanvas.h"
#include "QtWidgets/qmessagebox.h"
#include <QString>
#include "QtWidgets/qfiledialog.h"
#include "QtWidgets/qlistview.h"
#include "qlist.h"
#include <QList>

bool GUI::SetNameOfWindow(std::string header)
{
	setWindowTitle(QString(header.c_str()));
	return true;
}

void GUI::WriteError(const char* Text)
{
	ui->bottonBar->setStyleSheet(QLatin1String("background-color: rgb(202, 81, 0); color: rgb(255, 255, 255);}"));
	this->repaint();
	QMessageBox b;
	b.setText(Text);
	b.exec();
	ui->bottonBar->setStyleSheet(QLatin1String("background-color: rgb(0, 122, 204); color: rgb(255, 255, 255);"));
	return;
}

void GUI::StartWorkStatus()
{
	ui->workStatusLabel->setVisible(true);
	_loadcircle->start();
}

void GUI::StopWorkStatus()
{
	ui->workStatusLabel->setVisible(false);
	_loadcircle->stop();
}

// Write Short to status bar, Long to message bar
void GUI::WriteText(const char* Short, const char* Long)
{
	ui->statusBar->setText(Short);
	ui->messageBar->setText(Long);
	this->repaint();
}

bool GUI::Set_properties_of_point(unsigned id, double x, double y,
											 bool isx, bool isy, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Point");
	item->setData(17, PRIMITIVE_POINT);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	item->setData(18, isx);
	item->setData(19, isy);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x);
	item->setText("x:\t" + s);
	item->setData(17, x);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y);
	item->setText("y:\t" + s);
	item->setData(17, y);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

bool GUI::Set_properties_of_segment(unsigned id, double x1, double y1, double x2, double y2,
												bool isx1, bool isy1, bool isx2, bool isy2, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Segment");
	item->setData(17, PRIMITIVE_SEGMENT);
	item->setData(18, isx1);
	item->setData(19, isy1);
	item->setData(20, isx2);
	item->setData(21, isy2);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x1);
	item->setText("x1:\t" + s);
	item->setData(17, x1);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y1);
	item->setText("y1:\t" + s);
	item->setData(17, y1);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x2);
	item->setText("x2:\t" + s);
	item->setData(17, x2);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y2);
	item->setText("y2:\t" + s);
	item->setData(17, y2);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	item = new QListWidgetItem;
	s.setNum(length(x1, y1, x2, y2));
	item->setText("length:\t" + s);
	ui->propertiesList->addItem(item);
	return true;
}

bool GUI::Set_properties_of_circle(unsigned id, double x, double y, double r,
											  bool isx, bool isy, bool isr, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Circle");
	item->setData(17, PRIMITIVE_CIRCLE);
	item->setData(18, isx);
	item->setData(19, isy);
	item->setData(20, isr);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x);
	item->setText("x:\t" + s);
	item->setData(17, x);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y);
	item->setText("y:\t" + s);
	item->setData(17, y);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(r);
	item->setText("r:\t" + s);
	item->setData(17, r);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

void GUI::Clear_properties()
{
	ui->propertiesList->clear();
}

bool GUI::DrawPoint(unsigned id, double x, double y, Color c, bool selected)
{
	// if (x != x || y != y) return false; // check for NaN
	if (!(std::isinf(x) || std::isinf(y)))
		mainscene->addEllipse(x - _pointradius, -y - _pointradius, _pointradius * 2, _pointradius * 2,
		selected ? *_selectPen :
		QPen(QColor(c.red(), c.green(), c.blue())),
		selected ? *_selectBrush :
		QBrush(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tPoint";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
	{
		it->setSelected(true);

		mainscene->addEllipse(x  - _selectpointradius - _selectPradius - _constIndent,
									-y  - _selectpointradius - _selectPradius - _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x  + _selectpointradius - _selectPradius + _constIndent,
									-y  - _selectpointradius - _selectPradius - _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x  + _selectpointradius - _selectPradius + _constIndent,
									-y  + _selectpointradius - _selectPradius + _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x  - _selectpointradius - _selectPradius - _constIndent,
									-y  + _selectpointradius - _selectPradius + _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
	}
	return true;
}

bool GUI::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c, bool selected)
{
	//if (x1 != x1 || y1 != y1 || x2 != x2 || y2 != y2) return false; // check for NaN
	if (!(std::isinf(x1) || std::isinf(y1) || std::isinf(x2) || std::isinf(y2)))
		mainscene->addLine(x1, -y1, x2, -y2,
		selected ? QPen(QColor(QRgb(COLORSELECTED))) :
		QPen(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tSegment";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
	{
		it->setSelected(true);
	}
	return true;
}

bool GUI::DrawCircle(unsigned id, double x, double y, double r, Color c, bool selected)
{
	//if (x != x || y != y || r != r) return false; // check for NaN
	if (!(std::isinf(x) || std::isinf(y) || std::isinf(r)))
		mainscene->addEllipse(x - r, -y - r, r * 2, r * 2,
		selected ? QPen(QColor(QRgb(COLORSELECTED))) :
		QPen(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tCircle";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
	{
		it->setSelected(true);
		mainscene->addEllipse(x - r - _selectPradius - _constIndent,
									-y - r - _selectPradius - _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x + r - _selectPradius + _constIndent,
									-y - r - _selectPradius - _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x + r - _selectPradius + _constIndent,
									-y + r - _selectPradius + _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
		mainscene->addEllipse(x - r - _selectPradius - _constIndent,
									-y + r - _selectPradius + _constIndent,
									_selectPradius * 2, _selectPradius * 2, *_selectPen, *_selectBrush);
	}
	return true;
}

bool GUI::Clear()
{
	mainscene->clear();
	ui->myCanvas->NewCanvas();
	ui->objectsList->clear();
	ui->myCanvas->setupSelectRect();
	return true;
}

bool GUI::ClearRules()
{
	ui->rulesList->clear();
	return true;
}

bool GUI::WriteRule(unsigned myid, unsigned id1, unsigned id2, CONSTR_TYPE type)
{
	QString s;
	s = ConstrTypeToString(type);
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, type);
	it->setData(18, 0);
	it->setData(19, id1);
	it->setData(20, id2);
	it->setData(21, 0);
	it->setData(22, myid);
	ui->rulesList->addItem(it);
	return true;
}
bool GUI::WriteRule(unsigned myid, unsigned id1, unsigned id2, CONSTR_TYPE type, double value)
{
	QString s;
	s = ConstrTypeToString(type);
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, type);
	it->setData(18, value);
	it->setData(19, id1);
	it->setData(20, id2);
	it->setData(21, 0);
	it->setData(22, myid);
	ui->rulesList->addItem(it);
	return true;
}
bool GUI::WriteRule(unsigned myid, unsigned id1, unsigned id2, unsigned id3, CONSTR_TYPE type)
{
	QString s;
	s = ConstrTypeToString(type);
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, type);
	it->setData(18, 0);
	it->setData(19, id1);
	it->setData(20, id2);
	it->setData(21, id3);
	it->setData(22, myid);
	ui->rulesList->addItem(it);
	return true;
}
bool GUI::WriteRule(unsigned myid, unsigned id1, unsigned id2, unsigned id3, CONSTR_TYPE type, double value)
{
	QString s;
	s = ConstrTypeToString(type);
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, type);
	it->setData(18, value);
	it->setData(19, id1);
	it->setData(20, id2);
	it->setData(21, id3);
	it->setData(22, myid);
	ui->rulesList->addItem(it);
	return true;
}