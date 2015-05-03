#include "core.h"
#include "gui.h"
#include "Save.h"
#include "Load.h"
//#include "storages\storage_array.h"
//#include "storages\storage_list.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CORE testcore;
	GUI testgui;
	Save testsave;
	Load testload;
	testsave.ConnectCORE(&testcore);
	testgui.ConnectCORE(&testcore);
	testcore.Connect(&testgui, &testsave, &testload);
	testgui.show();
	return app.exec();
}
