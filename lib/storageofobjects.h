#ifndef STORAGE_OF_OBJECTS_H
#define STORAGE_OF_OBJECTS_H

#include "global.h"
#include "Id.h"
#include "ObjectBase.h"
#include "storages/AVL_tree.h"

class StorageOfObjects
{
private:
	unsigned _last_id;
	Storage_AVL<unsigned, ObjectBase*> _shelf;

	ID generateID();
public:
	friend class viewer;
	StorageOfObjects()
	{
		_last_id = 0;
		_shelf.add(0, 0);
	}

	ID add(ObjectBase*, ID& id);
	ID add(ObjectBase*, unsigned id = 0);
	bool remove(ID&);
	ObjectBase* get(ID&);
	ObjectBase* get(unsigned);

	void clear();

	class viewer
	{
	private:
		AVLVeiwer<unsigned, ObjectBase*> _current;
	public:
		viewer() { }
		viewer(StorageOfObjects& store)
		{
			_current = store._shelf.getIterator();
		}
		ObjectBase* value();
		ID key();
		void moveNext();
		bool canMoveNext() const;
	};

	viewer getIterator()
	{
		return viewer(*this);
	}

};

#endif