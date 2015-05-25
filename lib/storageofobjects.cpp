#include "global.h"
#include "storageofobjects.h"
#include "structures.h"

ID StorageOfObjects::generateID()
{
	_last_id++;
	while (_shelf.check(_last_id)) { _last_id++; }
	return ID(_last_id);
}

ID StorageOfObjects::add(ObjectBase* object, ID& objid)
{
	if (_shelf.check(objid.getID()))
	{
		objid = generateID();
	}
	object->id = objid;
	_shelf.insert(objid.getID(), object);
	return objid;
}

bool StorageOfObjects::has_SorC_with_P(Point* object)
{
	for (myavltree<unsigned, ObjectBase*>::myiterator iter(_shelf); iter.valid(); iter++)
	{
		if (iter.key() == 0) continue;
		switch (iter.value()->objectType())
		{
			case PRIMITIVE_SEGMENT:
			{
				Segment* s = dynamic_cast<Segment*>(iter.value());
				if (s->p1 == object || s->p2 == object) return true;
				break;
			}
			case PRIMITIVE_CIRCLE:
			{
				Circle* c = dynamic_cast<Circle*>(iter.value());
				if (c->p == object) return true;
				break;
			}
			default:
				break;
		}
	}
	return false;
}

ID StorageOfObjects::add(ObjectBase* object, unsigned objid)
{
	if (_shelf.check(objid))
	{
		objid = generateID().getID();
	}
	object->id.setID(objid);
	_shelf.insert(objid, object);
	return ID(objid);
}

void StorageOfObjects::clear()
{
	for (myavltree<unsigned, ObjectBase*>::myiterator i(_shelf); i.valid(); i++)
	{
		if (i.key() == 0) continue;
		delete i.value();
	}
	_shelf.clear();
	_last_id = 0;
	_shelf.insert(0, 0);
}

bool StorageOfObjects::remove(ID& id)
{
	if (id.getID() == 0) return false;
	if (_shelf.check(id.getID()))
	{
		try
		{
			_shelf.erase(id.getID());
		}
		catch (...) { }
		return true;
	}
	return false;
}

ObjectBase* StorageOfObjects::viewer::value()
{
	return _current.value();
}

ID StorageOfObjects::viewer::key()
{
	return ID(_current.key());
}

void StorageOfObjects::viewer::operator++()
{
	_current++;
}

void StorageOfObjects::viewer::operator++(int)
{
	_current++;
}

bool StorageOfObjects::viewer::valid() const
{
	return _current.valid();
};

ObjectBase* StorageOfObjects::get(unsigned id)
{
	if (_shelf.check(id))
		return _shelf.get(id);
	else
		return 0;
}

ObjectBase* StorageOfObjects::get(ID& id)
{
	if (_shelf.check(id.getID()))
		return _shelf.get(id.getID());
	else
		return 0;
}
