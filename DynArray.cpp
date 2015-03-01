#include "Structures.h"
#include <stdexcept>

DynArrayPoint::DynArrayPoint(void)
{
	_Points = 0;
	_Size = 0;
}

void DynArrayPoint::Store(Point P)
{
	if (_Points == 0)
	{
		_Points = new Point;
		(*_Points).X = P.X;
		(*_Points).Y = P.Y;
		_Size++;
		//  _Points ->
	}
	else
	{
		Point *NewPoints = new Point[_Size + 1];

		//  Копируем старые элементы в новый массив
		for (unsigned s = 0; s < _Size; ++s)
		{
			NewPoints[s] = _Points[s];
		}

		//  Добавляем новый
		//  NewPoints[_Size] = P; - Равносильно
		NewPoints[_Size].X = P.X;
		NewPoints[_Size].Y = P.Y;

		//  Освобождаем занимаемую старыми элементами память
		delete[] _Points;

		//  Копируем обратно
		_Points = NewPoints;
		_Size++;
	}
}

Point DynArrayPoint::Get(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	return _Points[num];
}

Point *DynArrayPoint::Value(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	return _Points + num;

}
void DynArrayPoint::Set(int num, Point P)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	_Points[num] = P;
}
void DynArrayPoint::Drop(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");

	Point *NewPoints = new Point[_Size -1];

	//  Копируем старые элементы в новый массив
	for (unsigned s = 0; s < num; ++s)
	{
		NewPoints[s] = _Points[s];
	}
	for (unsigned s = num + 1; s < _Size; ++s)
	{
		NewPoints[s - 1] = _Points[s];
	}

	//  Освобождаем занимаемую старыми элементами память
	delete[] _Points;

	//  Копируем обратно
	_Points = NewPoints;
	--_Size;
}





DynArraySect::DynArraySect(void)
{
	_Sections = 0;
	_Size = 0;
}

void DynArraySect::Store(Sect S)
{
	if (_Sections == 0)
	{
		_Sections = new Sect;
		(*_Sections).A.X = S.A.X;
		(*_Sections).A.Y = S.A.Y;
		(*_Sections).B.X = S.B.X;
		(*_Sections).B.Y = S.B.Y;
		_Size++;
		//  _Points ->
	}
	else
	{
		Sect *NewSections = new Sect[_Size + 1];

		//  Копируем старые элементы в новый массив
		for (unsigned s = 0; s < _Size; ++s)
		{
			NewSections[s] = _Sections[s];
		}

		//  Добавляем новый
		NewSections[_Size] = S;

		//  Освобождаем занимаемую старыми элементами память
		delete[] _Sections;

		//  Копируем обратно
		_Sections = NewSections;
		_Size++;
	}
}

Sect DynArraySect::Get(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	return _Sections[num];
}

Sect *DynArraySect::Value(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	return _Sections + num;
}
void DynArraySect::Set(int num, Sect S)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");
	_Sections[num] = S;
}
void DynArraySect::Drop(int num)
{
	if (num >= _Size | num < 0) throw std::invalid_argument("Bad array index");


	Sect *NewSections = new Sect[_Size -1];

	//  Копируем старые элементы в новый массив
	for (unsigned s = 0; s < num; ++s)
	{
		NewSections[s] = _Sections[s];
	}
	for (unsigned s = num + 1; s < _Size; ++s)
	{
		NewSections[s - 1] = _Sections[s];
	}
	

	//  Освобождаем занимаемую старыми элементами память
	delete[] _Sections;

	//  Копируем обратно
	_Sections = NewSections;
	--_Size;
}