#include "storageofconstraints.h"

bool StorageOfConstraints::_findhere(mylist<IConstraint*>& list, IConstraint* constraint)
{
	for (mylist<IConstraint*>::myiterator i = list.begin(); i.valid(); i++)
	{
		if (*i == constraint) return true;
	}
	return false;
}

bool StorageOfConstraints::_findhere(mylist<ObjectBase*>& list, ObjectBase* constraint)
{
	for (mylist<ObjectBase*>::myiterator i = list.begin(); i.valid(); i++)
	{
		if (*i == constraint) return true;
	}
	return false;
}

ID StorageOfConstraints::generateID()
{
	_last_id++;
	while (_ids.check(_last_id))
	{
		_last_id++;
	}
	return ID(_last_id);
}

void StorageOfConstraints::add(ObjectBase* object, IConstraint* constraint)
{
	if (_objects.check(object))
	{
		if (! _findhere(_objects.get(object), constraint))
			_objects.get(object).push_back(constraint);
	}
	else
	{
		mylist<IConstraint*> a;
		a.push_back(constraint);
		_objects.insert(object, a);
	}
	if (_constraints.check(constraint))
	{
		if (! _findhere(_constraints.get(constraint), object))
			_constraints.get(constraint).push_back(object);
	}
	else
	{
		mylist<ObjectBase*> b;
		b.push_back(object);
		_constraints.insert(constraint, b);
	}
	_ids.insert(generateID().getID(), constraint);
}

bool StorageOfConstraints::has(ObjectBase* a) const
{
	return _objects.check(a);
}

bool StorageOfConstraints::has(IConstraint* b) const
{
	return _constraints.check(b);
}

bool StorageOfConstraints::has(ID id) const
{
	return _ids.check(id.getID());
}

bool StorageOfConstraints::remove(ObjectBase* object, IConstraint* constraint)
{
	if (!_objects.check(object) || !_constraints.check(constraint)) return false;

	try
	{
		_objects.get(object).erase(_objects.get(object).find(constraint));
		if (_objects.get(object).size() == 0)
			_objects.erase(object);
		_constraints.get(constraint).erase(_constraints.get(constraint).find(object));
		if (_constraints.get(constraint).size() == 0)
			_constraints.erase(constraint);
	}
	catch (...)
	{
		return false;
	}

	return true;
}

IConstraint* StorageOfConstraints::get(ID id)
{
	try
	{
		return _ids.get(id.getID());
	}
	catch (std::logic_error err)
	{
		return 0;
	}
}

bool StorageOfConstraints::remove(ID id)
{
	return _ids.erase(id.getID());
}

mylist<IConstraint*>& StorageOfConstraints::get(ObjectBase* object)
{
	return _objects.get(object);
}

mylist<ObjectBase*>& StorageOfConstraints::get(IConstraint* constraint)
{
	return _constraints.get(constraint);
}

ID StorageOfConstraints::getid(IConstraint* constraint)
{
	for (myavltree<unsigned, IConstraint*>::myiterator iter(_ids); iter.valid(); iter++)
	{
		if (iter.key() == 0) continue;
		if (iter.value() == constraint) return iter.key();
	}
	return ID(0);
}

void StorageOfConstraints::clear()
{
	_objects.clear();
	_constraints.clear();
	_ids.clear();
	_last_id = 0;
	_ids.insert(0, 0);
}

mylist<ObjectBase*>& StorageOfConstraints::viewer::objects()
{
	return _viewer.value();
}
IConstraint* StorageOfConstraints::viewer::constraint()
{
	return _viewer.key();
}
bool StorageOfConstraints::viewer::valid() const
{
	return _viewer.valid();
}
void StorageOfConstraints::viewer::operator++()
{
	_viewer++;
}
void StorageOfConstraints::viewer::operator++(int)
{
	_viewer++;
}