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
#include <QListView>
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mycore = 0;
	mainscene = ui->graphicsView->getScene();
	ui->graphicsView->connectCORECanvas(mycore);
	ui->graphicsView->scale(2, 2);
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	toolsbuttons = new QButtonGroup;
	toolsbuttons->addButton(ui->selectBTNTool);
	toolsbuttons->addButton(ui->pointBTNTool);
	toolsbuttons->addButton(ui->ZoomBTNTool);

	showMaximized();
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
// Write Short to status bar, Long to message bar
void MainWindow::WriteText(const char* Short, const char* Long)
{
	ui->statusBar->setText(Short);
	ui->messageBar->setText(Long);
}

bool MainWindow::Set_properties_of_point(unsigned id, double x, double y, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;
	
	item->setText("Point");
	item->setData(17, 0);
	ui->propertiesList->addItem(item);

	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x);
	item->setText("x:\t" + s);
	item->setData(17, x);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y);
	item->setText("y:\t" + s);
	item->setData(17, y);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

bool MainWindow::Set_properties_of_segment(unsigned id, double x1, double y1, double x2, double y2, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Segment");
	item->setData(17, 1);
	ui->propertiesList->addItem(item);

	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x1);
	item->setText("x1:\t" + s);
	item->setData(17, x1);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y1);
	item->setText("y1:\t" + s);
	item->setData(17, y1);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x2);
	item->setText("x2:\t" + s);
	item->setData(17, x2);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y2);
	item->setText("y2:\t" + s);
	item->setData(17, y2);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

bool MainWindow::Set_properties_of_circle(unsigned id, double x, double y, double r, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Circle");
	item->setData(17, 2);
	ui->propertiesList->addItem(item);

	s.setNum(id);
	item->setText("id:\t" + s);
	item->setData(17, id);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(x);
	item->setText("x:\t" + s);
	item->setData(17, x);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(y);
	item->setText("y:\t" + s);
	item->setData(17, y);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(r);
	item->setText("r:\t" + s);
	item->setData(17, r);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(c.getColor());
	item->setText("color:\t" + s);
	item->setData(17, c.getColor());
	ui->propertiesList->addItem(item);
	return true;
}

void MainWindow::Clear_properties()
{
	ui->propertiesList->clear();
}

bool MainWindow::DrawPoint(unsigned id, double x, double y, Color c)
{
	/*ui->typesOfObjects->setCurrentIndex(0);
	QString s;
	ui->editID->setText(s.setNum(id));
	ui->editX1->setText(s.setNum(x));
	ui->editY1->setText(s.setNum(y));
	ui->editR->setText(s.setNum(c.getColor(1)));
	ui->editG->setText(s.setNum(c.getColor(2)));
	ui->editB->setText(s.setNum(c.getColor(3)));*/
	mainscene->addEllipse(x - 1.2, -y - 1.2, 2.4, 2.4,
								 QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))),
								 QBrush(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	QString s;
	s.setNum(id);
	s += "\tPoint";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (c.getColor() == COLORSELECTED)
		it->setSelected(true);
	return true;
}

bool MainWindow::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c)
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
	mainscene->addLine(x1, -y1, x2, -y2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	QString s;
	s.setNum(id);
	s += "\tSegment";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (c.getColor() == COLORSELECTED)
		it->setSelected(true);
	return true;
}

bool MainWindow::DrawCircle(unsigned id, double x, double y, double r, Color c)
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
	mainscene->addEllipse(x - r, -y - r, r * 2, r * 2, QPen(QColor(c.getColor(1), c.getColor(2), c.getColor(3))));
	QString s;
	s.setNum(id);
	s += "\tCircle";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (c.getColor() == COLORSELECTED)
		it->setSelected(true);
	return true;
}

bool MainWindow::Clear()
{	
	mainscene->clear();
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	ui->objectsList->clear();
	return true;
}

void MainWindow::on_openAddingBTN_clicked()
{
    objectPropertiesWindow ow(this);
	 ow.connectCORE(mycore);
	 WriteStatus("Add object");
	 ow.exec();
	 WriteStatus("Done");
}

void MainWindow::on_ruleBox_currentIndexChanged(int index)
{
	switch (index)
	{
		case 5:
		case 6:
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
		case 5:
		{
			mycore->AddRule(CONSTR_EXCONTACT);
			mycore->Calculate();
			break;
		}
		case 6:
		{
			mycore->AddRule(CONSTR_INCONTACT);
			mycore->Calculate();
			break;
		}
		case 7:
		{
			if (!ui->ruleValueEdit->text().isEmpty())
			{
				mycore->AddRule(CONSTR_P2SECTDIST, ui->ruleValueEdit->text().toDouble());
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
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	mycore->IWantLoad(filename);
}
void MainWindow::on_objectsList_clicked(const QModelIndex &index)
{
	mycore->Select(index.data(17).toUInt());
}
