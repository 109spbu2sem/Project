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
	ui->checkX2->setVisible(false);
	ui->checkY2->setVisible(false);
	QRegExp doub("-?[0-9]{1,8}\\.[0-9]{0,8}");
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
						mycore->AddObject(ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
												ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c);
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
						unsigned id1 = mycore->AddObject(ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
																	ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c, 0);
						unsigned id2 = mycore->AddObject(ui->editX2->text().toDouble(), ui->checkX2->isChecked(),
																	ui->editY2->text().toDouble(), ui->checkY2->isChecked(), c, 0);
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
						unsigned id = mycore->AddObject(ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
																  ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c, 0);
						mycore->AddObject(id, ui->editX2->text().toDouble(), ui->checkX2->isChecked(), c, 0);
					}
					break;
				}
			}
			break;
		}
			// ----------------------------------------------------------------------------------------------------------------
		case 1:
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
						mycore->ChangePoint(ui->editID->text().toUInt(), ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
												ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c);
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
						unsigned id1 = mycore->ChangePoint(ui->editID->text().toUInt(), ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
																	ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c);
						unsigned id2 = mycore->ChangePoint(ui->editID->text().toUInt(), ui->editX2->text().toDouble(), ui->checkX2->isChecked(),
																	ui->editY2->text().toDouble(), ui->checkY2->isChecked(), c);
						mycore->ChangeSegment(0, id1, id2, c);
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
						unsigned id = mycore->ChangePoint(ui->editID->text().toUInt(), ui->editX1->text().toDouble(), ui->checkX1->isChecked(),
																  ui->editY1->text().toDouble(), ui->checkY1->isChecked(), c);
						mycore->ChangeCircle(ui->editID->text().toUInt(), id, ui->editX2->text().toDouble(), ui->checkX2->isChecked(), c);
					}
					break;
				}
			}
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

			ui->checkX2->setVisible(false);
			ui->checkY2->setVisible(false);
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

			ui->checkX2->setVisible(true);
			ui->checkY2->setVisible(true);
			break;
		}
		case 2:
		{
			ui->editX2->setPlaceholderText("R");
			ui->labelX2->setText("Radius:");
			ui->labelX1->setText("X:");
			ui->labelY1->setText("Y:");

			ui->labelX2->setVisible(true);
			ui->labelY2->setVisible(false);

			ui->editX2->setVisible(true);
			ui->editY2->setVisible(false);

			ui->checkX2->setVisible(true);
			ui->checkY2->setVisible(false);
			ui->editY2->clear();
			break;
		}
	}
}

void objectPropertiesWindow::connectCORE(CORE* core)
{
	mycore = core;
}

void objectPropertiesWindow::setupPointProperties(unsigned id, double x, bool ischeckedx, double y, bool ischeckedy, Color c)
{
	ui->typesOfObjects->setCurrentIndex(0);
	ui->typesOfObjects->setEnabled(false);
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->editX1->setText(str.setNum(x));
	ui->editY1->setText(str.setNum(y));
	ui->checkX1->setChecked(ischeckedx);
	ui->checkY1->setChecked(ischeckedy);
}

void objectPropertiesWindow::setupSegmentProperties(unsigned id, double x1, bool ischeckedx1, double y1, bool ischeckedy1,
																	 double x2, bool ischeckedx2, double y2, bool ischeckedy2, Color c)
{
	ui->typesOfObjects->setCurrentIndex(1);
	ui->typesOfObjects->setEnabled(false);
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->editX1->setText(str.setNum(x1));
	ui->editY1->setText(str.setNum(y1));
	ui->editX2->setText(str.setNum(x2));
	ui->editY2->setText(str.setNum(y2));
	ui->checkX1->setChecked(ischeckedx1);
	ui->checkY1->setChecked(ischeckedy1);
	ui->checkX2->setChecked(ischeckedx2);
	ui->checkY2->setChecked(ischeckedy2);
}

void objectPropertiesWindow::setupCircleProperties(unsigned id, double x, bool ischeckedx, double y, bool ischeckedy,
																	double r, bool ischecked, Color c)
{
	ui->typesOfObjects->setCurrentIndex(2);
	ui->typesOfObjects->setEnabled(false);
	ui->editID->setEnabled(false);
	QString str;
	ui->editID->setText(str.setNum(id));
	ui->editR->setText(str.setNum(c.red()));
	ui->editG->setText(str.setNum(c.green()));
	ui->editB->setText(str.setNum(c.blue()));
	ui->editX1->setText(str.setNum(x));
	ui->editY1->setText(str.setNum(y));
	ui->editX2->setText(str.setNum(r));
	ui->checkX1->setChecked(ischeckedx);
	ui->checkY1->setChecked(ischeckedy);
	ui->checkX2->setChecked(ischecked);
}