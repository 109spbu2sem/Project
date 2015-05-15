#include "ObjectBase.h"


ObjectBase::ObjectBase()
{
	_select = 0;
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::changeSelect(bool b)
{
	_select = b;
}

bool ObjectBase::isSelected()
{
   return _select;
}
