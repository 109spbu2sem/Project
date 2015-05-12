#include "objectpropertieswindow.h"
#include "ui_objectpropertieswindow.h"

objectPropertiesWindow::objectPropertiesWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::objectPropertiesWindow)
{
	ui->setupUi(this);
	ui->editX2->setVisible(false);
	ui->editY2->setVisible(false);
	ui->labelX2->setVisible(false);
	ui->labelY2->setVisible(false);
	QRegExp doub("\-?[0-9]{1,8}\\.[0-9]{0,8}");
	doubvalid = new QRegExpValidator(doub, this);
	ui->editX1->setValidator(doubvalid);
	ui->editY1->setValidator(doubvalid);
	ui->editX2->setValidator(doubvalid);
	ui->editY2->setValidator(doubvalid);
	QRegExp uns("[0-9]*");
	unsvalid = new QRegExpValidator(uns, this);
	ui->editR->setValidator(unsvalid);
	ui->editG->setValidator(unsvalid);
	ui->editB->setValidator(unsvalid);
	ui->editID->setValidator(unsvalid);
	
	flag = 0;
}

objectPropertiesWindow::~objectPropertiesWindow()
{
	delete doubvalid;
	delete unsvalid;
	delete ui;
}

void objectPropertiesWindow::on_buttonBox_accepted()
{
	switch (flag)
	{
		case 0:
		{
			switch (ui->typesOfObjects->currentIndex())
			{
				// add point
				case 0:
				{
					if (!ui->editX1->text().isEmpty() &&
						 !ui->editY1->text().isEmpty() /*&&
																 ui->editX1->text(). &&
																 ui->editY1->text().toDouble()*/)
					{
						Color c;
						c.setColor(ui->editR->text().toUInt(), ui->editG->text().toUInt(), ui->editB->text().toUInt());
						mycore->AddObject(ui->editX1->text().toDouble(),
												ui->editY1->text().toDouble(), c);
					}
					break;
				}
					// add segment
				case 1:
				{
					if (!ui->editX1->text().isEmpty() &&
						 !ui->editY1->text().isEmpty() &&
						 !ui->editX2->text().isEmpty() &&
						 !ui->editY2->text().isEmpty() /*&&
																 ui->editX1->text().toDouble() &&
																 ui->editY1->text().toDouble() &&
																 ui->editX2->text().toDouble() &&
																 ui->editY2->text().toDouble()*/)
					{
						Color c;
						c.setColor(ui->editR->text().toUInt(), ui->editG->text().toUInt(), ui->editB->text().toUInt());
						unsigned id1 = mycore->AddObject(ui->editX1->text().toDouble(), ui->editY1->text().toDouble(), c, 0);
						unsigned id2 = mycore->AddObject(ui->editX2->text().toDouble(), ui->editY2->text().toDouble(), c, 0);
						mycore->AddObject(id1, id2, c, 0);
					}
					break;
				}
					// add circle
				case 2:
				{
					if (!ui->editX1->text().isEmpty() &&
						 !ui->editY1->text().isEmpty() &&
						 !ui->editX2->text().isEmpty() /*&&
																 ui->editX1->text().toDouble() &&
																 ui->editY1->text().toDouble() &&
																 ui->editX2->text().toDouble()*/)
					{
						Color c;
						c.setColor(ui->editR->text().toUInt(), ui->editG->text().toUInt(), ui->editB->text().toUInt());
						unsigned id = mycore->AddObject(ui->editX1->text().toDouble(), ui->editY1->text().toDouble(), c, 0);
						mycore->AddObject(id, ui->editX2->text().toDouble(), c, 0);
					}
					break;
				}
			}
			break;
		}
		case 1:
		{
			break;
		}
	}
	this->close();
}

void objectPropertiesWindow::setFlag(unsigned f)
{
	flag = f;
}

void objectPropertiesWindow::on_buttonBox_rejected()
{
	this->close();
}

void objectPropertiesWindow::on_typesOfObjects_currentIndexChanged(int index)
{
	switch (index)
	{
		case 0:
		{
			ui->labelX1->setText("X:");
			ui->labelY1->setText("Y:");
			ui->editX2->setVisible(false);
			ui->editY2->setVisible(false);
			ui->labelX2->setVisible(false);
			ui->labelY2->setVisible(false);
			ui->editX2->clear();
			ui->editY2->clear();
			break;
		}
		case 1:
		{
			ui->labelX1->setText("X1:");
			ui->labelY1->setText("Y1:");
			ui->labelX2->setText("X2:");
			ui->editX2->setVisible(true);
			ui->editY2->setVisible(true);
			ui->labelY2->setVisible(true);
			ui->labelX2->setVisible(true);
			ui->editX2->setPlaceholderText("X");
			break;
		}
		case 2:
		{
			ui->editX2->setPlaceholderText("R");
			ui->labelX2->setText("Radius:");
			ui->labelX1->setText("X:");
			ui->labelY1->setText("Y:");
			ui->labelX2->setVisible(true);
			ui->editX2->setVisible(true);
			ui->editY2->setVisible(false);
			ui->labelY2->setVisible(false);
			ui->editY2->clear();
			break;
		}
	}
}

void objectPropertiesWindow::connectCORE(CORE* core)
{
	mycore = core;
}

void objectPropertiesWindow::setupPointProperties(unsigned id, double x, double y, QColor& c)
{
	ui->labelX2->setVisible(false);
	ui->labelY2->setVisible(false);
	ui->editY2->setVisible(false);
	ui->editX2->setVisible(false);
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->editX1->setText(str.setNum(x));
	ui->editY1->setText(str.setNum(y));
}

void objectPropertiesWindow::setupSegmentProperties(unsigned id, double x, double y, double x2, double y2, QColor& c)
{
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->editX1->setText(str.setNum(x));
	ui->editY1->setText(str.setNum(y));
	ui->editX2->setText(str.setNum(x2));
	ui->editY2->setText(str.setNum(y2));
}

void objectPropertiesWindow::setupCircleProperties(unsigned id, double x, double y, double r, QColor& c)
{
	ui->labelY2->setVisible(false);
	ui->labelX2->setText("R");
	ui->labelY2->setVisible(false);
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->labelX1->setText(str.setNum(x));
	ui->labelY1->setText(str.setNum(y));
	ui->labelX2->setText(str.setNum(r));
}