#include <iostream>
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


int main(){
	double x1 = 1;
	double y1 = 2;
	double x2 = 4;
	double y2 = 1;
	double D = 1;	
	const double f_epsi = 1e-6;
	double f_cur = f(D,x1,y1,x2,y2);
	cout << "Starting error" << f_cur <<endl;
	double f_prev = 0; 
	do{		
		f_prev = f_cur;
		double dx = dfdx2(D,x1,y1,x2,y2);
		double dy = dfdy2(D,x1,y1,x2,y2);
		double step_min = 0.000001;
		double step_max = 1000;
		double fmin = f(D,x1,y1,x2+step_min*dx,y2+step_min*dy);
		double fmax = f(D,x1,y1,x2+step_max*dx,y2+step_max*dy);
		double step1 = step_min + 0.25*(step_max - step_min);
		double step2 = step_min + 0.75*(step_max - step_min);
		double f1 = f(D,x1,y1,x2+step1*dx,y2+step1*dy);
		double f2 = f(D,x1,y1,x2+step2*dx,y2+step2*dy);

		while ( abs(f1-f2) >f_epsi ) {
			if (f1 < f2) step_max = step2;
			else step_min = step1;
			step1 = step_min + 0.25*(step_max - step_min);
			step2 = step_min + 0.75*(step_max - step_min);
			f1 = f(D,x1,y1,x2-step1*dx,y2-step1*dy);
			f2 = f(D,x1,y1,x2-step2*dx,y2-step2*dy);
		}	
		cout << "s1" << step1 << endl;
		x2 -= step1*dx;
		y2 -= step1*dy;
		f_cur = f(D,x1,y1,x2,y2);
		//cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi);
	cout << "Error reached = " << f_cur << endl;
	cout <<"x2 = " << x2 << " y2 = " << y2 << endl;
	return 0;
}