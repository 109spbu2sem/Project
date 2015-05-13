#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include "QtWidgets\qgraphicssceneevent.h"
#include "mycanvas.h"
#include "QtWidgets\qmessagebox.h"
#include <QString>
#include "QtWidgets\qfiledialog.h"
#include "QtWidgets\qlistview.h"
#include "qlist.h"
#include <QList>



GUI::GUI(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GUI)
{
	ui->setupUi(this);
	mycore = 0;
	mainscene = ui->myCanvas->getScene();
	ui->myCanvas->connectCORECanvas(mycore);
	ui->pointBTNTool->setIcon(QIcon("icons/pointbtn.png"));
	toolsbuttons = new QButtonGroup;
	toolsbuttons->addButton(ui->selectBTNTool);
	toolsbuttons->addButton(ui->pointBTNTool);
	toolsbuttons->addButton(ui->ZoomBTNTool);

	showMaximized();
}

void GUI::ConnectCORE(CORE* core)
{
	mycore = core;
	ui->myCanvas->connectCORECanvas(core);
}

GUI::~GUI()
{
	delete toolsbuttons;
	delete ui;
}

bool GUI::SetNameOfWindow(std::string header)
{
	setWindowTitle(QString(header.c_str()));
	return true;
}

void GUI::WriteError(const char* Text)
{
	ui->statusBar->setText("Error");
	QMessageBox b;
	b.setText(Text);
	b.exec();
	return;
}

void GUI::WriteStatus(const char* Text)
{
	ui->statusBar->setText(Text);
	return;
}

void GUI::WriteMessage(const char* Text)
{
	ui->messageBar->setText(Text);
	return;
}
// Write Short to status bar, Long to message bar
void GUI::WriteText(const char* Short, const char* Long)
{
	ui->statusBar->setText(Short);
	ui->messageBar->setText(Long);
}

bool GUI::Set_properties_of_point(unsigned id, double x, double y, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;
	
	item->setText("Point");
	item->setData(17, static_cast<unsigned>(POINT));
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
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

bool GUI::Set_properties_of_segment(unsigned id, double x1, double y1, double x2, double y2, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Segment");
	item->setData(17, static_cast<unsigned>(SEGMENT));
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
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

bool GUI::Set_properties_of_circle(unsigned id, double x, double y, double r, Color c)
{
	ui->propertiesList->clear();
	QString s;
	QListWidgetItem* item = new QListWidgetItem;

	item->setText("Circle");
	item->setData(17, static_cast<unsigned>(CIRCLE));
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
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

void GUI::Clear_properties()
{
	ui->propertiesList->clear();
}

bool GUI::DrawPoint(unsigned id, double x, double y, Color c, bool selected)
{
	mainscene->addEllipse(x - 1.2, -y - 1.2, 2.4, 2.4,
								 selected ? QPen(QColor(QRgb(COLORSELECTED))) :
								 QPen(QColor(c.red(), c.green(), c.blue())),
								 selected ? QBrush(QColor(QRgb(COLORSELECTED))) :
								 QBrush(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tPoint";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
		it->setSelected(true);
	return true;
}

bool GUI::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c, bool selected)
{
	mainscene->addLine(x1, -y1, x2, -y2,
							 selected ? QPen(QColor(QRgb(COLORSELECTED))) :
							 QPen(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tSegment";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
		it->setSelected(true);
	return true;
}

bool GUI::DrawCircle(unsigned id, double x, double y, double r, Color c, bool selected)
{
	mainscene->addEllipse(x - r, -y - r, r * 2, r * 2,
								 selected ? QPen(QColor(QRgb(COLORSELECTED))) : 
								 QPen(QColor(c.red(), c.green(), c.blue())));
	QString s;
	s.setNum(id);
	s += "\tCircle";
	QListWidgetItem* it = new QListWidgetItem;
	it->setText(s);
	it->setData(17, id);
	ui->objectsList->addItem(it);
	if (selected)
		it->setSelected(true);
	return true;
}

bool GUI::Clear()
{	
	mainscene->clear();
	mainscene->addLine(0, -5000, 0, 5000, QPen(Qt::DotLine));
	mainscene->addLine(-5000, 0, 5000, 0, QPen(Qt::DotLine));
	ui->objectsList->clear();
	return true;
}

void GUI::on_openAddingBTN_clicked()
{
    objectPropertiesWindow ow(this);
	 ow.connectCORE(mycore);
	 WriteStatus("Add object");
	 ow.exec();
	 WriteStatus("Done");
}

void GUI::on_ruleBox_currentIndexChanged(int index)
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

void GUI::on_pushButton_clicked()
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

void GUI::on_concatinateBTN_clicked()
{
	mycore->ConcatenatePoints();
}

void GUI::on_selectBTNTool_clicked()
{
    ui->myCanvas->setTool(TOOL_Select);
}

void GUI::on_pointBTNTool_clicked()
{
    ui->myCanvas->setTool(TOOL_Point);
}

void GUI::on_ZoomBTNTool_clicked()
{
    ui->myCanvas->setTool(TOOL_Zoom);
}

void GUI::on_actionClose_triggered()
{
	// need add dialog if had changes
	close();
}

void GUI::on_actionRedraw_all_triggered()
{
	mycore->Calculate();
}

void GUI::on_actionSave_triggered()
{
	// need add save as if 1st time
	mycore->IWantSave();
}

void GUI::on_actionSave_As_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	mycore->IWantSaveAs(filename);
}

void GUI::on_actionClear_all_triggered()
{
	mycore->DeleteAll();
}

void GUI::on_actionLoad_triggered()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	mycore->DeleteAll();
	mycore->IWantLoad(filename);
}
void GUI::on_objectsList_clicked(const QModelIndex &index)
{
	mycore->Select(index.data(17).toUInt());
}

void GUI::on_openChangingDialog_clicked()
{
	if (ui->propertiesList->count())
	{
		WriteText("Change object", "");
		objectPropertiesWindow ow(this);
		ow.connectCORE(mycore);
		ow.setFlag(1);
		unsigned SWITCH = ui->propertiesList->item(0)->data(17).toUInt();
		switch (SWITCH)
		{
			case 0:
			{
				ow.setupPointProperties(ui->propertiesList->item(1)->data(17).toUInt(),
												ui->propertiesList->item(2)->data(17).toDouble(),
												false,
												ui->propertiesList->item(3)->data(17).toDouble(),
												false,
												Color(ui->propertiesList->item(4)->data(17).toUInt()));
				break;
			}
			case 1:
			{
				ow.setupSegmentProperties(ui->propertiesList->item(1)->data(17).toUInt(),
												  ui->propertiesList->item(2)->data(17).toDouble(),
												  false,
												  ui->propertiesList->item(3)->data(17).toDouble(),
												  false,
												  ui->propertiesList->item(4)->data(17).toDouble(),
												  false,
												  ui->propertiesList->item(5)->data(17).toDouble(),
												  false,
												  Color(ui->propertiesList->item(6)->data(17).toUInt()));
				break;
			}
			case 2:
			{
				ow.setupCircleProperties(ui->propertiesList->item(1)->data(17).toUInt(),
												 ui->propertiesList->item(2)->data(17).toDouble(),
												 false,
												 ui->propertiesList->item(3)->data(17).toDouble(),
												 false,
												 ui->propertiesList->item(4)->data(17).toDouble(),
												 false,
												 Color(ui->propertiesList->item(5)->data(17).toUInt()));
				break;
			}
		}
		ow.exec();
		WriteText("Done", "");
	}
	else
		WriteText("Tip:", "Select any object.");
}

void GUI::on_deleteObjBTN_clicked()
{
	mycore->DeleteSelected();
}
