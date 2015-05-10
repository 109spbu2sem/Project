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
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mycore = 0;
	mainscene = ui->graphicsView->getScene();
	ui->graphicsView->connectCORECanvas(mycore);
	ui->graphicsView->scale(2, 2);
	//ui->objectsList->setColumnCount(6);
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	toolsbuttons = new QButtonGroup;
	toolsbuttons->addButton(ui->selectBTNTool);
	toolsbuttons->addButton(ui->pointBTNTool);
	toolsbuttons->addButton(ui->ZoomBTNTool);
}

void MainWindow::ConnectCORE(CORE* core)
{
	mycore = core;
	ui->graphicsView->connectCORECanvas(core);
}

MainWindow::~MainWindow()
{
	delete toolsbuttons;
	delete ui;
}

void MainWindow::WriteError(const char* Text)
{
	ui->statusBar->setText("Error");
	QMessageBox b;
	b.setText(Text);
	b.exec();
	return;
}

void MainWindow::WriteStatus(const char* Text)
{
	ui->statusBar->setText(Text);
	return;
}

void MainWindow::WriteMessage(const char* Text)
{
	ui->messageBar->setText(Text);
	return;
}

bool MainWindow::DrawPoint(unsigned id, double x, double y, Color c, unsigned mode)
{
	if (mode)
	{
		/*ui->typesOfObjects->setCurrentIndex(0);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x));
		ui->editY1->setText(s.setNum(y));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));*/
	}
	else
	{
		mainscene->addEllipse(x - 1.2, -y - 1.2, 2.4, 2.4,
									 QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))),
									 QBrush(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	}
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

bool MainWindow::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c, unsigned mode)
{
	if (mode)
	{
		/*ui->typesOfObjects->setCurrentIndex(1);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x1));
		ui->editY1->setText(s.setNum(y1));
		ui->editX2->setText(s.setNum(x2));
		ui->editY2->setText(s.setNum(y2));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));*/
	}
	else
	{
		mainscene->addLine(x1, -y1, x2, -y2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	}
	return true;
}

bool MainWindow::DrawCircle(unsigned id, double x, double y, double r, Color c, unsigned mode)
{
	if (mode)
	{
		/*ui->typesOfObjects->setCurrentIndex(2);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x));
		ui->editY1->setText(s.setNum(y));
		ui->editX2->setText(s.setNum(r));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));*/
	}
	else
	{
		mainscene->addEllipse(x - r, -y - r, r * 2, r * 2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	}
	return true;
}

bool MainWindow::Clear()
{	
	mainscene->clear();
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	//ui->objectsList->clear();
	return true;
}

void MainWindow::on_openAddingBTN_clicked()
{
    objectPropertiesWindow ow = objectPropertiesWindow(this);
	 ow.connectCORE(mycore);
	 WriteStatus("Add object");
	 ow.exec();
	 WriteStatus("Done");
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
		{
			mycore->AddRule(CONSTR_P2PDIST, ui->ruleValueEdit->text().toDouble());
			mycore->Calculate();
		}
		else
			WriteStatus("Need value");
		break;
	}
	case 1:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
		{
			mycore->AddRule(CONSTR_P2LINEDIST, ui->ruleValueEdit->text().toDouble());
			mycore->Calculate();
		}
		else
			WriteStatus("Need value");
		break;
	}
	case 2:
	{
		mycore->AddRule(CONSTR_3PONLINE);
		mycore->Calculate();
		break;
	}
	case 3:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
		{
			mycore->AddRule(CONSTR_3PRATIO, ui->ruleValueEdit->text().toDouble());
			mycore->Calculate();
		}
		else
			WriteStatus("Need value");
		break;
	}
	case 4:
	{
		if (!ui->ruleValueEdit->text().isEmpty())
		{
			mycore->AddRule(CONSTR_L2LANGLE, ui->ruleValueEdit->text().toDouble());
			mycore->Calculate();
		}
		else
			WriteStatus("Need value");
		break;
	}
	}
	ui->ruleValueEdit->clear();
}

void MainWindow::on_concatinateBTN_clicked()
{
	mycore->ConcatenatePoints();
}

void MainWindow::on_selectBTNTool_clicked()
{
    ui->graphicsView->setTool(TOOL_Select);
}

void MainWindow::on_pointBTNTool_clicked()
{
    ui->graphicsView->setTool(TOOL_Point);
}

void MainWindow::on_ZoomBTNTool_clicked()
{
    ui->graphicsView->setTool(TOOL_Zoom);
}

void MainWindow::on_actionClose_triggered()
{
	// need add dialog if had changes
	close();
}

void MainWindow::on_actionRedraw_all_triggered()
{
	mycore->Calculate();
}

void MainWindow::on_actionSave_triggered()
{
	// need add save as if 1st time
	mycore->IWantSave();
}

void MainWindow::on_actionSave_As_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	mycore->IWantSaveAs(filename);
}

void MainWindow::on_actionClear_all_triggered()
{
	mycore->DeleteAll();
}

void MainWindow::on_actionLoad_triggered()
{
	// here load function
}