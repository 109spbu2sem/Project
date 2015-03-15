#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
	try {
		unsigned a, b;
		cout << "Number of points --------> ";
		cin >> a;
		point*p = new point[a];
		for (unsigned i = 0; i < a; ++i) {
			cout << i + 1 << " point " << "x= ";
			cin >> p[i].x;
			cout << i + 1 << " point " << "y= ";
			cin >> p[i].y;
		}
		cout << "Number of sections --------> ";
		cin >> b;
		section*s = new section[b];
		for (unsigned i = 0; i < b; ++i) {
			cout << i + 1 << " section " << "x1= ";
			cin >> s[i].a.x;
			cout << i + 1 << " section " << "y1= ";
			cin >> s[i].a.y;
			cout << i + 1 << " section " << "x2= ";
			cin >> s[i].b.x;
			cout << i + 1 << " section " << "y2= ";
			cin >> s[i].b.y;
		}
		LinkedList<point> Point;
		LinkedList<section> Section;
		for (unsigned i = 0; i < a; ++i) {
			Point.add(p[i]);
		}
		for (unsigned i = 0; i < b; ++i) {
			Section.add(s[i]);
		}
		int sizeSection = Section.size();
		int sizePoint = Point.size();
		for (int i = 1; i <= sizePoint; ++i) {
			cout << Point.get(i).x << endl << Point.get(i).y << endl;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
}