#include "global.h"
#include "storageofobjects.h"

ID StorageOfObjects::generateID()
{
	_last_id++;
	while (_shelf.hasKey(_last_id)) { _last_id++; }
	return ID(_last_id);
}

ID StorageOfObjects::add(ObjectSkin* object, ID& objid)
{
	if (_shelf.hasKey(objid.getID()))
	{
		objid = generateID();
	}
	object->id = objid;
	_shelf.add(objid.getID(), object);
	return objid;
}

ID StorageOfObjects::add(ObjectSkin* object, unsigned objid)
{
	if (_shelf.hasKey(objid))
	{
		objid = generateID().getID();
	}
	object->id.setID(objid);
	_shelf.add(objid, object);
	return ID(objid);
}

void StorageOfObjects::clear()
{
	_shelf.clear();
	_last_id = 0;
	_shelf.add(0, 0);
}

bool StorageOfObjects::remove(ID& id)
{
	if (id.getID() == 0) return false;
	if (_shelf.hasKey(id.getID()))
	{
		try
		{
			_shelf.remove(id.getID());
		}
		catch (...) { }
		return true;
	}
	return false;
}

ObjectSkin* StorageOfObjects::viewer::value()
{
	return _current.getValue().value;
}

ID StorageOfObjects::viewer::key()
{
	return ID(_current.getValue().key);
}

void StorageOfObjects::viewer::moveNext()
{
	_current.moveNext();
}

bool StorageOfObjects::viewer::canMoveNext()
{
	return _current.canMoveNext();
};

ObjectSkin* StorageOfObjects::get(unsigned id)
{
	try
	{
		return _shelf.getValuebyKey(id);
	}
	catch (std::logic_error a)
	{
		throw a;
	}
}

ObjectSkin* StorageOfObjects::get(ID& id)
{
	try
	{
		return _shelf.getValuebyKey(id.getID());
	}
	catch (std::logic_error a)
	{
		throw a;
	}
}