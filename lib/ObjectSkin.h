#ifndef OBJECTSKIN_H
#define OBJECTSKIN_H
#include "LineSkin.h"
#include "Id.h"
#include "global.h"
#include "enums.h"

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
	virtual ~ObjectSkin();
	void changeVisible();
	void changeSelect(bool b);
	void changeSelect()
	{
		_select = !_select;
	}
   bool isSelected();
   bool isVisible();
	virtual PRIMITIVE_TYPE objectType() = 0;
};

#endif // OBJECTSKIN_H 