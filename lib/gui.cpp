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

char* GUI::ConstrTypeToString(CONSTR_TYPE type)
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
		default:
			return "Not a Constraint";
	}
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
		case 8:
		{
			if (!ui->ruleValueEdit->text().isEmpty())
			{
				mycore->AddRule(CONSTR_SPRATIO, ui->ruleValueEdit->text().toDouble());
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
	if (flag == false) {
		QString filename = QFileDialog::getSaveFileName(
			this, tr("Open File"),
			"C://",
			"Text File (*.txt);; Xml File (*.xml)");
		mycore->IWantSaveAs(filename);
		flag = true;
	}
	mycore->IWantSave();
}

void GUI::on_actionSave_As_triggered()
{
	QString filename = QFileDialog::getSaveFileName(
		this, tr("Open File"),
		"C://",
		"Text File (*.txt);; Xml File (*.xml)");
	flag = true;
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
	if (filename == "")
		return;
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
