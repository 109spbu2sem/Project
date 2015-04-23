#ifndef LINE_H
#define LINE_H
#include "Color.h"

class LineSkin
{
private:
	Color _color;
	float _width;
	unsigned char _type; // 0 - invisible, 1 - default, 2 - dotted line. May add other types.
public:
	LineSkin();
	~LineSkin();
	void setColor(unsigned);
	void setWidth(float);
	void setType(unsigned char);
};

#endif // LINE_H