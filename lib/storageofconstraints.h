#ifndef SOFCONSTR_H
#define SOFCONSTR_H

#include "storages\AVL_tree.h"
#include "global.h"
#include "ObjectBase.h"
#include <list>

class StorageOfConstraints
{
private:
	Storage_AVL<ObjectBase*, std::list<IConstraint*> > _objects;
	Storage_AVL<IConstraint*, std::list<ObjectBase*> > _constraints;

	bool _findhere(std::list<IConstraint*>&, IConstraint*);
	bool _findhere(std::list<ObjectBase*>&, ObjectBase*);
public:
	StorageOfConstraints()
	{

	}
	~StorageOfConstraints()
	{

	}
	void add(ObjectBase*, IConstraint*);
	bool remove(ObjectBase*, IConstraint*);
	bool has(ObjectBase*) const;
	bool has(IConstraint*) const;
	std::list<IConstraint*>& get(ObjectBase*);
	std::list<ObjectBase*>& get(IConstraint*);
	void clear();
};

#endif