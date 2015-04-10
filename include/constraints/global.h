#ifndef PI
#define PI 3.1415926535897932384

double length(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

class IConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
};


#endif