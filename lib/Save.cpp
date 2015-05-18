#include "Save.h"
#include "global.h"
#include "gui.h"

using namespace std;

Save::Save(){
};
Save::Save(QString way) {
	_way = way.toStdString();
	_save.open(_way.c_str(), ios_base::out | ios_base::trunc);
	_save << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	_save << "<list>\n";
}

Save::~Save(){
	_save << "</list>\n";
	_save.close();
}

bool Save::DrawPoint(unsigned id, double x, bool isconstx, double y, bool isconsty, Color c, bool mode)
{
	_save << "	<point>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<x>" << x << "</x>\n";
	_save << "		<isconstx>" << isconstx << "</isconstx>\n";
	_save << "		<y>" << y << "</y>\n";
	_save << "		<isconsty>" << isconsty << "</isconsty>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</point>\n";
	return true;
}

bool Save::DrawSegment(unsigned id, unsigned id1, unsigned id2, Color c, bool mode)
{
	_save << "	<segment>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<id2>" << id2 << "</id2>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</segment>\n";
	return true;
}

bool Save::DrawCircle(unsigned id, unsigned id1, double r, bool isconstr, Color c, bool mode)
{
	_save << "	<circle>\n";
	_save << "		<id>" << id << "</id>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<radius>" << r << "</radius>\n";
	_save << "		<isconstr>" << isconstr << "</isconstr>\n";
	_save << "		<color>" << c.getColor() << "</color>\n";
	_save << "	</circle>\n";
	return true;
}

bool Save::DrawRule(CONSTR_TYPE type, unsigned id1, unsigned id2) {
	_save << "	<constraint>\n";
	_save << "		<type>" << type << "</type>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<id2>" << id2 << "</id2>\n";
	_save << "	</constraint>\n";
	return true;
}

bool Save::DrawRule(CONSTR_TYPE type, unsigned id1, unsigned id2, double value) {
	_save << "	<constraint>\n";
	_save << "		<type>" << type << "</type>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<id2>" << id2 << "</id2>\n";
	_save << "		<value>" << value << "</value>\n";
	_save << "	</constraint>\n";
	return true;
}

bool Save::DrawRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3, double value) {
	_save << "	<constraint>\n";
	_save << "		<type>" << type << "</type>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<id2>" << id2 << "</id2>\n";
	_save << "		<id3>" << id3 << "</id3>\n";
	_save << "		<value>" << value << "</value>\n";
	_save << "	</constraint>\n";
	return true;
}

bool Save::DrawRule(CONSTR_TYPE type, unsigned id1, unsigned id2, unsigned id3) {
	_save << "	<constraint>\n";
	_save << "		<type>" << type << "</type>\n";
	_save << "		<id1>" << id1 << "</id1>\n";
	_save << "		<id2>" << id2 << "</id2>\n";
	_save << "		<id3>" << id3 << "</id3>\n";
	_save << "	</constraint>\n";
	return true;
}