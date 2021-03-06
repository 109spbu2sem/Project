#include "global.h"


Color::Color()
{
	_color = COLORDEF;
}

Color::Color(unsigned c)
{
	_color = c % 16777216;
}

Color::~Color()
{
}

void Color::setColor(unsigned long color)
{
	if (color >= 16777216) return;
	_color = color;
}

void Color::setColor(unsigned char R, unsigned char G, unsigned char B)
{
	_color = R * 65536 + G * 256 + B;
}

unsigned Color::getColor(char mode) const
{
	if (!mode) return _color;
	if (mode == 1) return (_color >> 16) & 0xFF;		// returns RED color
	if (mode == 2) return (_color >> 8) & 0xFF;		// returns GREEN color
	if (mode == 3) return _color & 0xFF;				// returns BLUE color
	return 0;
}

unsigned Color::red() const
{
	return (_color >> 16) & 0xFF;
}

unsigned Color::green() const
{
	return (_color >> 8) & 0xFF;
}

unsigned Color::blue() const
{
	return _color & 0xFF;
}

void Color::setColor(const Color& c)
{
	_color = c._color;
}