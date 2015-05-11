#include "Load.h"
#include "global.h"

Load::Load(){

};
void Load::fileWay(QString way) {
	_way = way;
}
void Load::ConnectCORE(CORE*core){
	_action = core;
}
void Load::begin() {
	_action->DeleteAll();
	_file = new QFile(_way);
	if (!_file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
	}
	_xml.setDevice(_file);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.atEnd())
		return;
}
void Load::point() {
	unsigned id;
	double x;
	double y;
	double c;
	while (_xml.name() != "id") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	id = _xml.text().toInt();
	while (_xml.name() != "x")
		_xml.readNext();
	_xml.readNext();
	x = _xml.text().toDouble();
	while (_xml.name() != "y")
		_xml.readNext();
	_xml.readNext();
	y = _xml.text().toDouble();
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	_action->AddObject(x, y, c1, id, 0);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.atEnd())
		return;
}

void Load::segment() {
	unsigned id;
	double x1;
	double y1;
	double x2;
	double y2;
	double c;
	while (_xml.name() != "id") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	id = _xml.text().toInt();
	while (_xml.name() != "x1")
		_xml.readNext();
	_xml.readNext();
	x1 = _xml.text().toDouble();
	while (_xml.name() != "y1")
		_xml.readNext();
	_xml.readNext();
	y1 = _xml.text().toDouble();
	while (_xml.name() != "x2")
		_xml.readNext();
	_xml.readNext();
	x2 = _xml.text().toDouble();
	while (_xml.name() != "y2")
		_xml.readNext();
	_xml.readNext();
	y2 = _xml.text().toDouble();
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.atEnd())
		return;
}

void Load::circle() {
	unsigned id;
	double x;
	double y;
	double r;
	double c;
	while (_xml.name() != "id") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	id = _xml.text().toInt();
	while (_xml.name() != "x")
		_xml.readNext();
	_xml.readNext();
	x = _xml.text().toDouble();
	while (_xml.name() != "y")
		_xml.readNext();
	_xml.readNext();
	y = _xml.text().toDouble();
	while (_xml.name() != "radius")
		_xml.readNext();
	_xml.readNext();
	r = _xml.text().toDouble();
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.atEnd())
		return;
}
