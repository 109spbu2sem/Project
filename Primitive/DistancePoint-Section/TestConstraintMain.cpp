#include <iostream>
#include "DistancePoint-Section.h"
#include "ConstrCollector.h"

using namespace std;

double  DistanceFromPointToSection::length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double DistanceFromPointToSection::GetX(double x, double y, double x1, double y1, double x2, double y2)
{
	double X, Y;
	Y = (-x*x2*y2 + y*y1*y2 + x*x2*y1 - y*y1*y1 + x1*x2*y2 - x2*x2*y1) / (y1*y2 - y1*y1 + x1*x2 - x2*x2);
	X = (y1*Y + x*x2 - y*y1) / x2;
	return X;
}
double DistanceFromPointToSection::GetY(double x, double y, double x1, double y1, double x2, double y2)
{
	double Y;
	Y = (-x*x2*y2 + y*y1*y2 + x*x2*y1 - y*y1*y1 + x1*x2*y2 - x2*x2*y1) / (y1*y2 - y1*y1 + x1*x2 - x2*x2);
	return Y;
}
double DistanceFromPointToSection::DistPointSection(double x, double y, double x1, double y1, double x2, double y2)
{
	double X = GetX(x, y, x1, y1, x2, y2);
	double Y = GetY(x, y, x1, y1, x2, y2);
	return length(X, Y, x, y);
}


double err(double D, double x1,double y1,double x2,double y2){
	return D - sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double f(double D, double x1,double y1,double x2,double y2){
	double e = err(D,x1,y1,x2,y2);
	return e*e;
}
double dfdx2(double D, double x1,double y1,double x2,double y2){
	return 2*err(D,x1,y1,x2,y2)*(x1-x2)/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double dfdy2(double D, double x1,double y1,double x2,double y2){
	return 2*err(D,x1,y1,x2,y2)*(y1-y2)/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void find_para(IConstraint *constr,double **para ,int num_par){
	const double f_epsi = 1e-12;
	double f_cur = constr->error();
	cout << "Starting error " << f_cur <<endl;
	double f_prev = 0; 
	double *dx = new double[num_par];

	do
	{		
		f_prev = f_cur;
		
		double step_min = 0.000001;
		double step_max = 1000;
		// 
		
		for (int k = 0;k < num_par;++k)
			dx[k] = -step_min*constr->diff(para[k]);
		// 
		for (int k = 0;k<num_par;++k)
			*para[k] += dx[k];
		
		f_cur = constr->error();
		//cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi); // видоизменить при исходном расстоянии
	delete[] dx;
	cout << "Error reached = " << f_cur << endl;
}


int main()
{
	struct point
	{
		double x,y;
	};
	
	point A = {2,2};			// исходная точка, от которой нужно найти расстояние
	point B = {2,6};			// 1 точка отрезка
	point C = {7,1};			// 2 точка отрезка

	//double D = 2.82842712476;	// расстояние
	double D = 1.5;
	//double D = 5;
	ConstrCollector collector;
	DistanceFromPointToSection *ccconstr1 = new DistanceFromPointToSection(&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D);
	collector.addConstraint(ccconstr1);

	/*
	Point2Point *ccconstr1 = new Point2Point(&center1.x,&center1.y,&center2.x,&center2.y,&R1);
	collector.addConstraint(ccconstr1);
	Point2Point *ccconstr2 = new Point2Point(&center1.x,&center1.y,&center3.x,&center3.y,&R2);
	collector.addConstraint(ccconstr2);
	Point2Point *ccconstr3 = new Point2Point(&center3.x,&center3.y,&center2.x,&center2.y,&R3);
	collector.addConstraint(ccconstr3);
	*/

	double *paraddr[9];
	paraddr[0] = &A.x;
	paraddr[1] = &A.y;
	paraddr[2] = &B.x;
	paraddr[3] = &B.y;
	paraddr[4] = &C.x;
	paraddr[5] = &C.y;
	paraddr[6] = &D;
	cout<< "Before" << endl;
	std::cout << '(' << A.x	<<','<<	A.y	<<')'<<	endl;
	std::cout << '(' << B.x	<<','<<	B.y	<<')'<<	endl;
	std::cout << '(' << C.x	<<','<<	C.y	<<')'<<	endl;
	std::cout << ccconstr1->error() <<endl;
	//std::cout << ccconstr2->error() <<endl;
	//std::cout << ccconstr3->error() <<endl;

	find_para(&collector,paraddr,6);

	cout << "After" << endl;
	std::cout << '(' << A.x	<<','<<	A.y	<<')'<<	endl;
	std::cout << '(' << B.x	<<','<<	B.y	<<')'<<	endl;
	std::cout << '(' << C.x	<<','<<	C.y	<<')'<<	endl;
	std::cout << ccconstr1->error() <<endl;
	//std::cout << ccconstr2->error() <<endl;
	//std::cout << ccconstr3->error() <<endl;
	//DistanceFromPointToSection::GetX
	//double l1 = length(A.x,A.y,GetX(A.x,A.y,B.x,B.y,C.x,C.y),GetY(A.x,A.y,B.x,B.y,C.x,C.y));
	
	double l1 = ccconstr1->DistPointSection(A.x,A.y,B.x,B.y,C.x,C.y);
	
	//double l2 = length(center1.x,center1.y,center3.x,center3.y);
	//double l3 = length(center2.x,center2.y,center3.x,center3.y);
	
	cout <<"l1 = " << l1 << endl;
	//cout <<"l2 = " << l2 << endl;
	//cout <<"l3 = " << l3 << endl;
	//cout << l1*l1+l2*l2 - l3*l3 << endl;

	return 0;
}