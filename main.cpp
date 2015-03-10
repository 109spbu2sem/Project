#include <iostream>
#include "storages.h"

int main()
{
	Storage_List<Vector> store;
	Vector v;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> v.x >> v.y;
		store.add(v);
	}
	v = store.get();
	store.move_next();
	std::cout << (v + store.get()).x << (v + store.get()).y << std::endl;
	return 0;
}
