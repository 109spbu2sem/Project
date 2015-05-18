#ifndef ENUMS_H
#define ENUMS_H

enum GTool
{
	TOOL_Select,
	TOOL_Point,
	TOOL_Zoom
};

enum PRIMITIVE_TYPE : unsigned
{
	PRIMITIVE_NOTHING = 0,
	PRIMITIVE_POINT,
	PRIMITIVE_SEGMENT,
	PRIMITIVE_CIRCLE,
};

#endif