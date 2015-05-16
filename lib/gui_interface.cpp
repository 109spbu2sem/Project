#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include "QtWidgets\qgraphicssceneevent.h"
#include "mycanvas.h"
#include "QtWidgets\qmessagebox.h"
#include <QString>
#include "QtWidgets\qfiledialog.h"
#include "QtWidgets\qlistview.h"
#include "qlist.h"
#include <QList>

bool GUI::SetNameOfWindow(std::string header)
{
	setWindowTitle(QString(header.c_str()));
	return true;
}

void GUI::WriteError(const char* Text)
{
	ui->statusBar->setText("Error");
	QMessageBox b;
	b.setText(Text);
	b.exec();
	return;
}

void GUI::WriteStatus(const char* Text)
{
	ui->statusBar->setText(Text);
	this->repaint();
	return;
}

void GUI::WriteMessage(const char* Text)
{
	ui->messageBar->setText(Text);
	this->repaint();
	return;
}
// Write Short to status bar, Long to message bar
void GUI::WriteText(const char* Short, const char* Long)
{
	ui->statusBar->setText(Short);
	ui->messageBar->setText(Long);
	this->repaint();
}

bool GUI::Set_properties_of_point(unsigned id, double x, double y, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Point");
	item->setData(17, static_cast<unsigned>(POINT));
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
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

bool GUI::Set_properties_of_segment(unsigned id, double x1, double y1, double x2, double y2, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Segment");
	item->setData(17, static_cast<unsigned>(SEGMENT));
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
	return true;
}

bool GUI::Set_properties_of_circle(unsigned id, double x, double y, double r, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Circle");
	item->setData(17, static_cast<unsigned>(CIRCLE));
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
	if (x != x || y != y) return false; // check for NaN
	mainscene->addEllipse(x - 1.2, -y - 1.2, 2.4, 2.4,
								 selected ? QPen(QColor(QRgb(COLORSELECTED))) :
								 QPen(QColor(c.red(), c.green(), c.blue())),
								 selected ? QBrush(QColor(QRgb(COLORSELECTED))) :
								 QBrush(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tPoint";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
		it->setSelected(true);
	return true;
}

bool GUI::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c, bool selected)
{
	if (x1 != x1 || y1 != y1 || x2 != x2 || y2 != y2) return false; // check for NaN
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
		it->setSelected(true);
	return true;
}

bool GUI::DrawCircle(unsigned id, double x, double y, double r, Color c, bool selected)
{
	if (x != x || y != y || r != r) return false; // check for NaN
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
		it->setSelected(true);
	return true;
}

bool GUI::Clear()
{
	mainscene->clear();
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	ui->objectsList->clear();
	return true;
}

bool GUI::WriteRule(unsigned id1, unsigned id2, CONSTR_TYPE type)
{
	QString s;
	s = ConstrTypeToString(type);
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, type);
	ui->rulesList->addItem(it);
	return true;
}
bool GUI::WriteRule(unsigned id1, unsigned id2, CONSTR_TYPE type, double value)
{
	return true;
}
bool GUI::WriteRule(unsigned id1, unsigned id2, unsigned id3, CONSTR_TYPE type)
{
	return true;
}
bool GUI::WriteRule(unsigned id1, unsigned id2, unsigned id3, CONSTR_TYPE type, double value)
{
	return true;
}