#ifndef OBJECTPROPERTIESWINDOW_H
#define OBJECTPROPERTIESWINDOW_H

#include <QDialog>

namespace Ui {
class objectPropertiesWindow;
}

class objectPropertiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit objectPropertiesWindow(QWidget *parent = 0);
	~objectPropertiesWindow();
	
private slots:
	void on_objectTypeBox_currentIndexChanged(int index);

	void on_buttonBox_accepted();

private:
	Ui::objectPropertiesWindow *ui;
};

#endif // OBJECTPROPERTIESWINDOW_H
