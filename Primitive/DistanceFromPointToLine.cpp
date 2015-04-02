#include <iostream>
using namespace std;

double DistancePointToLine(double x, double y, double x1, double x2, double y1, double y2, double d)
{
	double X, Y;
	Y = (-x*x2*y2 + y*y1*y2 + x*x2*y1 - y*y1*y1 + x1*x2*y2 - x2*x2*y1) / (y1*y2 - y1*y1 + x1*x2 - x2*x2);
	X = (y1*Y + x*x2 - y*y1) / x2;
	d = sqrt((X - x)*(X - x) + (Y - y)*(Y - y));
	return d;
}

int main()
{
	double x, y, x1, x2, y1, y2, d = 0;
	cout << "x = "; cin >> x; 
	cout << "y = "; cin >> y;
	cout << "x1 = "; cin >> x1;
	cout << "y1 = "; cin >> y1;
	cout << "x2 = "; cin >> x2;
	cout << "y2 = "; cin >> y2;
	cout << "Distance = " << DistancePointToLine(x, y, x1, x2, y1, y2, d) << endl;

	return 0;
}