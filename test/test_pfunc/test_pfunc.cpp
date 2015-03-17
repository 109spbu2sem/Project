#include <iostream>
using namespace std;

double f1(double x){
	return x*x-2*x-3;
}
double f2(double x){
	return x*x*x-2*x-3;
}

template<typename T>  T ff(T a){
	return a*a;
}


double find_zero1(double a,double b,double(*f)(double), double eps = 1e-6){
	//////
	(*f)(1);
	return 0;
}
double find_zero2(double a,double b,double(*f)(double), double eps = 1e-6){
	return 0;
}
int main(){

	double zero1 = find_zero1(0,10,&f1);
	double zero2 = find_zero1(0,10,&f2);

	cout << ff(1.0) << endl;
	cout << ff(22) << endl;
	return 0;
}