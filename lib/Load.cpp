#include "Load.h"
#include "global.h"

Load::Load(){
	_action->Calculate();
};

Load::Load(CORE*core, QString way){
	_action = core;
	_way = way;
	_action->DeleteAll();
};

void Load::begin() {
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
	_action->AddObject(x, 0, y, 0, c1, id, 0);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
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
	unsigned id1;
	unsigned id2;
	double c;
	while (_xml.name() != "id") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	id = _xml.text().toInt();
	while (_xml.name() != "id1")
		_xml.readNext();
	_xml.readNext();
	id1 = _xml.text().toInt();
	while (_xml.name() != "id2")
		_xml.readNext();
	_xml.readNext();
	id2 = _xml.text().toInt();
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	_action->AddObject(id1, id2, c1, id, 0);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
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
	unsigned id1;
	double r;
	double c;
	while (_xml.name() != "id") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	id = _xml.text().toInt();
	while (_xml.name() != "id1")
		_xml.readNext();
	_xml.readNext();
	id1 = _xml.text().toInt();
	while (_xml.name() != "radius")
		_xml.readNext();
	_xml.readNext();
	r = _xml.text().toDouble();
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	_action->AddObject(id1, r, 0, c1, id, 0);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
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
