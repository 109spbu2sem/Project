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

void Save::save(){
	if (_action->StreamIsOpened()) throw std::logic_error("Stream is opened");
	_action->OpenStream();
	_save.open(_way, ios_base::out | ios_base::trunc);
	_save << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
	while (_action->StreamIsOpened()) {
		_ans = _action->GetFromStream();
		if (!_action->StreamIsOpened())
			break;
		_save << "<primitive>\n";
		_save << "	<id>" << _ans.id << "</id>\n";
		_save << "	<type>" << _ans.type << "</type>\n";
		_save << "	<x1>" << _ans.p1_x << "</x1>\n";
		_save << "	<y1>" << _ans.p1_y << "</y1>\n";
		_save << "	<x2>" << _ans.p2_x << "</x2>\n";
		_save << "	<y2>" << _ans.p2_y << "</y2>\n";
		_save << "	<radius>" << _ans.r << "</radius>\n";
		Color color = _ans.color;
		_save << "	<color>" << color.getColor() << "</color>\n";
		_save << "</primitive>\n";
	}

	_save.close();
	_action->CloseStream();
}