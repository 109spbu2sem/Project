#include <iostream>
#include "Constraint.h"

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
	const double f_epsi = 1e-6;
	double f_cur = constr->error();
	cout << "Starting error" << f_cur <<endl;
	double f_prev = 0; 
	do{		
		f_prev = f_cur;
		
		double step_min = 0.000001;
		double step_max = 1000;
		// Вычислим приращение вектора параметров через градиент ошибки
		double *dx = new double[num_par];
		for (int k = 0;k < num_par;++k)
			dx[k] = -step_min*constr->diff(para[k]);
		// Изменим значения параметров
		for (int k = 0;k<num_par;++k)
			*para[k] += dx[k];
		delete[] dx;

		f_cur = constr->error();
		cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi);
	cout << "Error reached = " << f_cur << endl;
}


int main(){
	struct point{
		double x,y;
	};
	point center1 = {1,2};
	point center2 = {0,1};
	double R1  = 0.1;
	double R2 = 0.3;

	ContactCircle *ccconstr = new ContactCircle(&center1.x,&center1.y,&center2.x,&center2.y,&R1,&R2);
	double *paraddr[6];
	paraddr[0] = &center1.x;
	paraddr[1] = &center1.y;
	paraddr[2] = &center2.x;
	paraddr[3] = &center2.y;
	paraddr[4] = &R1;
	paraddr[5] = &R2;
	find_para(ccconstr,paraddr,6);


	return 0;
}