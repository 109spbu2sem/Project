#ifndef OBJECTPROPERTIESWINDOW_H
#define OBJECTPROPERTIESWINDOW_H

#include "QtWidgets\qdialog.h"
#include "global.h"
#include <QColor>
#include "core.h"
#include <QRegExp>
#include <QValidator>

namespace Ui {
class objectPropertiesWindow;
}

class objectPropertiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit objectPropertiesWindow(QWidget *parent = 0);
	~objectPropertiesWindow();

	void connectCORE(CORE*);

	void setupPointProperties(unsigned id, double x, bool ischeckedx, double y, bool ischeckedy, Color c);
	void setupSegmentProperties(unsigned id, double x1, bool ischeckedx1, double y1, bool ischeckedy1,
										 double x2, bool ischeckedx2, double y2, bool ischeckedy2, Color c);
	void setupCircleProperties(unsigned id, double x, bool ischeckedx, double y, bool ischeckedy, double r, bool ischecked, Color c);

	void setFlag(unsigned);
	
private slots:
	void on_buttonBox_rejected();

	void on_buttonBox_accepted();

	void on_typesOfObjects_currentIndexChanged(int index);

private:
	Ui::objectPropertiesWindow *ui;
	CORE* mycore;
	QRegExpValidator *doubvalid;
	QRegExpValidator *unsvalid;
	unsigned flag;
};

#endif // OBJECTPROPERTIESWINDOW_H
