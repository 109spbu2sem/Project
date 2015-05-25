#ifndef STORAGE_OF_OBJECTS_H
#define STORAGE_OF_OBJECTS_H

#include "global.h"
#include "storages/mytree.h"
#include "structures.h"

class StorageOfObjects
{
private:
	unsigned _last_id;
	myavltree<unsigned, ObjectBase*> _shelf;

	ID generateID();
public:
	friend class viewer;
	StorageOfObjects()
	{
		_last_id = 0;
		_shelf.insert(0, 0);
	}

	ID add(ObjectBase*, ID& id);
	ID add(ObjectBase*, unsigned id = 0);
	bool remove(ID&);
	ObjectBase* get(ID&);
	ObjectBase* get(unsigned);
	bool has_SorC_with_P(Point*);

	void clear();

	class viewer
	{
	private:
		myavltree<unsigned, ObjectBase*>::myiterator _current;
	public:
		viewer() { }
		viewer(StorageOfObjects& store)
		{
			_current = store._shelf.begin();
		}
		ObjectBase* value();
		ID key();
		void operator++();
		void operator++(int);
		bool valid() const;
	};

	viewer getIterator()
	{
		return viewer(*this);
	}

};

#endif
