#ifndef SPARSE_T_H
#define SPARSE_T_H
#include <set>
#include "storage_list.h"

struct Pair{
	unsigned r, c;
};

class SparseT{
private:
	struct Pair{
		unsigned r, c;
	};
	Storage_List < Pair > List;
public:
	SparseT(void){

	}
	~SparseT(){
		List.clear();
	}
	void add(unsigned r, unsigned c){
		if (get(r, c) == 0){
			Pair A;
			A.r = r;
			A.c = c;
			List.add(A);
		}
	}
	bool get(unsigned r, unsigned c){
		ListViewer<Pair> A(List);
		Pair P;
		P.c = c;
		P.r = r;
		while (A.canMoveNext())
		{
//			if (A.getValue() == P)return true;
			A.moveNext();
		}
		return false;
	}
	void del(unsigned r, unsigned c){
		ListViewer<Pair> A(List);
		Pair P;
		P.c = c;
		P.r = r;
		while (A.canMoveNext())
		{
//			if (A.getValue == P)
			{
				List.remove(&A);
				break;
			}
			A.moveNext();
		}
	}
};

Storage_List<std::set<unsigned>> graphsfind(Storage_List<Pair> List){
	Storage_List<std::set<unsigned>> data;
	std::set<unsigned> compsub, condidates, Not,all;
	ListViewer<Pair> A(List);

	while (A.canMoveNext())
	{
		all.insert(A.getValue().c);
		all.insert(A.getValue().r);
		A.moveNext();
	}

	compsub.insert(*(all.begin()));
	unsigned copy;
	copy = *(all.begin());
	condidates.insert(*(all.begin()));
	while (all.size() != 0){
		while (condidates.size()!=0){
			A.back_to_begin();
			do{
				if (A.getValue().c == copy){
					condidates.insert(A.getValue().r);
					compsub.insert(A.getValue().r);
				}
				if (A.getValue().r == copy){
					condidates.insert(A.getValue().c);
					compsub.insert(A.getValue().c);
				}
				if (A.getValue().c == copy || A.getValue().r == copy) List.remove(&A);
				else A.moveNext();
			} while (A.canMoveNext());

			A.back_to_begin();
			/*while (A.canMoveNext())
			{
				std::cout << A.getValue().c << ' ' << A.getValue().r << '\n';
				A.moveNext();
			}*/
			compsub.insert(copy);
			condidates.erase(copy);
			Not.insert(copy);
			all.erase(copy);
			if(condidates.size()) copy = *(condidates.begin());
			if (all.size() == 1){
				all.clear();
				condidates.clear();
				break;

			}
		}
		data.add(compsub);
		compsub.clear();
		Not.clear();
		if (all.size()){
			copy = *(all.begin());
			condidates.insert(copy);
		}
	}
	return data;
	
}

#endif
