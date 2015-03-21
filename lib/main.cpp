#include <iostream>
#include "core.h"

int main()
{
	while (1)
	{
		Storage_Array<Point*> storage;
		for (int i = 0; i < 120; i++)
		{
			Point *a = new Point(i, i+1);
			storage.add(a);
			std::cout << storage[i] << " | " << *storage[i]->_x << " " << *storage[i]->_y << " | w= " << storage.myWeight() << std::endl;
		}
	}
	return 0;
}
