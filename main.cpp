#include <iostream>
#include <stdexcept>
#include "Point.h"
#include <climits>
using namespace std;
int main() {
	try {
		unsigned a;
		cout << "Number of points --------> ";
		cin >> a;
		Point*s = new Point[a];
		for (unsigned i = 0; i < a; ++i) {
			cout << i + 1 << " point " << "x= ";
			cin >> s[i].x;
			cout << i + 1 << " point " << "y= ";
			cin >> s[i].y;
		}
			DynArray woy;
			for (unsigned i = 0; i < a; ++i) {
				woy.store(s[i]);
			}
			int size = woy.size();
			//	Point*points = new Point[size];
			//	*points = woy.back();
			double min = DBL_MAX;
			int p_min1;
			int p_min2;
			for (unsigned i = 0; i < size; ++i)
			for (unsigned j = i + 1; j < size; ++j) {
				if (sqrt((woy.get(i).x - woy.get(j).x)*(woy.get(i).x - woy.get(j).x)
					+ (woy.get(i).y - woy.get(j).y)*(woy.get(i).y - woy.get(j).y)) < min) {
					min = sqrt((woy.get(i).x - woy.get(j).x)*(woy.get(i).x - woy.get(j).x)
						+ (woy.get(i).y - woy.get(j).y)*(woy.get(i).y - woy.get(j).y));
					p_min1 = i;
					p_min2 = j;
				}
			}
			cout << "Minimum distance between points " << p_min1 << " and " << p_min2 << endl;
		}
		catch (std::invalid_argument e) {
			cout << e.what() << endl;
		}
	}