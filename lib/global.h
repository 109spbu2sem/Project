#ifndef PI
#define PI 3.1415926535897932384

#include <string>

#define COLORSELECTED 0x3560d6
#define COLORDEF 0x000000

double length(double, double, double, double);

double min(double, double);

enum CONSTR_TYPE : unsigned
{
	CONSTR_COLLECTOR = 0,
	CONSTR_P2PDIST,
	CONSTR_P2LINEDIST,
	CONSTR_3PONLINE,
	CONSTR_L2LANGLE,
	CONSTR_EXCONTACT,
	CONSTR_INCONTACT,
	CONSTR_PARALLELISM,
	CONSTR_ORTHOGONALITY,
	CONSTR_PONC
};


class IConstraint
{
public:
	virtual double error() = 0;
	virtual double diff(double *par) = 0;
	virtual CONSTR_TYPE type() const = 0;
	virtual double value() const = 0;
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
	unsigned red() const;
	unsigned green() const;
	unsigned blue() const;
};

class Interface
{
public:
	// id, x, y, color
	virtual bool DrawPoint(unsigned, double, double, Color, bool) = 0;
	// id, x1, y1, x2, y2, color
	virtual bool DrawSegment(unsigned, double, double, double, double, Color, bool) = 0;
	// id, x, y, r, color
	virtual bool DrawCircle(unsigned, double, double, double, Color, bool) = 0;
	virtual bool Clear() = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE, double) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE, double) = 0;
	virtual bool ClearRules() = 0;

};

class GraphicsInterface: public Interface
{
public:
	virtual bool SetNameOfWindow(std::string) = 0;
	// id, x, y, color
	virtual bool DrawPoint(unsigned, double, double, Color, bool) = 0;
	// id, x1, y1, x2, y2, color
	virtual bool DrawSegment(unsigned, double, double, double, double, Color, bool) = 0;
	// id, x, y, r, color
	virtual bool DrawCircle(unsigned, double, double, double, Color, bool) = 0;
	virtual bool Clear() = 0;

	virtual bool Set_properties_of_point(unsigned, double, double, Color = 0) = 0;
	virtual bool Set_properties_of_segment(unsigned, double, double, double, double, Color = 0) = 0;
	virtual bool Set_properties_of_circle(unsigned, double, double, double, Color = 0) = 0;
	virtual void Clear_properties() = 0;

	virtual void WriteError(const char* Text) = 0;
	virtual void WriteText(const char* Short, const char* Long) = 0;

	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, CONSTR_TYPE, double) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE) = 0;
	virtual bool WriteRule(unsigned, unsigned, unsigned, unsigned, CONSTR_TYPE, double) = 0;
	virtual bool ClearRules() = 0;

	virtual void UpdateWorkStatus(unsigned) = 0;
	virtual void WorkStatusDone() = 0;
};

#endif
