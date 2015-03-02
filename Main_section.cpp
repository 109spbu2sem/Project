#include <iostream>
#include "section.h"
#include <stdexcept>
using namespace std;
int main() {
	try {
		unsigned a;
		cout << "Number of sections --------> ";
		cin >> a;
		section*s = new section[a];
		for (unsigned i = 0; i < a; ++i) {
			cout << i + 1 << " section " << "x1= ";
			cin >> s[i].x1;
			cout << i + 1 << " section " << "x2= ";
			cin >> s[i].x2;
			cout << i + 1 << " section " << "y1= ";
			cin >> s[i].y1;
			cout << i + 1 << " section " << "y2= ";
			cin >> s[i].y2;
		}
		DynArray action;
		for (unsigned i = 0; i < a; ++i) {
			action.add(s[i]);
		}
		int size = action.size();
		for (unsigned i = 0; i < size - 1; ++ i)
		for (unsigned j = i + 1; j < size; ++j) {
			/*	if ((action.get(i).x1 - action.get(i).x2 == action.get(j).y1 - action.get(j).y2) &&
			(action.get(i).y1 - action.get(i).y2 == -(action.get(j).x1 - action.get(j).x2)) ||
			(action.get(i).x1 - action.get(i).x2 == -(action.get(j).y1 - action.get(j).y2)) &&
			(action.get(i).y1 - action.get(i).y2 == action.get(j).x1 - action.get(j).x2)) {*/
			if (((action.get(i).x1 - action.get(i).x2) * (action.get(j).x1 - action.get(j).x2)) +
				((action.get(i).y1 - action.get(i).y2) * (action.get(j).y1 - action.get(j).y2)) == 0) {
				cout << "Section number " << i << " orthogonal " << j << endl;
				action.value(i, j);
			}
		}
		for (unsigned i = 0; i < size; ++i)
			cout << i + 1 << " segment" << endl <<
			"x1= " << action.get(i).x1 << endl <<
			"x2= " << action.get(i).x2 << endl <<
			"y1= " << action.get(i).y1 << endl <<
			"y2= " << action.get(i).y2 << endl;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
}