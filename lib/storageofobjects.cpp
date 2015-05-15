#include "global.h"
#include "storageofobjects.h"

ID StorageOfObjects::generateID()
{
	_last_id++;
	while (_shelf.hasKey(_last_id)) { _last_id++; }
	return ID(_last_id);
}

ID StorageOfObjects::add(ObjectBase* object, ID& objid)
{
	if (_shelf.hasKey(objid.getID()))
	{
		objid = generateID();
	}
	object->id = objid;
	_shelf.add(objid.getID(), object);
	return objid;
}

ID StorageOfObjects::add(ObjectBase* object, unsigned objid)
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
	for (AVLVeiwer<unsigned, ObjectBase*> i(_shelf); i.canMoveNext(); i.moveNext())
	{
		if (i.getValue().key == 0) continue;
		delete i.getValue().value;
	}
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

ObjectBase* StorageOfObjects::viewer::value()
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

ObjectBase* StorageOfObjects::get(unsigned id)
{
	if (_shelf.hasKey(id))
		return _shelf.getValuebyKey(id);
	else
		return 0;
}

ObjectBase* StorageOfObjects::get(ID& id)
{
	if (_shelf.hasKey(id.getID()))
		return _shelf.getValuebyKey(id.getID());
	else
		return 0;
}