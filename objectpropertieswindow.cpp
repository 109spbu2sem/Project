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
		break;
	}
	//ADD SEGMENT
	case 1:
	{
		break;
	}
	}
}
