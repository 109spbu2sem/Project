#include <iostream>
#include "storages.h"

using namespace std;

int main()
{
	try
	{
		storage<Point> point;
		storage<Segment> segment;
		Point A;
		cout << "Add Point:" << endl;
		cout << "x = "; cin >> A.x;
		cout << "y = ";	cin >> A.y;
		cout << "Add in Storage" << endl;
		point.add(A); 
		cout << point.get(0).x << " " << point.get(0).y << endl; 

	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}
	return 0;
}