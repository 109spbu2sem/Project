#ifndef OBJECTSKIN_H
#define OBJECTSKIN_H
#include "Id.h"
#include "global.h"
#include "enums.h"

class ObjectBase
{
private:
	bool _select; // false(0) object is free, true(1) object if picked
public:
	Color color;
	ID id;
	ObjectBase();
	virtual ~ObjectBase();
	void changeSelect(bool b);
	void changeSelect()
	{
		_select = !_select;
	}
   bool isSelected();
	virtual PRIMITIVE_TYPE objectType() = 0;
};

#endif // OBJECTSKIN_H 