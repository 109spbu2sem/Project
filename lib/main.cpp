#include "core.h"
#include "gui.h"
#include "QtWidgets\qapplication.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CORE testcore;
	GUI testgui;
	testgui.ConnectCORE(&testcore);
	testcore.Connect(&testgui);
	testgui.show();
	return app.exec();
}