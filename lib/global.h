#ifndef PI
#define PI 3.1415926535897932384

#define P2P_DIST 1
#define P2S_DIST 2
#define P2L_DIST 3
#define PPPONL 4
#define LL_ANGLE 5

#define SELECTEDCOLOR 1

double length(double, double, double, double);

double min(double, double);

enum CONSTR_TYPE
{
	CONSTR_COLLECTOR,
	CONSTR_P2PDIST,
	CONSTR_P2SECTDIST,
	CONSTR_P2LINEDIST,
	CONSTR_3PONLINE,
	CONSTR_L2LANGLE
};

class IConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
	virtual CONSTR_TYPE type() = 0;
};


#endif