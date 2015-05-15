#include "storageofconstraints.h"

bool StorageOfConstraints::findhere(std::list<IConstraint*>& list, IConstraint* constraint)
{
	for (std::list<IConstraint*>::iterator i = list.begin(); i != list.end(); i++)
	{
		if (*i == constraint) return true;
	}
	return false;
}

void StorageOfConstraints::add(ObjectBase* object, IConstraint* constraint)
{
	if (_objects.hasKey(object))
	{
		if (findhere(_objects.getValuebyKey(object), constraint))
		{
		
		}
		else
			_objects.getValuebyKey(object).push_back(constraint);
	}
	else
	{
		std::list<IConstraint*> a;
		a.push_back(constraint);
		_objects.add(object, a);
	}
}