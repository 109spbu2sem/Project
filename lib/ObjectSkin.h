#ifndef OBJECTSKIN_H
#define OBJECTSKIN_H
#include "LineSkin.h"

class ObjectSkin
{
public:
	LineSkin line;
	Color background;
	//unsigned char visible; // 0 - invisible, 100 - full visible; // May be unused
	bool visible_b; // false(0) invisible, true(1) visible
	ObjectSkin();
	~ObjectSkin();
};

#endif // OBJECTSKIN_H 