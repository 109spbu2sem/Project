#include "Save.h"
#include "global.h"
#include "gui.h"

using namespace std;

Save::Save(){
	_way = "test.txt";
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
	_save << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
	_save << "<list>\n";
}

bool Save::DrawPoint(unsigned id, double x, double y, Color c) {
	_save << "	<primitive>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x1>" << x << "</x1>\n";
	_save << "		<y1>" << y << "</y1>\n";
	_save << "		<x2>" << 0 << "</x2>\n";
	_save << "		<y2>" << 0 << "</y2>\n";
	_save << "		<radius>" << 0 << "</radius>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</primitive>\n";
	return true;
}

bool Save::DrawSegment(unsigned id, double x1, double y1, double x2, double y2, Color c) {
	_save << "	<primitive>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x1>" << x1 << "</x1>\n";
	_save << "		<y1>" << y1 << "</y1>\n";
	_save << "		<x2>" << x2 << "</x2>\n";
	_save << "		<y2>" << y2 << "</y2>\n";
	_save << "		<radius>" << 0 << "</radius>\n";
	Color color = c;
	_save << "		<color>" << color.getColor() << "</color>\n";
	_save << "	</primitive>\n";
	return true;
}

bool Save::DrawCircle(unsigned id, double x, double y, double r, Color c) {
	_save << "	<primitive>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x1>" << x << "</x1>\n";
	_save << "		<y1>" << y << "</y1>\n";
	_save << "		<x2>" << 0 << "</x2>\n";
	_save << "		<y2>" << 0 << "</y2>\n";
	_save << "		<radius>" << r << "</radius>\n";
	Color color = c;
	_save << "		<color>" << color.getColor() << "</color>\n";
	_save << "	</primitive>\n";
	return true;
}

void Save::end() {
	_save << "</list>\n";
	_save.close();
}

bool Save::Clear() {
	return true;
}
