#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "mycanvas.h"
#include <QMessageBox>
#include <QString>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mycore = 0;
	mainscene = ui->graphicsView->getScene();
	ui->editX2->setVisible(false);
	ui->editY2->setVisible(false);
	ui->labelX2->setVisible(false);
	ui->labelY2->setVisible(false);
	ui->graphicsView->connectCORECanvas(mycore);
	ui->graphicsView->scale(2, 2);
	//ui->objectsList->setColumnCount(6);
	mainscene->addLine(0, -10000, 0, 10000, QPen(Qt::DotLine));
	mainscene->addLine(-10000, 0, 10000, 0, QPen(Qt::DotLine));
}

void MainWindow::ConnectCORE(CORE* core)
{
	mycore = core;
	ui->graphicsView->connectCORECanvas(core);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::WriteError(const char* ErrorText)
{
	ui->statusBar->showMessage("Error", 7000);
	QMessageBox b;
	b.setText(ErrorText);
	b.exec();
	return;
}

void MainWindow::WriteStatus(const char* ErrorKey)
{
	ui->statusBar->showMessage(ErrorKey);
	return;
}

bool MainWindow::DrawPoint(unsigned id, double x, double y, Color c)
{
	mainscene->addEllipse(x - 1, -y - 1, 2.0, 2.0,
		QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))),
		QBrush(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	/*for (unsigned i = 0; i < 10000; i++)
	{
	ui->objectsList->setRowCount(ui->objectsList->rowCount());
	QTableWidgetItem* item = new QTableWidgetItem;//(tr("%1").arg((ui->objectsList->rowCount()+1)*(0+1)));
	item->setText("Point");
	ui->objectsList->setItem(ui->objectsList->rowCount() - 1, 0, item);
	//ui->objectsList->setItem();
	}*/
	return true;
}

bool MainWindow::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c)
{
	mainscene->addLine(x1, -y1, x2, -y2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	return true;
}

bool MainWindow::DrawCircle(unsigned id, double x, double y, double r, Color c)
{
	mainscene->addEllipse(x - r, -y - r, r * 2, r * 2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	return true;
}

bool MainWindow::Clear()
{	
	mainscene->clear();
	mainscene->addLine(0, -10000, 0, 10000, QPen(Qt::DotLine));
	mainscene->addLine(-10000, 0, 10000, 0, QPen(Qt::DotLine));
	ui->objectsList->clear();
	return true;
}

void MainWindow::on_openAddingBTN_clicked()
{
    objectPropertiesWindow * ow = new objectPropertiesWindow(this);
	 ow->exec();
	 WriteError("Test Error");
}

void MainWindow::on_addBTN_clicked()
{
	switch (ui->typesOfObjects->currentIndex())
	{
		// add point
	case 0:
	{
		if (!ui->editX1->text().isEmpty() &&
				!ui->editY1->text().isEmpty() /*&&
				ui->editX1->text().toDouble() &&
				ui->editY1->text().toDouble()*/)
		{
			Color c;
			c.setColor(ui->editR->text().toUInt(), ui->editG->text().toUInt(), ui->editB->text().toUInt());
			mycore->AddObject(ui->editX1->text().toDouble(),
							  ui->editY1->text().toDouble(), c.getColor());
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
			mycore->AddObject(ui->editX1->text().toDouble(),
							  ui->editY1->text().toDouble(),
							  ui->editX2->text().toDouble(),
							  ui->editY2->text().toDouble(), c.getColor());
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
			mycore->AddObject(ui->editX1->text().toDouble(),
							  ui->editY1->text().toDouble(),
							  ui->editX2->text().toDouble(), c.getColor());
		}
		break;
	}
	}
}

void MainWindow::on_typesOfObjects_currentIndexChanged(int index)
{
	switch(index)
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

void MainWindow::on_calculateBTN_clicked()
{
    mycore->Calculate();
}

void MainWindow::on_ruleBox_currentIndexChanged(int index)
{
    switch (index)
	{
	case 2:
	{
		ui->ruleValueEdit->setEnabled(false);
		break;
	}
	default:
	{
		if (!ui->ruleValueEdit->isEnabled())
			ui->ruleValueEdit->setEnabled(true);
		break;
	}
	}
	return;
}

void MainWindow::on_pushButton_clicked()
{
    switch (ui->ruleBox->currentIndex())
	{
	case 0:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
			mycore->AddRule(CONSTR_P2PDIST, ui->ruleValueEdit->text().toDouble());
		else
			WriteStatus("Need value");
		break;
	}
	case 1:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
			mycore->AddRule(CONSTR_P2LINEDIST, ui->ruleValueEdit->text().toDouble());
		else
			WriteStatus("Need value");
		break;
	}
	case 2:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
			mycore->AddRule(CONSTR_3PONLINE);
		else
			WriteStatus("Need value");
		break;
	}
	case 3:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
			mycore->AddRule(CONSTR_3PRATIO, ui->ruleValueEdit->text().toDouble());
		else
			WriteStatus("Need value");
		break;
	}
	case 4:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
			mycore->AddRule(CONSTR_L2LANGLE, ui->ruleValueEdit->text().toDouble());
		else
			WriteStatus("Need value");
		break;
	}
	}
	ui->ruleValueEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    mycore->ClearSelection();
}

void MainWindow::on_concatinateBTN_clicked()
{
	mycore->ConcatenatePoints();
}

void MainWindow::on_selectTool_clicked()
{
    ui->graphicsView->setTool(TOOL_Select);
}

void MainWindow::on_pointTool_clicked()
{
    ui->graphicsView->setTool(TOOL_Point);
}
