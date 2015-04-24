#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "mycanvas.h"

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
	ui->graphicsView->scale(3, 3);
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

void MainWindow::WriteError(unsigned ErrorKey)
{
	ui->statusBar->showMessage("Error");
	return;
}

void MainWindow::WriteStatus(const char* ErrorKey)
{
	ui->statusBar->showMessage(ErrorKey);
	return;
}

bool MainWindow::Redraw()
{
	if (!mycore->OpenStream()) return false;
	
	mainscene->clear();
	while (mycore->StreamIsOpened())
	{
		CORE::Primitive p;
		p.type = PRIMITIVE_NOTHING;
		try
		{
			p = mycore->GetFromStream();
		}
		catch (std::logic_error a)
		{
			mycore->CloseStream();
			return true;
		}

		QPen pen(QColor(p.color.getColor(1), p.color.getColor(2), p.color.getColor(3)));
		
	switch (p.type)
	{
	case PRIMITIVE_POINT:
	{
		QBrush brush(QColor(p.color.getColor(1), p.color.getColor(2), p.color.getColor(3)));
		mainscene->addEllipse(p.p1_x - 1, p.p1_y - 1, 2.0, 2.0, pen, brush);
		//mainscene->addLine(p.p1_x, p.p1_y, p.p1_x, p.p1_y, pen);
		break;
	}
	case PRIMITIVE_SEGMENT:
	{
		mainscene->addLine(p.p1_x, p.p1_y, p.p2_x, p.p2_y, pen);
		break;
	}
	case PRIMITIVE_CIRCLE: 
	{
		mainscene->addEllipse(p.p1_x - p.r, p.p1_y - p.r, p.r * 2, p.r * 2, pen);
		break;
	}
	default:
		break;
	}
	}
	mycore->CloseStream();
	return true;
}

/*bool GUI::Redraw()
{
	if (mycore->OpenStream()) return false;
	
	mainwindow->graphicsView->setScene(0);
	delete mainscene;
	mainscene = new QGraphicsScene;
	while (mycore->StreamIsOpened())
	{
		CORE::Primitive p = mycore->GetFromStream();
		QPen pen;
		pen.setColor(QColor(p.color.getColor(1), p.color.getColor(2), p.color.getColor(3)));
	switch (p.type)
	{
	case PRIMITIVE_POINT:
	{
		//mainscene->addEllipse(p.p1_x, p.p1_y, 2.0, 2.0);
		mainscene->addLine(p.p1_x, p.p1_y, p.p1_x, p.p1_y, pen);
		break;
	}
	case PRIMITIVE_SEGMENT:
	{
		mainscene->addLine(p.p1_x, p.p1_y, p.p2_x, p.p2_y, pen);
		break;
	}
	case PRIMITIVE_CIRCLE: 
	{
		mainscene->addEllipse(p.p1_x + p.r, p.p1_y - p.r, p.r * 2.0, p.r * 2.0, pen);
		break;
	}
	default:
		break;
	}
	}
	mainwindow->graphicsView->setScene(mainscene);
	mycore->CloseStream();
	return true;
}*/

void MainWindow::on_openAddingBTN_clicked()
{
    objectPropertiesWindow * ow = new objectPropertiesWindow(this);
	//ow->setFocusPolicy(Qt::StrongFocus);
	ow->show();
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
			mycore->AddRule(CONSTR_3PRATIO, ui->ruleValueEdit->text().toDouble());
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
