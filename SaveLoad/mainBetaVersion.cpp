#include <iostream> 
#include <fstream>
#include "Core.h"
using namespace std;


void save(DynArray<point> action,DynArray<section> action2 )
{
	int size_points = action.size();
	fstream save1;
	save1.open("test.txt", ios_base::out | ios_base::trunc);
	// Add in file kol-vo Points
	save1 << size_points << ' ';
	// Add in file Points (x,y)
	for (unsigned i = 0; i < size_points; i++)
		save1 << action.get(i).x << ' ' << action.get(i).y << ' ';
	save1 << '\n';
	// Add in file Section (a,b)
	int size_sections = action2.size();
	save1 << size_sections << ' ';
	for (unsigned i = 0; i < size_sections; i++)
		save1 << action2.get(i).a.x << ' ' << action2.get(i).a.y << ' ' 
		<< action2.get(i).b.x << ' ' << action2.get(i).b.y << ' ';
	save1 << '\n';


	save1.close();
}

void load(DynArray<point>&action1, DynArray<section>&action2) 
{
	fstream load1;
	point p;
	section s;
	load1.open("test.txt");
	int size_points, size_sections;
	load1 >> size_points;
	for (unsigned i = 0; i < size_points; ++i)
	{
		load1 >> p.x;
		load1 >> p.y;
		action1.add(p);
	}
	load1 >> size_sections;
	for (unsigned i = 0; i < size_sections; ++i) 
	{
		load1 >> s.a.x;
		load1 >> s.a.y;
		load1 >> s.b.x;
		load1 >> s.b.y;
		action2.add(s);
	}


	load1.close();
}



int main()
{
	unsigned a, b;
	double num;
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
	
	//save(Point, Section);
	load(Point, Section);
	int size_points = Point.size();
	int size_sections = Section.size();
	for (int i = 0; i < size_points; i++)
	{
		cout << i + 1 << " x = " << Point.get(i).x << endl;
		cout << i + 1 << " y = " << Point.get(i).y << endl;
	}
	for (int i = 0; i < size_sections; i++)
	{
		cout << i + 1 << " x1 = " << Section.get(i).a.x << endl;
		cout << i + 1 << " y1 = " << Section.get(i).a.y << endl;
		cout << i + 1 << " x2 = " << Section.get(i).b.x << endl;
		cout << i + 1 << " y2 = " << Section.get(i).b.y << endl;
	}
	return 0;
}