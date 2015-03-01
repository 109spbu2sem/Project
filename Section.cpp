#include "section.h"
#include <stdexcept>

DynArray::DynArray()
{
	_sections = 0;
	_size = 0;
}
void DynArray::add(section s) {
	if (_size == 0) {
		_sections = new section;
		*_sections = s;
		++_size;
	}
	else {
		section*newSection = new section[_size + 1];
		for (unsigned i = 0; i < _size; ++i)
			newSection[i] = _sections[i];
		newSection[_size] = s;
		delete[]_sections;
		_sections = newSection;
		++_size;
	}
}
void DynArray::del(int num) {
	if (num == _size) {
		section*newSection = new section[_size - 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newSection[i] = _sections[i];
		delete[] _sections;
		_sections = newSection;
		--_size;
	}
	else {
		section*newSection = new section[_size - 1];
		for (unsigned i = num; i < _size - 1; ++i)
			_sections[i] = _sections[i + 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newSection[i] = _sections[i];
		delete[] _sections;
		_sections = newSection;
		--_size;
	}
}
section DynArray::get(int num) {
	if (num >= _size)
		throw std::invalid_argument("Nope");
	return _sections[num];
}
int DynArray::size() {
	return _size;
}
