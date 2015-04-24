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
	unsigned  nf_eval = 0;
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
		
		nf_eval++;
		f_cur = constr->error();
		//cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi);
	delete[] dx;
	cout << "Error reached = " << f_cur << endl;
	cout << "nf_eval = " << nf_eval << endl;
}

void find_para_gold(IConstraint *constr,double **para ,int num_par){
	const double f_epsi = 1e-12;
	double f_cur = constr->error();
	cout << "Starting error " << f_cur <<endl;
	double f_prev = 0; 
	double *grad = new double[num_par];
	double *old_para = new double[num_par];
	unsigned nf_eval = 0;
	do{		
		f_prev = f_cur;		
		// Вычислим градиент ошибки
		for (int k = 0;k < num_par;++k)
			grad[k] = constr->diff(para[k]);

		double alpha1 = 1;
		// Запомним текущее значение вектора параметров
		for (int k =0;k < num_par; ++k)
			old_para[k] = *para[k];
		// Двигаемся вдоль антиградиента
		for (int k = 0;k<num_par;++k)
			*para[k] -= alpha1*grad[k];
		double f_alpha1 = constr->error();
		nf_eval++;

		while (f_alpha1 <= f_prev){
			alpha1 *=2;
			for (int k = 0;k<num_par;++k)
				*para[k] = old_para[k] - alpha1*grad[k];
			f_alpha1 = constr->error();
			nf_eval++;
		}
		const double gold = 0.5+sqrt(5.0/4);
		double alpha0 = 0;
		double f_alpha0 = f_prev;
		double alphal = alpha1 - (alpha1 - alpha0)/gold;
		double alphar = alpha0 + (alpha1 - alpha0)/gold;
		for (int k = 0;k<num_par;++k)
			*para[k] = old_para[k] - alphal*grad[k];		
		double f_alphal =constr->error();
		nf_eval++;
		for (int k = 0;k<num_par;++k)
			*para[k] = old_para[k] - alphar*grad[k];
		double f_alphar = constr->error();
		nf_eval++;
		unsigned gold_count = 0;
		while (abs(f_alphal - f_alphar) > f_epsi ){
			gold_count ++;
			if (f_alphal < f_alphar){
				alpha1 = alphar; f_alpha1 = f_alphar;
				alphar = alphal; f_alphar = f_alphal;
				alphal = alpha1 - (alpha1 - alpha0)/gold;
				for (int k = 0;k<num_par;++k)
					*para[k] = old_para[k] - alphal*grad[k];		
				f_alphal =constr->error();
				nf_eval++;
			}
			else{
				alpha0 = alphal; f_alpha0 = f_alphal;
				alphal = alphar; f_alphal = f_alphar;
				alphar = alpha0 + (alpha1 - alpha0)/gold;
				for (int k = 0;k<num_par;++k)
					*para[k] = old_para[k] - alphar*grad[k];
				f_alphar = constr->error();
				nf_eval++;
			}
		}
		cout << "gold_count  = " << gold_count  <<endl;
		// Изменим значения параметров
		for (int k = 0;k<num_par;++k)
			*para[k] = old_para[k] - (alphar+alphal)/2*grad[k];
		f_cur = constr->error();
		nf_eval++;
		//cout << "Error reached = " << f_cur << endl;
	}while(abs(f_prev - f_cur) > f_epsi);
	delete[] grad;
	delete[] old_para;
	cout << "Error reached = " << f_cur << endl;
	cout << "nf_eval = " << nf_eval << endl;
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

	//find_para(&collector,paraddr,6);
	find_para_gold(&collector,paraddr,6);

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