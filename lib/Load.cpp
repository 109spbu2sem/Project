#include "Load.h"
#include "global.h"

Load::Load(){
	_action->Calculate();
};

Load::Load(CORE*core, QString way){
	_action = core;
	_way = way;
	_flag = 1;
};

bool Load::isCorrect() {
	return _flag;
}

void Load::testPoints() {
	_file = new QFile(_way);
	if (!_file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		_flag = 0;
	}
	_xml.setDevice(_file);
	while (!_xml.atEnd()) {
		while (_xml.name() != "point" && !_xml.atEnd())
			_xml.readNext();
		if (_xml.name() == "point") {
			_xml.readNext(); _xml.readNext(); _xml.readNext();
			_vector.push_back(_xml.text().toInt());
			while (_xml.name() != "point" && !_xml.atEnd())
				_xml.readNext();
			_xml.readNext();
		}
		if (_xml.atEnd())
			return;
	}
}

void Load::testBegin() {
	_file = new QFile(_way);
	if (!_file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		_flag = 0;
	}
	_xml.setDevice(_file);
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		testPoint();
	if (_xml.name() == "segment")
		testSegment();
	if (_xml.name() == "circle")
		testCircle();
	if (_xml.name() == "constraint")
		testConstraint();
	if (_xml.atEnd())
		return;
}
void Load::testPoint() {
	_xml.readNext(); _xml.readNext();
	if (_xml.name() == "id") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "x") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "isconstx") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "y") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "isconsty") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "color") _xml.readNext();
	else { _flag = 0; return; }
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		testPoint();
	if (_xml.name() == "segment")
		testSegment();
	if (_xml.name() == "circle")
		testCircle();
	if (_xml.name() == "constraint")
		testConstraint();
	if (_xml.atEnd())
		return;
}

void Load::testSegment() {
	_xml.readNext(); _xml.readNext();
	if (_xml.name() == "id") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	_vector.push_back(_xml.text().toInt());
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "id1") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	for (unsigned i = 0; i < _vector.size(); ++i) {
		if (_vector[i] == _xml.text().toInt())
			break;
		if (i == _vector.size() - 1)
			_flag = 0;
	}
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "id2") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	for (unsigned i = 0; i < _vector.size(); ++i) {
		if (_vector[i] == _xml.text().toInt())
			break;
		if (i == _vector.size() - 1)
			_flag = 0;
	}
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "color") _xml.readNext();
	else { _flag = 0; return; }
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		testPoint();
	if (_xml.name() == "segment")
		testSegment();
	if (_xml.name() == "circle")
		testCircle();
	if (_xml.name() == "constraint")
		testConstraint();
	if (_xml.atEnd())
		return;
}

void Load::testCircle() {
	_xml.readNext(); _xml.readNext();
	if (_xml.name() == "id") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	_vector.push_back(_xml.text().toInt());
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "id1") _xml.readNext();
	else { _flag = 0; return; }
	if (_xml.text().toInt() == 0) { _flag = 0; return; }
	for (unsigned i = 0; i < _vector.size(); ++i) {
		if (_vector[i] == _xml.text().toInt())
			break;
		if (i == _vector.size() - 1)
			_flag = 0;
	}
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "radius") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "isconstr") _xml.readNext();
	else { _flag = 0; return; }
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (_xml.name() == "color") _xml.readNext();
	else { _flag = 0; return; }
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		testPoint();
	if (_xml.name() == "segment")
		testSegment();
	if (_xml.name() == "circle")
		testCircle();
	if (_xml.name() == "constraint")
		testConstraint();
	if (_xml.atEnd())
		return;
}

void Load::testConstraint() {
	_xml.readNext(); _xml.readNext();
	if (_xml.name() == "type") _xml.readNext();
	else { _flag = 0; return; }
	CONSTR_TYPE type = static_cast<CONSTR_TYPE>(_xml.text().toUInt());
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (type == CONSTR_EXCONTACT || type == CONSTR_INCONTACT ||
		type == CONSTR_ORTHOGONALITY || type == CONSTR_PARALLELISM) {
		if (_xml.name() == "id1") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		if (_xml.name() == "id2") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
	}
	if (type == CONSTR_P2PDIST ||
		type == CONSTR_P2LINEDIST || type == CONSTR_L2LANGLE) {
		if (_xml.name() == "id1") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		if (_xml.name() == "id2") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		if (_xml.name() == "value") _xml.readNext();
		else { _flag = 0; return; }
	}
	if (type == CONSTR_3PONLINE) {
		if (_xml.name() == "id1") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		if (_xml.name() == "id2") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		if (_xml.name() == "id3") _xml.readNext();
		else { _flag = 0; return; }
		if (_xml.text().toInt() == 0) { _flag = 0; return; }
		for (unsigned i = 0; i < _vector.size(); ++i) {
			if (_vector[i] == _xml.text().toInt())
				break;
			if (i == _vector.size() - 1)
				_flag = 0;
		}
	}
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	_xml.readNext();
	while (_xml.name() != "point" && _xml.name() != "segment" && _xml.name() != "circle" && _xml.name() != "constraint" && !_xml.atEnd())
		_xml.readNext();
	if (_xml.name() == "point")
		testPoint();
	if (_xml.name() == "segment")
		testSegment();
	if (_xml.name() == "circle")
		testCircle();
	if (_xml.name() == "constraint")
		testConstraint();
	if (_xml.atEnd())
		return;
}

void Load::begin() {
	_action->DeleteAll();
	_file = new QFile(_way);
	if (!_file->open(QIODevice::ReadOnly | QIODevice::Text))
	{
		_flag = 0;
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
	bool isconstx;
	bool isconsty;
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	id = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	x = _xml.text().toDouble();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	isconstx = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	y = _xml.text().toDouble();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	isconsty = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	_action->AddObject(x, isconstx, y, isconsty, c1, id, 0);
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
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	id = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	id1 = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	id2 = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
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
	bool isconstr;
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	id = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	id1 = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	r = _xml.text().toDouble();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	isconstr = _xml.text().toInt();
	_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
	c = _xml.text().toDouble();
	Color c1(c);
	_action->AddObject(id1, r, isconstr, c1, id, 0);
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
	unsigned id1;
	unsigned id2;
	unsigned id3;
	double value;
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	CONSTR_TYPE type = static_cast<CONSTR_TYPE>(_xml.text().toUInt());
	_xml.readNext(); _xml.readNext(); _xml.readNext();
	if (type == CONSTR_EXCONTACT || type == CONSTR_INCONTACT ||
		type == CONSTR_ORTHOGONALITY || type == CONSTR_PARALLELISM) {
		_xml.readNext();
		id1 = _xml.text().toInt();
		_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
		id2 = _xml.text().toInt();
		_action->AddRule(type, id1, id2);
	}
	if (type == CONSTR_P2PDIST ||
		type == CONSTR_P2LINEDIST || type == CONSTR_L2LANGLE) {
		_xml.readNext();
		id1 = _xml.text().toInt();
		_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
		id2 = _xml.text().toInt();
		_xml.readNext(); _xml.readNext(); _xml.readNext(); _xml.readNext();
		value = _xml.text().toDouble();
		_action->AddRule(type, id1, id2, value);
	}
	if (type == CONSTR_3PONLINE) {
		_xml.readNext();
		id1 = _xml.text().toInt();
		_xml.readNext(); _xml.readNext(); _xml.readNext();
		_xml.readNext();
		id2 = _xml.text().toInt();
		_xml.readNext(); _xml.readNext(); _xml.readNext();
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