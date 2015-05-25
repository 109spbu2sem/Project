#include "gui.h"
#include "global.h"
#include "ui_gui.h"
#include "objectpropertieswindow.h"
#include "QtWidgets/qgraphicssceneevent.h"
#include "mycanvas.h"
#include "QtWidgets/qmessagebox.h"
#include <QString>
#include "QtWidgets/qfiledialog.h"
#include "QtWidgets/qlistview.h"
#include "qlist.h"
#include <QList>
#include "QtWidgets/qscrollbar.h"
#include "QtWidgets/qmainwindow.h"
#include "qresource.h"

GUI::GUI(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GUI)
{
	ui->setupUi(this);
	mycore = 0;
	selectedRuleId = 0;
	QRegExp doub("[0-9]{1,8}\\.[0-9]{0,8}");
	doubvalid = new QRegExpValidator(doub, this);
	ui->ruleValueEdit->setValidator(doubvalid);
	ui->radiusEdit->setValidator(doubvalid);
	mainscene = ui->myCanvas->getScene();
	ui->myCanvas->connectCORECanvas(mycore);
	toolsbuttons = new QButtonGroup;
	toolsbuttons->addButton(ui->selectBTNTool);
	toolsbuttons->addButton(ui->pointBTNTool);
	toolsbuttons->addButton(ui->ZoomBTNTool);
	workstatus = 0;


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
	delete doubvalid;
}

const char* GUI::ConstrTypeToString(CONSTR_TYPE type)
{
	switch (type)
	{
		case CONSTR_COLLECTOR:
			return "Constraint collector";
		case CONSTR_P2PDIST:
			return "Distance from point to point";
		case CONSTR_P2SECTDIST:
			return "Distance from point to segment";
		case CONSTR_P2LINEDIST:
			return "Distance from point to line";
		case CONSTR_3PONLINE:
			return "Three points on line";
		case CONSTR_L2LANGLE:
			return "Angle between segments";
		case CONSTR_3PRATIO:
			return "Ratio between three points";
		case CONSTR_EXCONTACT:
			return "External circle contact";
		case CONSTR_INCONTACT:
			return "Internal circle contact";
		case CONSTR_SPRATIO:
			return "Ratio between point and segment";
		case CONSTR_PARALLELISM:
			return "Parallel lines";
		case CONSTR_ORTHOGONALITY:
			return "Orthogonal lines";
		case CONSTR_PONC:
			return "Point on circle";
		default:
			return "Not a Constraint";
	}
}

void GUI::on_openAddingBTN_clicked()
{
    objectPropertiesWindow ow(this);
	 ow.connectCORE(mycore);
	 WriteText("Add object", "");
	 ow.exec();
	 WriteText("Done", "");
}

void GUI::on_ruleBox_currentIndexChanged(int index)
{
	switch (index)
	{
		case 5:
		case 6:
		case 9:
		case 10:
		case 11:
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
				WriteText("Need value", "");
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
				WriteText("Need value", "");
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
				WriteText("Need value", "");
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
				WriteText("Need value", "");
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
				WriteText("Need value", "");
			break;
		}
		case 8:
		{
			if (!ui->ruleValueEdit->text().isEmpty())
			{
				mycore->AddRule(CONSTR_SPRATIO, ui->ruleValueEdit->text().toDouble());
				mycore->Calculate();
			}
			else
				WriteText("Need value", "");
			break;
		}
		case 9:
		{
			mycore->AddRule(CONSTR_PARALLELISM);
			mycore->Calculate();
			break;
		}
		case 10:
		{
			mycore->AddRule(CONSTR_ORTHOGONALITY);
			mycore->Calculate();
			break;
		}
		case 11:
		{
			mycore->AddRule(CONSTR_PONC);
			mycore->Calculate();
			break;
		}
	}
	ui->ruleValueEdit->clear();
}

void GUI::on_createSegmentBTN_clicked()
{
	mycore->CreateSegment();
}

void GUI::on_createCircleBTN_clicked()
{
	mycore->CreateCircle(ui->radiusEdit->text().toDouble(), ui->circleCheck->isChecked());
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
	if (flag == false) {
		QString filename = QFileDialog::getSaveFileName(
			this, tr("Open File"),
			"C://",
			"Text File (*.xml);; Xml File (*.txt)");
		if (filename == "")
			return;
		mycore->IWantSaveAs(filename);
		flag = true;
		return;
	}
	mycore->IWantSave();
}

void GUI::on_actionSave_As_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.xml);; Xml File (*.txt)");
	if (filename == "")
		return;
	flag = true;
	mycore->IWantSaveAs(filename);
}

void GUI::on_actionClear_all_triggered()
{
	mycore->DeleteAll();
	ui->myCanvas->horizontalScrollBar()->setSliderPosition(50);
	ui->myCanvas->verticalScrollBar()->setSliderPosition(50);
}

void GUI::on_saveBTN_clicked()
{
	on_actionSave_triggered();
}
void GUI::on_saveasBTN_clicked()
{
	on_actionSave_As_triggered();
}
void GUI::on_openBTN_clicked()
{
	on_actionLoad_triggered();
}
void GUI::on_closeBTN_clicked()
{
	on_actionClose_triggered();
}

void GUI::on_redrawBTN_clicked()
{
	on_actionRedraw_all_triggered();
}

void GUI::on_clearallBTN_clicked()
{
	on_actionClear_all_triggered();
}

void GUI::on_gridBTN_clicked()
{
	ui->myCanvas->setGrid(ui->gridBTN->isChecked());
	mycore->Calculate();
}

void GUI::on_actionLoad_triggered()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.xml);; Xml File (*.txt)");
	if (filename == "")
		return;
	mycore->IWantLoad(filename);
	mycore->Calculate();
}
void GUI::on_objectsList_clicked(const QModelIndex &index)
{
	mycore->Select(index.data(17).toUInt());
}

void GUI::on_rulesList_clicked(const QModelIndex &index)
{
	mycore->ClearSelection();
	mycore->Select(index.data(19).toUInt());
	mycore->Select(index.data(20).toUInt());
	mycore->Select(index.data(21).toUInt());
	ui->propertiesList->clear();
	selectedRuleId = index.data(22).toUInt();
	QString s;

	QListWidgetItem* item = new QListWidgetItem;
	item->setText(ConstrTypeToString(static_cast<CONSTR_TYPE>(index.data(17).toUInt())));
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(index.data(18).toDouble());
	item->setText("value:\t" + s);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(index.data(19).toUInt());
	item->setText("object's id:\t" + s);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(index.data(20).toUInt());
	item->setText("object's id:\t" + s);
	ui->propertiesList->addItem(item);

	item = new QListWidgetItem;
	s.setNum(index.data(21).toUInt());
	item->setText("object's id:\t" + s);
	ui->propertiesList->addItem(item);
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
			case PRIMITIVE_POINT:
			{
				ow.setupPointProperties(ui->propertiesList->item(1)->data(17).toUInt(),
												ui->propertiesList->item(2)->data(17).toDouble(),
												false,
												ui->propertiesList->item(3)->data(17).toDouble(),
												false,
												Color(ui->propertiesList->item(4)->data(17).toUInt()));
				break;
			}
			case PRIMITIVE_SEGMENT:
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
			case PRIMITIVE_CIRCLE:
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
	mycore->DeleteSelectedObjects();
}

void GUI::on_deleteRuleBTN_clicked()
{
	if (ui->propertiesList->count() != 0)
	{
		mycore->DeleteRule(selectedRuleId);
		ui->propertiesList->clear();
	}
}
