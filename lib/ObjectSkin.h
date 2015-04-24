#ifndef OBJECTSKIN_H
#define OBJECTSKIN_H
#include "LineSkin.h"
#include "Id.h"

class ObjectSkin
{
private:
	bool _select; // false(0) object is free, true(1) object if picked
	bool _visible; // false(0) invisible, true(1) visible
public:
	LineSkin line;
	Color color;
	ID id;
	//unsigned char visible; // 0 - invisible, 100 - full visible; // May be unused
	ObjectSkin();
	~ObjectSkin();
	void changeVisible();
	void changeSelect(bool b = 1);
   bool isSelected();
   bool isVisible();
	virtual unsigned objectType() = 0;
};

#endif // OBJECTSKIN_H 