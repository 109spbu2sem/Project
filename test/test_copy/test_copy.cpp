#include <iostream>
#include "storage.h"

int main(){
	storage_template<int> *ps;
	if (true){
		storage_template<int> s1;
		for (int k = 0; k< 34;++k){
			s1.add(k);
		}
		ps = new storage_template<int>(s1);
	}

	for (int k = 0; k< 34;++k)
		std::cout << (*ps)[k] << std::endl;

	return 0;
}
