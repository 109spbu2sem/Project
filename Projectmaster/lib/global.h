#ifndef PI
#define PI 3.1415926535897932384

#define SELECTEDCOLOR 0x003adb
#define COLORDEF 0x000000

double length(double, double, double, double);

double min(double, double);

enum CONSTR_TYPE
{
	CONSTR_COLLECTOR,
	CONSTR_P2PDIST,
	CONSTR_P2SECTDIST,
	CONSTR_P2LINEDIST,
	CONSTR_3PONLINE,
	CONSTR_L2LANGLE,
	CONSTR_3PRATIO
};

enum PRIMITIVE_TYPE
{
	PRIMITIVE_NOTHING,
	PRIMITIVE_POINT,
	PRIMITIVE_SEGMENT,
	PRIMITIVE_CIRCLE,
};

class IConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
	virtual CONSTR_TYPE type() = 0;
};

class Color
{
private:
	unsigned _color;
public:
	Color();
	~Color();
	void setColor(unsigned long);
	void setColor(unsigned char, unsigned char, unsigned char);
	unsigned getColor(char mode = 0) const;
};

#endif
