#include "objectpropertieswindow.h"
#include "ui_objectpropertieswindow.h"
#include <QString>
#include "storages.h"
#include "global.h"

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

void objectPropertiesWindow::on_objectTypeBox_currentIndexChanged(int index)
{
	switch(index)
	{
	case 0:
	{
		ui->textX2->setEnabled(false);
		ui->textY2->setEnabled(false);
		ui->textX2->clear();
		ui->textY2->clear();
		break;
	}
	case 1:
	{
		ui->textX2->setEnabled(true);
		ui->textY2->setEnabled(true);
		break;
	}
	}
}

void objectPropertiesWindow::on_buttonBox_accepted()
{
	switch (ui->objectTypeBox->count())
	{
	//ADD POINT
	case 0:
	{
		bool ok;
		Point p;
		p.x = ui->textX1->text().toDouble(&ok);
		if (!ok) break;
		p.y = ui->textY1->text().toDouble(&ok);
		if (!ok) break;
		//here some actions
		//GLOBAL::storage.points.add(p);
		//storage.points.add(p);
		break;
	}
	//ADD SEGMENT
	case 1:
	{
		bool ok;
		Point p;
		Segment s;
		p.x = ui->textX1->text().toDouble(&ok);
		if (!ok) break;
		p.y = ui->textY1->text().toDouble(&ok);
		if (!ok) break;
		s.o = p;
		p.x = ui->textX2->text().toDouble(&ok);
		if (!ok) break;
		p.y = ui->textY2->text().toDouble(&ok);
		if (!ok) break;
		s.d = p;
		//here some actions
		//GLOBAL::storage.segments.add(s);
		break;
	}
	}
}
