#include "Point.h"
#include <stdexcept>


DynArray::DynArray()
{
	_points = 0;
	_size = 0;
}
void DynArray::store(Point p) {
	if (_size == 0) {
		_points = new Point;
		*_points = p;
		++_size;
	}
	else {
		Point*newPoints = new Point[_size + 1];
		for (unsigned i = 0; i < _size; ++i)
			newPoints[i] = _points[i];
		newPoints[_size] = p;
		delete[] _points;
		_points = newPoints;
		++_size;
	}
}
void DynArray::del(int num) {
	if (num == _size) {
		Point*newPoint = new Point[_size - 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newPoint[i] = _points[i];
		delete[] _points;
		_points = newPoint;
		--_size;
	}
	else {
		Point*newPoint = new Point[_size - 1];
		for (unsigned i = num; i < _size - 1; ++i)
			_points[i] = _points[i + 1];
		for (unsigned i = 0; i < _size - 1; ++i)
			newPoint[i] = _points[i];
		delete[] _points;
		_points = newPoint;
		--_size;
	}
}
Point DynArray::get(int num) {
	if (num >= _size) 
		throw std::invalid_argument("Nope");
	return _points[num];
}
Point DynArray::back() {
	return (*_points);
}
int DynArray::size() {
	return _size;
}
void DynArray::del(int num) {

}



