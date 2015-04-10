#ifndef PI
#define PI 3.1415926535897932384

double length(double, double, double, double);

class iConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
	virtual unsigned type() = 0;
};


#endif
