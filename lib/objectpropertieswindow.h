#ifndef OBJECTPROPERTIESWINDOW_H
#define OBJECTPROPERTIESWINDOW_H

#include <QDialog>
#include "global.h"
#include <QColor>

namespace Ui {
class objectPropertiesWindow;
}

class objectPropertiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit objectPropertiesWindow(QWidget *parent = 0);
	~objectPropertiesWindow();

	void setupPointProperties(unsigned id, double x, double y, QColor& c);
	void setupSegmentProperties(unsigned id, double x, double y, double x2, double y2, QColor& c);
	void setupCircleProperties(unsigned id, double x, double y, double r, QColor& c);
	
private slots:
	void on_buttonBox_rejected();

	void on_buttonBox_accepted();

private:
	Ui::objectPropertiesWindow *ui;
};

#endif // OBJECTPROPERTIESWINDOW_H
