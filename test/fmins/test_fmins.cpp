#include <iostream>
#include "Constraint.h"
#include "ConstrCollector.h"

using namespace std;

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

	do{		
		f_prev = f_cur;
		
		double step_min = 0.000001;
		double step_max = 1000;
		// Вычислим приращение вектора параметров через градиент ошибки
		
		for (int k = 0;k < num_par;++k)
			dx[k] = -step_min*constr->diff(para[k]);
		// Изменим значения параметров
		for (int k = 0;k<num_par;++k)
			*para[k] += dx[k];
		
		f_cur = constr->error();
		//cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi);
	delete[] dx;
	cout << "Error reached = " << f_cur << endl;
}


int main(){
	struct point{
		double x,y;
	};
	point center1 = {1,2};
	point center2 = {0,1};
	point center3 = {1,-1};
	double R1  = 3;
	double R2 = 4;
	double R3 = 5;

	ConstrCollector collector;
			
	Point2Point *ccconstr1 = new Point2Point(&center1.x,&center1.y,&center2.x,&center2.y,&R1);
	collector.addConstraint(ccconstr1);
	Point2Point *ccconstr2 = new Point2Point(&center1.x,&center1.y,&center3.x,&center3.y,&R2);
	collector.addConstraint(ccconstr2);
	Point2Point *ccconstr3 = new Point2Point(&center3.x,&center3.y,&center2.x,&center2.y,&R3);
	collector.addConstraint(ccconstr3);

	
	double *paraddr[9];
	paraddr[0] = &center1.x;
	paraddr[1] = &center1.y;
	paraddr[2] = &center2.x;
	paraddr[3] = &center2.y;
	paraddr[4] = &center3.x;
	paraddr[5] = &center3.y;
	paraddr[6] = &R1;
	paraddr[7] = &R2;
	paraddr[8] = &R3;
	cout<< "Before" << endl;
	std::cout << '(' << center1.x<<','<<center1.y<<')'<<endl;
	std::cout << '(' << center2.x<<','<<center2.y<<')'<<endl;
	std::cout << '(' << center3.x<<','<<center3.y<<')'<<endl;
	std::cout << ccconstr1->error() <<endl;
	std::cout << ccconstr2->error() <<endl;
	std::cout << ccconstr3->error() <<endl;

	find_para(&collector,paraddr,6);

	cout << "After" << endl;
	std::cout << '(' << center1.x<<','<<center1.y<<')'<<endl;
	std::cout << '(' << center2.x<<','<<center2.y<<')'<<endl;
	std::cout << '(' << center3.x<<','<<center3.y<<')'<<endl;
	std::cout << ccconstr1->error() <<endl;
	std::cout << ccconstr2->error() <<endl;
	std::cout << ccconstr3->error() <<endl;

	double l1 = length(center1.x,center1.y,center2.x,center2.y);
	double l2 = length(center1.x,center1.y,center3.x,center3.y);
	double l3 = length(center2.x,center2.y,center3.x,center3.y);

	cout <<"l1 = " << l1 << endl;
	cout <<"l2 = " << l2 << endl;
	cout <<"l3 = " << l3 << endl;
	cout << l1*l1+l2*l2 - l3*l3 << endl;

	return 0;
}