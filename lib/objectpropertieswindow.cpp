#include "objectpropertieswindow.h"
#include "ui_objectpropertieswindow.h"

objectPropertiesWindow::objectPropertiesWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::objectPropertiesWindow)
{
	ui->setupUi(this);	
	ui->textX2->setVisible(false);
	ui->textY2->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);
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
		ui->label->setText("X:");
		ui->label_2->setText("Y:");
		ui->textX2->setVisible(false);
		ui->textY2->setVisible(false);
		ui->label_4->setVisible(false);
		ui->label_3->setVisible(false);
		ui->textX2->clear();
		ui->textY2->clear();
		break;
	}
	case 1:
	{
		ui->label->setText("X1:");
		ui->label_2->setText("Y1:");
		ui->label_3->setText("X2:");
		ui->textX2->setVisible(true);
		ui->textY2->setVisible(true);
		ui->label_4->setVisible(true);
		ui->label_3->setVisible(true);
		ui->textX2->setPlaceholderText("X");
		break;
	}
	case 2:
	{
		ui->textX2->setPlaceholderText("R");
		ui->label_3->setText("Radius:");
		ui->label->setText("X:");
		ui->label_2->setText("Y:");
		ui->label_3->setVisible(true);
		ui->textX2->setVisible(true);
		ui->textY2->setVisible(false);
		ui->label_4->setVisible(false);
		ui->textY2->clear();
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
	case 2:
	{
		break;
	}
	}
}
