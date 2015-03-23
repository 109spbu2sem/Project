#include <iostream>
#include "array.h"
#include "list.h"
#include "tree_storage.h"

int main(){
	tree_storage<int, int> S;
	for (unsigned i = 0; i < 100000; ++i){
		S.add(i, 5);
	}
	
	system("pause");

	return 0;
}