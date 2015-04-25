#include "Load.h"
#include "global.h"

Load::Load(){
	*_way = "test.txt";
	*_cur = 60;
};
string Load::fileWay(string way) {
	*_way = way;
	return *_way;
}
CORE::Primitive Load::load() {
	char c;
	CORE::Primitive ans;
	_load.open(*_way);
	if (*_cur == 60) {
		_load.seekg(*_cur);
		_load >> ans.id;
		_load.get(c);
		*_cur = _load.tellg();
	}
	else {
		_load.seekg((*_cur) + 41);
		_load >> ans.id;
		_load.get(c);
		*_cur = _load.tellg();
	}
	_load.seekg((*_cur) + 13);
	_load >> ans.type;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 13);
	_load >> ans.p1_x;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 11);
	_load >> ans.p1_y;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 11);
	_load >> ans.p2_x;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 11);
	_load >> ans.p2_y;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 15);
	_load >> ans.r;
	_load.get(c);
	*_cur = _load.tellg();
	_load.seekg((*_cur) + 18);
	_load >> ans.color;
	_load.get(c);
	*_cur = _load.tellg();
	_load.close();
	return ans;
}