#include <iostream> 
#include <fstream>
#include "Storage.h"
using namespace std;


void save(DynArray<point>&action, DynArray<section>&action2)
{
	fstream save1;
	save1.open("test.txt", ios_base::out | ios_base::trunc);
	save1 << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
	save1 << "<primitive>\n";
	save1 << "	<point>\n";
	save1 << "		<amount>" << action.size() << "</amount>\n";
	for (unsigned i = 0; i < action.size(); i++)
	save1 << "		<coordinates x=\"" 
		<< action.get(i).x << "\" y=\"" 
		<< action.get(i).y << "\">"
		<< i+1 << " Point</coordinates>\n";
	save1 << "	</point>\n";
	save1 << "	<section>\n";
	save1 << "		<amount>" << action2.size() << "</amount>\n";
	for (unsigned i = 0; i < action2.size(); i++)
		save1 << "		<coordinates Ax=\""
		<< action2.get(i).a.x << "\" Ay=\""
		<< action2.get(i).a.y << "\" Bx=\""
		<< action2.get(i).b.x << "\" By=\""
		<< action2.get(i).b.y << "\">"
		<< i + 1 << " Section</coordinates>\n";
	save1 << "	</section>\n";
	save1 << "</primitive>\n";

	save1.close();
}
int main()
{
	unsigned a, b;
	DynArray<point> Point;
	DynArray<section> Section;
	point p;
	section s;
	cout << "Number of points --------> ";
	cin >> a;
	for (unsigned i = 0; i < a; ++i)
	{
		cout << i + 1 << " point " << "x = ";
		cin >> p.x;
		cout << i + 1 << " point " << "y = ";
		cin >> p.y;
		Point.add(p);
	}
	cout << "Number of sections --------> ";
	cin >> b;
	for (unsigned i = 0; i < b; ++i)
	{
		cout << i + 1 << " section " << "x1 = ";
		cin >> s.a.x;
		cout << i + 1 << " section " << "y1 = ";
		cin >> s.a.y;
		cout << i + 1 << " section " << "x2 = ";
		cin >> s.b.x;
		cout << i + 1 << " section " << "y2 = ";
		cin >> s.b.y;
		Section.add(s);
	}

	save(Point, Section);
	return 0;
}