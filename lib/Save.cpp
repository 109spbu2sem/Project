#include "Save.h"
#include "global.h"
#include "gui.h"

using namespace std;

Save::Save(){
	_way = "test.xml";
};

Save::~Save(){
};

void Save::ConnectCORE(CORE*core){
	_action = core;
}

string Save::fileWay(QString way) {
	_way = way.toStdString();
	return _way;
}

void Save::begin() {
	_save.open(_way, ios_base::out | ios_base::trunc);
	_save << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	_save << "<list>\n";
}

bool Save::DrawPoint(unsigned id, double x, double y, Color c)
{
	_save << "	<point>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x>" << x << "</x>\n";
	_save << "		<y>" << y << "</y>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</point>\n";
	return true;
}

bool Save::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c)
{
	_save << "	<segment>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x1>" << x1 << "</x1>\n";
	_save << "		<y1>" << y1 << "</y1>\n";
	_save << "		<x2>" << x2 << "</x2>\n";
	_save << "		<y2>" << y2 << "</y2>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</segment>\n";
	return true;
}

bool Save::DrawCircle(unsigned id, double x, double y, double r, Color c)
{
	_save << "	<circle>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x>" << x << "</x>\n";
	_save << "		<y>" << y << "</y>\n";
	_save << "		<radius>" << r << "</radius>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</circle>\n";
	return true;
}

void Save::end() {
	_save << "</list>\n";
	_save.close();
}

bool Save::Clear() {
	return true;
}
