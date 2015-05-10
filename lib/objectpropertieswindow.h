#ifndef OBJECTPROPERTIESWINDOW_H
#define OBJECTPROPERTIESWINDOW_H

#include <QDialog>
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

	void setupPointProperties(unsigned id, double x, double y, QColor& c);
	void setupSegmentProperties(unsigned id, double x, double y, double x2, double y2, QColor& c);
	void setupCircleProperties(unsigned id, double x, double y, double r, QColor& c);
	
private slots:
	void on_buttonBox_rejected();

	void on_buttonBox_accepted();

	void on_typesOfObjects_currentIndexChanged(int index);

private:
	Ui::objectPropertiesWindow *ui;
	CORE* mycore;
	QRegExpValidator *doubvalid;
	QRegExpValidator *unsvalid;
};

#endif // OBJECTPROPERTIESWINDOW_H
