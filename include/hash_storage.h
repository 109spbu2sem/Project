#ifndef _HASH_STORAGE_H
#define _HASH_STORAGE_H
#include "linkedlist.h"
#include "brute_hasher.h"

template<typename A,typename B,typename hasher = BruteHasher<A> > class hash_storage{
public:
	hash_storage();
	~hash_storage();
		
	void add(const A& a,const B& b );
	bool hasA(const A& a)const;
	B& getBbyA(const A& a);
	unsigned size()const{return _size;}
private:
	struct tuple{A a;B b};
	dynarray<linkedlist<tuple> > _table;
	unsigned _size;

};

#endif