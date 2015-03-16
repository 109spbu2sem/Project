#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	try
	{
		LinkedList<Point> point;
		LinkedList<Segment> segment;
		Segment A;
		cout << "Add Segment: " << endl;
		cout << "x1 = "; cin >> A.a.x;
		cout << "y1 = "; cin >> A.a.y;
		cout << "x2 = "; cin >> A.b.x;
		cout << "y2 = "; cin >> A.b.y;
		segment.Add(A);
		cout << "Get segment: x1 = " << segment.Get(0).a.x << "; y1 = " << segment.Get(0).a.y << endl;
		cout << "Get segment: x2 = " << segment.Get(0).b.x << "; y2 = " << segment.Get(0).b.y << endl;
	}

	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}

	return 0;
}