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
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.name() == "constraint")
		constraint();
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
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.name() == "constraint")
		constraint();
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
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.name() == "constraint")
		constraint();
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
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.name() == "constraint")
		constraint();
	if (_xml.atEnd())
		return;
}

void Load::constraint() {
	CONSTR_TYPE type;
	unsigned helpType;
	unsigned id1;
	unsigned id2;
	unsigned id3;
	double value;
	while (_xml.name() != "type") {
		_xml.readNext();
		if (_xml.atEnd())
			return;
	}
	_xml.readNext();
	helpType = _xml.text().toInt();
	switch (helpType) {
	case 1:
		type = CONSTR_P2PDIST;
		break;
	case 2:
		type = CONSTR_P2SECTDIST;
		break;
	case 3:
		type = CONSTR_P2LINEDIST;
		break;
	case 4:
		type = CONSTR_3PONLINE;
		break;
	case 5:
		type = CONSTR_L2LANGLE;
		break;
	case 6:
		type = CONSTR_3PRATIO;
		break;
	case 7:
		type = CONSTR_EXCONTACT;
		break;
	case 8:
		type = CONSTR_INCONTACT;
		break;
	case 9:
		type = CONSTR_SPRATIO;
		break;
	case 10:
		type = CONSTR_PARALLELISM;
		break;
	case 11:
		type = CONSTR_ORTHOGONALITY;
		break;
	}
	if (type == CONSTR_EXCONTACT || type == CONSTR_INCONTACT ||
		type == CONSTR_ORTHOGONALITY || type == CONSTR_PARALLELISM) {
		while (_xml.name() != "id1")
			_xml.readNext();
		_xml.readNext();
		id1 = _xml.text().toInt();
		while (_xml.name() != "id2")
			_xml.readNext();
		_xml.readNext();
		id2 = _xml.text().toInt();
		_action->AddRule(type, id1, id2);
	}
	if (type == CONSTR_P2PDIST || type == CONSTR_P2SECTDIST ||
		type == CONSTR_P2LINEDIST || type == CONSTR_L2LANGLE ||
		type == CONSTR_SPRATIO) {
		while (_xml.name() != "id1")
			_xml.readNext();
		_xml.readNext();
		id1 = _xml.text().toInt();
		while (_xml.name() != "id2")
			_xml.readNext();
		_xml.readNext();
		id2 = _xml.text().toInt();
		while (_xml.name() != "value")
			_xml.readNext();
		_xml.readNext();
		value = _xml.text().toDouble();
		_action->AddRule(type, id1, id2, value);
	}
	if (type == CONSTR_3PRATIO) {
		while (_xml.name() != "id1")
			_xml.readNext();
		_xml.readNext();
		id1 = _xml.text().toInt();
		while (_xml.name() != "id2")
			_xml.readNext();
		_xml.readNext();
		id2 = _xml.text().toInt();
		while (_xml.name() != "id3")
			_xml.readNext();
		_xml.readNext();
		id3 = _xml.text().toInt();
		while (_xml.name() != "value")
			_xml.readNext();
		_xml.readNext();
		value = _xml.text().toDouble();
		_action->AddRule(type, id1, id2, id3, value);
	}
	if (type == CONSTR_3PONLINE) {
		while (_xml.name() != "id1")
			_xml.readNext();
		_xml.readNext();
		id1 = _xml.text().toInt();
		while (_xml.name() != "id2")
			_xml.readNext();
		_xml.readNext();
		id2 = _xml.text().toInt();
		while (_xml.name() != "id3")
			_xml.readNext();
		_xml.readNext();
		id3 = _xml.text().toInt();
		_action->AddRule(type, id1, id2, id3);
	}
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		point();
	if (_xml.name() == "segment")
		segment();
	if (_xml.name() == "circle")
		circle();
	if (_xml.name() == "constraint")
		constraint();
	if (_xml.atEnd())
		return;
}
