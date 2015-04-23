#include "LineSkin.h"


LineSkin::LineSkin()
{
	_type = 1;
	_width = 1;
	_color.setColor(0);
}


LineSkin::~LineSkin()
{
}


void LineSkin::setColor(unsigned color)
{
	_color.setColor(color);
}

void LineSkin::setWidth(float width)
{
	if (width > 0)
	{
		_width = width;
	}
	else
		if (!width) _type = 0;
}

void LineSkin::setType(unsigned char type)
{
	if (type >= 0 && type <= 2)
	{
		_type = type;
	}
	else
		_type = 1;
}