#ifndef STORAGE_OF_OBJECTS_H
#define STORAGE_OF_OBJECTS_H

#include "global.h"
#include "Id.h"
#include "ObjectSkin.h"
#include "storages\AVL_tree.h"

class StorageOfObjects
{
private:
	unsigned _last_id;
	Storage_AVL<unsigned, ObjectSkin*> _shelf;

	ID generateID();
public:
	friend class viewer;
	StorageOfObjects()
	{
		_last_id = 0;
		_shelf.add(0, 0);
	}

	ID add(ObjectSkin*, ID& id);
	ID add(ObjectSkin*, unsigned id = 0);
	bool remove(ID&);
	ObjectSkin* get(ID&);
	ObjectSkin* get(unsigned);

	void clear();

	class viewer
	{
	private:
		AVLVeiwer<unsigned, ObjectSkin*> _current;
	public:
		viewer() { }
		viewer(StorageOfObjects& store)
		{
			_current = store._shelf.getIterator();
		}
		ObjectSkin* value();
		ID key();
		void moveNext();
		bool canMoveNext();
	};

	viewer getIterator()
	{
		viewer v(*this);
		return v;
	}

};

#endif