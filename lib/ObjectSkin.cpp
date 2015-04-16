#include "ObjectSkin.h"


ObjectSkin::ObjectSkin()
{
}


ObjectSkin::~ObjectSkin()
{
}

void ObjectSkin::changeSelect(bool b = true)
{
	_select = b;
}

void ObjectSkin::changeVisible()
{
	_visible = !_visible;
}