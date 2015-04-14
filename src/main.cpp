#include <iostream>
#include "storages.h"
#include "storage.h"
#include "linkedlist.h"
#include "tree_storage.h"
#include "vec2.h"
#include "brute_hasher.h"
#include "advanced_hasher.h"
#include "hash_storage.h"

using std::cout;
using std::endl;

class IConstraint{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
};

class Point2PointDistance:public IConstraint{
	double *p1x,*p1y,*p2x,*p2y;
	double *dist;
public:
	Point2PointDistance(Point & p1,Point& p2,double * distance);
	virtual double error(){
		double dist1 = sqrt((*p1x - *p2x)*(*p1x - *p2x) + (*p1y -*p2y)*(*p1y - *p2y));
		return (dist1 - *dist)*(dist1 - *dist);
	};
	virtual double diff(double *par){
		if (par == p1x){
			return 0;
		}



		return 0;
	};
};






class Constraint2{
	double * p1,*p2,*p3,*p4;
public:
	double error();
	double diff(double *par){

		if (par == p1)
			return 0;
		if (par == p2) 
			return 0;

		return 0;
	};
};

int main()
{
	storage_template<Point> ps;


	double d = 0.123123;

	unsigned sum = 0;
	unsigned char *pc = (unsigned char *)(&d);
	for (int k =0;k< sizeof(d);++k){
		sum += *pc;
		cout << int(*pc++)<<endl;
	}
	cout << "Sum = " << sum << endl;

	BruteHasher<double> b;
	cout << b(d) <<endl;

	hash_storage<double,int> stor;
	hash_storage<double,int,AdvancedHasher<double> > storAdv;
	
	hash_storage<double,int,AdvancedHasher<double> >::Viewer<double,int> hstorViewer(storAdv);







	tree_storage<int,double> ts;
	ts.add(1,2.3);
	ts.add(2,23.3);
	ts.add(4,443.3);
	ts.add(3,3.2);
	ts.add(5,5.2);
	ts.add(6,552.2);
	ts.add(7,7.2);
	ts.add(8,2);

	cout << ts.size() <<endl;

	tree_storage<int,double>::Viewer<int,double> v(ts);

	do {
		cout << v.getValue().a << " : " << v.getValue().b << endl;
		v.moveNext();
	}
	while (v.canMoveNext());


	storage_template<Point> s1;
	Point p;
	s1.add(p);
	s1[0].x = 90;
	storage_template<Segment> ss1;
	storage_template<Point>::Viewer pv(s1);
	while (pv.canMoveNext()){
		pv.getValue().x +=2;
		pv.moveNext();
	}


	pv = s1.getStartingViewer();
	while (pv.canMoveNext()){
		std::cout << pv.getValue().x;
		pv.moveNext();
	}






	linkedlist<Point> ll;
	ll.add(p);
	ll.add(p);

	linkedlist<Point>::Viewer<Point> lv1(ll);
	linkedlist<Point>::Viewer<Point> lv2(ll);
	lv2.moveNext();

	while(lv2.canMoveNext()){
		if (lv1.getValue().x < lv2.getValue().x)
			std::cout << "Wrong pair" <<std::endl;
		lv1.moveNext();
		lv2.moveNext();
	}
	








	
	vec2 v1(1,0);
	vec2 v2(3,-4);

	//vec2 v3 = v1.sum(v2);
	vec2 v3 = v1 + v2;
	//vec2 v4 = v3.operator+(v2);
	vec2 v4 = v3 + v2;

	//storagepoints sp;
	linkedlist<Point> sp;

	sp.add(p);
	sp.add(p);	



	//Point p1 = sp.operator[](1);
	/*
	storagepoints storagep;
	//-------------------searching minimum
	unsigned n;
	std::cin >> n;
	std::cin >> p.x;
	std::cin >> p.y;
	double min = 400;
	unsigned min1;
	unsigned min2;
	storagep.add(p);
	for (unsigned i = 1; i < n; i++)
	{
		std::cin >> p.x;
		std::cin >> p.y;
		storagep.add(p);
		for (unsigned j = 0; j < i; j++)
		{
			if (pow(storagep[i].x - storagep[j].x, 2) + pow(storagep[i].y - storagep[j].y, 2) < min)
			{
				min = pow(storagep[i].x - storagep[j].x, 2) + pow(storagep[i].y - storagep[j].y, 2);
				min1 = j;
				min2 = i;
			}
		}
	}
	std::cout << "p1 = " << storagep[min1].x << " " << storagep[min1].y << std::endl;
	std::cout << "p2 = " << storagep[min2].x << " " << storagep[min2].y << std::endl;
	//-------------------
	storagesegments storage_s;
	std::cin >> n;
	for (unsigned i = 0; i < n; i++)
	{
		Point p,p1;
		//point
		std::cin >> p.x;
		std::cin >> p.y;
		//vector
		std::cin >> p1.x;
		std::cin >> p1.y;
		//add new segment (p,p1) to storage
		storage_s.add(Segment( p, p1 ));
	}
	//searching for orthogonal segments
	for (unsigned i = 0; i < storage_s.size() - 1; i++)
	{
		for (unsigned j = 1; j < storage_s.size(); j++)
		{
			if (storage_s[i].d.x * storage_s[j].d.x + storage_s[i].d.y * storage_s[j].d.y == 0)//check for orthogonal
			{
				std::cout << "s[" << i << "].d= " << storage_s[min1].d.x << " " << storage_s[min1].d.y << std::endl;
				std::cout << "s[" << j << "].d= " << storage_s[min2].d.x << " " << storage_s[min2].d.y << std::endl;
			}
		}
	}
	*/
	return 0;
}