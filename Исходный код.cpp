using namespace std;
#include <iostream>
#include "storages.h"
//#include "storage.h"
#include "linkedlist.h"
#include "BinaryTree.h"
//#include "vec2.h"

class IConstraint{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
};

class Point2PointDistance :public IConstraint{
	double *p1x, *p1y, *p2x, *p2y;
	double *dist;
public:
	Point2PointDistance(Point & p1, Point& p2, double * distance);
	virtual double error(){
		double dist1 = sqrt((*p1x - *p2x)*(*p1x - *p2x) + (*p1y - *p2y)*(*p1y - *p2y));
		return (dist1 - *dist)*(dist1 - *dist);
	};
	virtual double diff(double *par){
		if (par == p1x){
			return 0;
		}



		return 0;
	};
};

/*class Constraint2{
double * p1,*p2,*p3,*p4;
public:
double error();
double diff(double *par){

if (par == p1)
return ...;
if (par == p2)
return ...

return 0;
};
};*/

int main()
{
	int i = 3;
	std::cout << 4 << endl;
	BinaryTree<int, char> t;
	t.add(3, 'a');
	t.add(5, 'b');
	t.add(16, 'c');
	t.add(8, 'd');
	t.add(1, 'e');
	t.add(7, 'f');
	t.add(4, 'g');
	cout << t.getBbyA(8) << endl;



	return 0;
}