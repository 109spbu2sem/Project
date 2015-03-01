#include <iostream>
#include <cmath>
#include "Structures.h"

using namespace std;

int main(int argc, const char * argv[])
{
	setlocale(0, "");
	//    Point P1;
	//    P1.X = 2;  P1.Y = 3;
	//    
	//    Point P2;
	//    P2.X = -2; P2.Y = 4;
	//    
	//    Point P3;
	//    P3.X = 17; P3.Y = -3;
	//    
	//    DynArray Storage;
	//    Storage.Store(P1);
	//    Storage.Store(P2);
	//    Storage.Store(P3);
	//    
	//    
	//    try
	//    {
	//        cout << Storage.Get(0).X << endl;
	//        cout << Storage.Get(1).X << endl;
	//        cout << Storage.Get(2).X << endl;
	//    }
	//    catch (invalid_argument e)
	//    {
	//        cout << e.what() << endl;
	//    }

	Point P;
	unsigned n = 2;
	DynArrayPoint Storage;
	unsigned Ans[2];
	Ans[0] = 0;
	Ans[1] = 1;

	cout << "Чтобы прекратить вводить координаты введите 00" << endl;

	//  Первые две точки обязательны
	cin >> P.X >> P.Y;
	cout << endl;
	Storage.Store(P);
	cin >> P.X >> P.Y;
	Storage.Store(P);
	cout << endl;

	//  Через цикл получаем остальные
	while (true)
	{
		cin >> P.X;
		if (P.X == 00)
		{
			cout << "-- Конец ввода --" << endl << endl;
			break;
		}
		cin >> P.Y;
		cout << endl;

		Storage.Store(P);

		++n;
	}

	double min = (sqrt(pow((Storage.Get(0).X - Storage.Get(1).X), 2) + pow((Storage.Get(0).Y - Storage.Get(1).Y), 2)));
	try
	{
		for (unsigned i = 0; i < n; ++i)
		{
			for (unsigned k = 1; k < n; ++k)
			{
				if (i != k)
					if ((sqrt(pow((Storage.Get(i).X - Storage.Get(k).X), 2) + pow((Storage.Get(i).Y - Storage.Get(k).Y), 2))) < min)
					{
					min = (sqrt(pow((Storage.Get(i).X - Storage.Get(k).X), 2) + pow((Storage.Get(i).Y - Storage.Get(k).Y), 2)));
					Ans[0] = i;
					Ans[1] = k;
					}
			}
		}

		cout << "Min distance: " << min << endl;
		cout << "1: " << Storage.Get(Ans[0]).X << " " << Storage.Get(Ans[0]).Y << endl;
		cout << "2: " << Storage.Get(Ans[1]).X << " " << Storage.Get(Ans[1]).Y << endl << endl;

		//  Меняем эти две точки местами
		Point P1 = Storage.Get(Ans[0]);
		(*Storage.Value(Ans[0])) = (*Storage.Value(Ans[1]));
		(*Storage.Value(Ans[1])) = P1;

		cout << "1: " << Storage.Get(Ans[0]).X << " " << Storage.Get(Ans[0]).Y << endl;
		cout << "2: " << Storage.Get(Ans[1]).X << " " << Storage.Get(Ans[1]).Y << endl << endl;
	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
