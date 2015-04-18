#include "ObjectSkin.h"


ObjectSkin::ObjectSkin()
{
	_visible = 1;
	_select = 0;
}


ObjectSkin::~ObjectSkin()
{
}

void ObjectSkin::changeSelect(bool b)
{
	_select = b;
}

void ObjectSkin::changeVisible()
{
	_visible = !_visible;
}

bool ObjectSkin::isSelected()
{
   return _select;
}

bool ObjectSkin::isVisible()
{
   return _visible;
}