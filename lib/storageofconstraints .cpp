#include "storageofconstraints.h"

bool StorageOfConstraints::_findhere(std::list<IConstraint*>& list, IConstraint* constraint)
{
	for (std::list<IConstraint*>::iterator i = list.begin(); i != list.end(); i++)
	{
		if (*i == constraint) return true;
	}
	return false;
}

bool StorageOfConstraints::_findhere(std::list<ObjectBase*>& list, ObjectBase* constraint)
{
	for (std::list<ObjectBase*>::iterator i = list.begin(); i != list.end(); i++)
	{
		if (*i == constraint) return true;
	}
	return false;
}

void StorageOfConstraints::add(ObjectBase* object, IConstraint* constraint)
{
	if (_objects.hasKey(object))
	{
		if (! _findhere(_objects.getValuebyKey(object), constraint))
			_objects.getValuebyKey(object).push_back(constraint);
	}
	else
	{
		std::list<IConstraint*> a;
		a.push_back(constraint);
		_objects.add(object, a);
	}
	if (_constraints.hasKey(constraint))
	{
		if (! _findhere(_constraints.getValuebyKey(constraint), object))
			_constraints.getValuebyKey(constraint).push_back(object);
	}
	else
	{
		std::list<ObjectBase*> b;
		b.push_back(object);
		_constraints.add(constraint, b);
	}
}

bool StorageOfConstraints::has(ObjectBase* a) const
{
	return _objects.hasKey(a);
}

bool StorageOfConstraints::has(IConstraint* b) const
{
	return _constraints.hasKey(b);
}

bool StorageOfConstraints::remove(ObjectBase* object, IConstraint* constraint)
{
	if (!_objects.hasKey(object) || !_constraints.hasKey(constraint)) return false;

	_objects.getValuebyKey(object).remove(constraint);
	_constraints.getValuebyKey(constraint).remove(object);

	return true;
}

std::list<IConstraint*>& StorageOfConstraints::get(ObjectBase* object)
{
	return _objects.getValuebyKey(object);
}

std::list<ObjectBase*>& StorageOfConstraints::get(IConstraint* constraint)
{
	return _constraints.getValuebyKey(constraint);
}

void StorageOfConstraints::clear()
{
	_objects.clear();
	_constraints.clear();
}

std::list<ObjectBase*>& StorageOfConstraints::viewer::objects()
{
	return _viewer.getValue().value;
}
IConstraint* StorageOfConstraints::viewer::constraint()
{
	return _viewer.getValue().key;
}
bool StorageOfConstraints::viewer::canMoveNext() const
{
	return _viewer.canMoveNext();
}
void StorageOfConstraints::viewer::moveNext()
{
	_viewer.moveNext();
}