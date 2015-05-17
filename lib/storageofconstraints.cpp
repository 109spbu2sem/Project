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

ID StorageOfConstraints::generateID()
{
	_last_id++;
	while (_ids.hasKey(_last_id))
	{
		_last_id++;
	}
	return ID(_last_id);
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
	_ids.add(generateID().getID(), constraint);
}

bool StorageOfConstraints::has(ObjectBase* a) const
{
	return _objects.hasKey(a);
}

bool StorageOfConstraints::has(IConstraint* b) const
{
	return _constraints.hasKey(b);
}

bool StorageOfConstraints::has(ID id) const
{
	return _ids.hasKey(id.getID());
}

bool StorageOfConstraints::remove(ObjectBase* object, IConstraint* constraint)
{
	if (!_objects.hasKey(object) || !_constraints.hasKey(constraint)) return false;

	_objects.getValuebyKey(object).remove(constraint);
	if (_objects.getValuebyKey(object).size() == 0)
		_objects.remove(object);
	_constraints.getValuebyKey(constraint).remove(object);
	if (_constraints.getValuebyKey(constraint).size() == 0)
		_constraints.remove(constraint);

	return true;
}

IConstraint* StorageOfConstraints::get(ID id)
{
	try
	{
		return _ids.getValuebyKey(id.getID());
	}
	catch (std::logic_error err)
	{
		return 0;
	}
}

bool StorageOfConstraints::remove(ID id)
{
	return _ids.remove(id.getID());
}

std::list<IConstraint*>& StorageOfConstraints::get(ObjectBase* object)
{
	return _objects.getValuebyKey(object);
}

std::list<ObjectBase*>& StorageOfConstraints::get(IConstraint* constraint)
{
	return _constraints.getValuebyKey(constraint);
}

ID StorageOfConstraints::getid(IConstraint* constraint)
{
	for (AVLVeiwer<unsigned, IConstraint*> iter(_ids); iter.canMoveNext(); iter.moveNext())
	{
		if (iter.getValue().key == 0) continue;
		if (iter.getValue().value == constraint) return iter.getValue().key;
	}
	return ID(0);
}

void StorageOfConstraints::clear()
{
	_objects.clear();
	_constraints.clear();
	_ids.clear();
	_last_id = 0;
	_ids.add(0, 0);
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