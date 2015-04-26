#include <iostream>
#include "Storage.h"
#include <stdexcept>
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
		DynArray<section> Section;
		DynArray<point> Point;
		for (unsigned i = 0; i < b; ++i) {
			Point.add(p[i]);
		}
		for (unsigned i = 0; i < b; ++i) {
			Section.add(s[i]);
		}
		int sizeSection = Section.size();
		int sizePoint = Point.size();
		// Points belongs to the sections
	/*	for (unsigned i = 0; i < sizePoint; ++i)
		for (unsigned j = 0; j < sizeSection; ++j) {
			if ((Section.get(j).b.y - Section.get(j).a.y)*Point.get(i).x
				- (Section.get(j).b.x - Section.get(j).a.x)*Point.get(i).y
				- Section.get(j).a.x*(Section.get(j).b.y - Section.get(j).a.y)
				+ Section.get(j).a.y*(Section.get(j).b.x - Section.get(j).a.x) == 0) {
				if (Section.get(j).a.x <= Section.get(j).b.x && Section.get(j).a.y <= Section.get(j).b.y) {
					if (Point.get(i).x >= Section.get(j).a.x && Point.get(i).x <= Section.get(j).b.x &&
						Point.get(i).y >= Section.get(j).a.y && Point.get(i).y <= Section.get(j).b.y)
						cout << "Point number " << i + 1 << " belongs to the section number " << j + 1 << endl;
				}
				if (Section.get(j).a.x >= Section.get(j).b.x && Section.get(j).a.y <= Section.get(j).b.y) {
					if (Point.get(i).x <= Section.get(j).a.x && Point.get(i).x >= Section.get(j).b.x &&
						Point.get(i).y >= Section.get(j).a.y && Point.get(i).y <= Section.get(j).b.y)
						cout << "Point number " << i + 1 << " belongs to the section number " << j + 1 << endl;
				}
				if (Section.get(j).a.x <= Section.get(j).b.x && Section.get(j).a.y >= Section.get(j).b.y) {
					if (Point.get(i).x >= Section.get(j).a.x && Point.get(i).x <= Section.get(j).b.x &&
						Point.get(i).y <= Section.get(j).a.y && Point.get(i).y >= Section.get(j).b.y)
						cout << "Point number " << i + 1 << " belongs to the section number " << j + 1 << endl;
				}
				if (Section.get(j).a.x >= Section.get(j).b.x && Section.get(j).a.y >= Section.get(j).b.y) {
					if (Point.get(i).x <= Section.get(j).a.x && Point.get(i).x >= Section.get(j).b.x &&
						Point.get(i).y <= Section.get(j).a.y && Point.get(i).y >= Section.get(j).b.y)
						cout << "Point number " << i + 1 << " belongs to the section number " << j + 1 << endl;
				}
			}
		}*/
		//Search parallel lines
	/*	for (unsigned i = 0; i < sizeSection - 1; ++i)
		for (unsigned j = i + 1; j < sizeSection; ++j) {
			if (((Section.get(i).a.x - Section.get(i).b.x) * (Section.get(j).a.x - Section.get(j).b.x)) +
				((Section.get(i).a.y - Section.get(i).b.y) * (Section.get(j).a.y - Section.get(j).b.y)) == 0) {
				cout << "Section number " << i << " orthogonal " << j << endl;
				Section.value(i, j);
			}
		}
		/*	for (unsigned i = 0; i < sizeSection; ++i)
		cout << i + 1 << " section" << endl <<
		"x1= " << action.get(i).a.x << endl <<
		"x2= " << action.get(i).b.x << endl <<
		"y1= " << action.get(i).a.y << endl <<
		"y2= " << action.get(i).b.y << endl;*/
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
}