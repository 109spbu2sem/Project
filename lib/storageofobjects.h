#ifndef STORAGE_OF_OBJECTS_H
#define STORAGE_OF_OBJECTS_H

#include "global.h"
#include "Id.h"
#include "ObjectSkin.h"

class StorageOfObjects
{
private:
	unsigned _last_id;
	ID generateID();
public:
	StorageOfObjects()
	{
		_last_id = 0;
	}

	ID add(ObjectSkin*, ID id = ID(0));
	ID add(ObjectSkin*, unsigned id = 0);
	bool remove(ID);

	class viewer
	{
	private:
	public:
		ObjectSkin* value();
		void moveNext();
		bool canMoveNext();
	};

};

#endif