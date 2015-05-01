#include "global.h"
#include "storageofobjects.h"

ID StorageOfObjects::generateID()
{
	return ID(0);
}

ID StorageOfObjects::add(ObjectSkin*, ID)
{
	return ID(0);
}

ID StorageOfObjects::add(ObjectSkin*, unsigned)
{
	return ID(0);
}

bool StorageOfObjects::remove(ID)
{
	return true;
}

ObjectSkin* StorageOfObjects::viewer::value()
{
	return 0;
}

void StorageOfObjects::viewer::moveNext()
{

}

bool StorageOfObjects::viewer::canMoveNext()
{
	return true;
};