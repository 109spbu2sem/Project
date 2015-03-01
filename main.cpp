#include "mainwindow.h"
#include <QApplication>
#include "globals.h"
//#include "storages.h"

int Create(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	w.show();
	return a.exec();
}

int main(int argc, char *argv[])
{
	return Create(argc, argv);

}
