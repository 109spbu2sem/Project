#include "core.h"
#include "gui.h"
#include "QtWidgets\qapplication.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CORE maincore;
	GUI maingui;
	maingui.ConnectCORE(&maincore);
	maincore.Connect(&maingui);
	maingui.show();
	return app.exec();
}