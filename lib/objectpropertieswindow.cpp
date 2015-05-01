#include "objectpropertieswindow.h"
#include "ui_objectpropertieswindow.h"

objectPropertiesWindow::objectPropertiesWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::objectPropertiesWindow)
{
	ui->setupUi(this);	
}

objectPropertiesWindow::~objectPropertiesWindow()
{
	delete ui;
}

void objectPropertiesWindow::on_buttonBox_accepted()
{
	this->close();
}

void objectPropertiesWindow::on_buttonBox_rejected()
{
	this->close();
}

void objectPropertiesWindow::setupPointProperties(unsigned id, double x, double y, QColor& c)
{
	ui->textX2->setVisible(false);
	ui->textY2->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
	QString str;
	ui->idLabel->setText(str.setNum(id));
	ui->typeLabel->setText("Point");
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->textX1->setText(str.setNum(x));
	ui->textY1->setText(str.setNum(y));
}

void objectPropertiesWindow::setupSegmentProperties(unsigned id, double x, double y, double x2, double y2, QColor& c)
{
	QString str;
	ui->idLabel->setText(str.setNum(id));
	ui->typeLabel->setText("Segment");
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->textX1->setText(str.setNum(x));
	ui->textY1->setText(str.setNum(y));
	ui->textX2->setText(str.setNum(x2));
	ui->textY2->setText(str.setNum(y2));
}

void objectPropertiesWindow::setupCircleProperties(unsigned id, double x, double y, double r, QColor& c)
{
	ui->textY2->setVisible(false);
	ui->label_3->setText("R");
	ui->label_4->setVisible(false);
	QString str;
	ui->idLabel->setText(str.setNum(id));
	ui->typeLabel->setText("Circle");
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->textX1->setText(str.setNum(x));
	ui->textY1->setText(str.setNum(y));
	ui->textX2->setText(str.setNum(r));
}