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

	bool findhere(std::list<IConstraint*>&, IConstraint*);
public:
	StorageOfConstraints()
	{

	}
	~StorageOfConstraints()
	{

	}
	void add(ObjectBase*, IConstraint*);
	void add(IConstraint*, ObjectBase*);
	bool remove(ObjectBase*);
	bool remove(IConstraint*);
	bool find(ObjectBase*) const;
	bool find(IConstraint*) const;
	std::list<IConstraint*>* get(ObjectBase*);
	std::list<ObjectBase*>* get(IConstraint*);
	void clear();
};

#endif