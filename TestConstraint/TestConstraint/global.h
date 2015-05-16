#ifndef PI
#define PI 3.1415926535897932384

double length(double, double, double, double);
double DistPointSection(double,double,double,double,double,double);

class IConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
};


#endif