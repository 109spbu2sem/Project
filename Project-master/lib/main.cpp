#include "core.h"
#include "gui.h"
//#include "storages\storage_array.h"
//#include "storages\storage_list.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CORE testcore;
	GUI testgui;
	testgui.ConnectCORE(&testcore);
	testcore.Connect(&testgui, 0);
	testgui.show();
	return app.exec();
}
