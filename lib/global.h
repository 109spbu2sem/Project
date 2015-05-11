#ifndef PI
#define PI 3.1415926535897932384

#define COLORSELECTED 0x3560d6
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
	CONSTR_3PRATIO,
	CONSTR_EXCONTACT,
	CONSTR_INCONTACT
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
	Color(unsigned);
	~Color();
	void setColor(unsigned long);
	void setColor(const Color&);
	void setColor(unsigned char, unsigned char, unsigned char);
	unsigned getColor(char mode = 0) const;
};

class Interface
{
public:
	// id, x, y, color
	virtual bool DrawPoint(unsigned, double, double, Color = 0) = 0;
	// id, x1, y1, x2, y2, color
	virtual bool DrawSegment(unsigned, double, double, double, double, Color = 0) = 0;
	// id, x, y, r, color
	virtual bool DrawCircle(unsigned, double, double, double, Color = 0) = 0;
	virtual bool Clear() = 0;
};

#endif
