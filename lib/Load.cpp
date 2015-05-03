#include "Load.h"
#include "global.h"

Load::Load(){

};
void Load::fileWay(QString way) {
	_way = way;
}
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
	double id;
	double x;
	double y;
	double c;
	while (_xml.name() != "id")
		_xml.readNext();
	_xml.readNext();
	id = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "x")
		_xml.readNext();
	_xml.readNext();
	x = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "y")
		_xml.readNext();
	_xml.readNext();
	y = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = atof(_xml.text().toString().toStdString().c_str());
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
	double id;
	double x1;
	double y1;
	double x2;
	double y2;
	double c;
	while (_xml.name() != "id")
		_xml.readNext();
	_xml.readNext();
	id = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "x1")
		_xml.readNext();
	_xml.readNext();
	x1 = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "y1")
		_xml.readNext();
	_xml.readNext();
	y1 = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "x2")
		_xml.readNext();
	_xml.readNext();
	x2 = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "y2")
		_xml.readNext();
	_xml.readNext();
	y2 = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = atof(_xml.text().toString().toStdString().c_str());
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
	double id;
	double x;
	double y;
	double r;
	double c;
	while (_xml.name() != "id")
		_xml.readNext();
	_xml.readNext();
	id = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "x")
		_xml.readNext();
	_xml.readNext();
	x = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "y")
		_xml.readNext();
	_xml.readNext();
	y = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "radius")
		_xml.readNext();
	_xml.readNext();
	r = atof(_xml.text().toString().toStdString().c_str());
	while (_xml.name() != "color")
		_xml.readNext();
	_xml.readNext();
	c = atof(_xml.text().toString().toStdString().c_str());
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
