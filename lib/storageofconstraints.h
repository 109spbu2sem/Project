#ifndef SOFCONSTR_H
#define SOFCONSTR_H

#include "storages/mytree.h"
#include "global.h"
#include "ObjectBase.h"
#include "storages/mylist.h"

class StorageOfConstraints
{
private:
	myavltree<ObjectBase*, mylist<IConstraint*> > _objects;
	myavltree<IConstraint*, mylist<ObjectBase*> > _constraints;
	myavltree<unsigned, IConstraint*> _ids;
	unsigned _last_id;

	bool _findhere(mylist<IConstraint*>&, IConstraint*);
	bool _findhere(mylist<ObjectBase*>&, ObjectBase*);
	ID generateID();
public:
	friend class viewer;
	StorageOfConstraints()
	{
		_last_id = 0;
		_ids.insert(0, 0);
	}
	~StorageOfConstraints()
	{

	}
	void add(ObjectBase*, IConstraint*);
	bool remove(ObjectBase*, IConstraint*);
	bool remove(ID);
	bool has(ObjectBase*) const;
	bool has(IConstraint*) const;
	bool has(ID) const;
	mylist<IConstraint*>& get(ObjectBase*);
	mylist<ObjectBase*>& get(IConstraint*);
	IConstraint* get(ID);
	ID getid(IConstraint*);
	class viewer
	{
	private:
		myavltree<IConstraint*, mylist<ObjectBase*> >::myiterator _viewer;
	public:
		viewer() { }
		viewer(StorageOfConstraints& a)
		{
			_viewer = a._constraints.begin();
		}
		mylist<ObjectBase*>& objects();
		IConstraint* constraint();
		bool valid() const;
		void operator++();
		void operator++(int);
	};
	void clear();
	viewer getIterator()
	{
		return viewer(*this);
	}
};

#endif