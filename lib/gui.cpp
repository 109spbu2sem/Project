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
	ui->editX2->setVisible(false);
	ui->editY2->setVisible(false);
	ui->labelX2->setVisible(false);
	ui->labelY2->setVisible(false);
	ui->graphicsView->connectCORECanvas(mycore);
	ui->graphicsView->scale(2, 2);
	//ui->objectsList->setColumnCount(6);
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	/*QPixmap pixpam1("icons/pointbtn.png");
	ui->pointBTNTool->setIcon(pixpam1);
	ui->pointBTNTool->setIconSize(pixpam1.rect().size());*/
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
		ui->typesOfObjects->setCurrentIndex(0);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x));
		ui->editY1->setText(s.setNum(y));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));
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
		ui->typesOfObjects->setCurrentIndex(1);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x1));
		ui->editY1->setText(s.setNum(y1));
		ui->editX2->setText(s.setNum(x2));
		ui->editY2->setText(s.setNum(y2));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));
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
		ui->typesOfObjects->setCurrentIndex(2);
		QString s;
		ui->editID->setText(s.setNum(id));
		ui->editX1->setText(s.setNum(x));
		ui->editY1->setText(s.setNum(y));
		ui->editX2->setText(s.setNum(r));
		ui->editR->setText(s.setNum(c.getColor(1)));
		ui->editG->setText(s.setNum(c.getColor(2)));
		ui->editB->setText(s.setNum(c.getColor(3)));
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
	 ow.exec();
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
			unsigned id1 = mycore->AddObject(ui->editX1->text().toDouble(), ui->editY1->text().toDouble(), c, 0, true);
			unsigned id2 = mycore->AddObject(ui->editX2->text().toDouble(), ui->editY2->text().toDouble(), c, 0, true);
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
			/*mycore->AddObject(ui->editX1->text().toDouble(),
							  ui->editY1->text().toDouble(),
							  ui->editX2->text().toDouble(), c);*/
			unsigned id = mycore->AddObject(ui->editX1->text().toDouble(), ui->editY1->text().toDouble(), c, 0, true);
			mycore->AddObject(id, ui->editX2->text().toDouble(), c, 0);
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
		mycore->AddRule(CONSTR_3PONLINE);
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

void MainWindow::on_saveButton_clicked() {
	mycore->IWantSave();
}

void MainWindow::on_saveAsButton_clicked() {
	QString filename = QFileDialog::getSaveFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	mycore->IWantSaveAs(filename);
}

void MainWindow::on_deleteAllBTN_clicked()
{
	mycore->DeleteAll();
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
