#include <iostream>
#include "student.h"
#include "structs.h"

double getrange(Point p1, Point p2)
{
	double range = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	return range;
}

int main()
{
	//try
	//{
	//	/*point p;
	//	line l;
	//	circle o;
	//	std::cout << "Point: ";
	//	std::cin >> p.x >> p.y;
	//	std::cout << "Line: ";
	//	std::cin >> l.x >> l.y;
	//	std::cin >> l.xe >> l.ye;
	//	std::cout << "Circle: ";
	//	std::cin >> o.x >> o.y >> o.R;
	//	//----------------------------
	//	std::cout << "Point: ";
	//	std::cout << p.x << " " << p.y << std::endl << std::endl;
	//	std::cout << "Line: ";
	//	std::cout << l.x << " " << l.y << std::endl;
	//	std::cout << "      ";
	//	std::cout << l.xe << " " << l.ye << std::endl << std::endl;
	//	std::cout << "Circle: ";
	//	std::cout << o.x << " " << o.y << " R: " << o.R << std::endl;
	//	return 0;*/
	//	//rational r(1, 3);
	////	rational r1(1, 0);
	////	rational r2(1, 6);
	//	rational r3(30,-30);
	//	//std::cout << r.get_num() << "/" << r.get_den() << std::endl;
	//	std::cout << r3.get_num() << "/" << r3.get_den() << std::endl;
	//	r3.typing();
	//	std::cout << r3.get_num() << "/" << r3.get_den() << std::endl;
	//}
	//catch (std::invalid_argument e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//catch (...)
	//{
	//	std::cout << "error" << std::endl;
	//}
	try
	{
		Point p;
		DynArray storage;
		unsigned n;
		std::cin >> n;
		std::cin >> p.x;
		std::cin >> p.y;
		storage.store(p);
		double min = 400;
		Point min1;
		Point min2;
		for (int i = 0; i < n - 1; i++)
		{
			std::cin >> p.x;
			std::cin >> p.y;
			storage.store(p);
			for (unsigned j = 0; j < storage._size - 1; j++)
			{
				if ((storage.get(j).x - storage.get(storage._size - 1).x) * (storage.get(j).x - storage.get(storage._size - 1).x) + (storage.get(j).y - storage.get(storage._size - 1).y) * (storage.get(j).y - storage.get(storage._size - 1).y) < min)
				{
					min1 = storage.get(j);
					min2 = storage.get(storage._size - 1);
				}
			}
		}
		//std::cout << storage.get(0).x << " " << storage.get(0).y << std::endl;
		//std::cout << storage.get(1).x << " " << storage.get(1).y << std::endl;
	}
	catch (std::invalid_argument e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}