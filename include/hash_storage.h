#ifndef _HASH_STORAGE_H
#define _HASH_STORAGE_H
#include "storage.h"
#include "linkedlist.h"
#include "brute_hasher.h"

template<typename A,typename B,typename hasher = BruteHasher<A> > class hash_storage{
public:
	struct tuple{A a;B b;};

	hash_storage(){};
	~hash_storage(){};

	void add(const A& a,const B& b ){};
	bool hasA(const A& a)const{return false;};
	B& getBbyA(const A& a){};
	unsigned size()const{return _size;}
	template<typename A1,typename B1> class Viewer{
	public:
		Viewer();
		Viewer(hash_storage&s){
		}

		typename tree_storage<A1,B1>::tuple & getValue(){
			throw std::runtime_error("Invalid viewer");
		};
		void moveNext(){};
		bool canMoveNext(){return false;};
	private:
		typename storage_template<linkedlist<typename hash_storage<A1,B1>::tuple> >::Viewer _dv;
		typename linkedlist<typename hash_storage<A,B>::tuple >::template Viewer<typename hash_storage<A,B>::tuple> _lv;
	};

private:
	storage_template<linkedlist<tuple> > _table;
	unsigned _size;
	friend class Viewer<A,B>;
};

#endif
