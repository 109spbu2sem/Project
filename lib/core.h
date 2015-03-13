#ifndef CORE_H
#define CORE_H


class CORE
{
public:
	CORE();
	~CORE();
	void AddObject(Point &point);
	void AddObject(Segment &segment);
	void AddObject(Arc &arc);
	void AddRule(Point &point_1, Point &point_2, unsigned rule, ...);
	void AddRule(Point &point, Segment &segment, unsigned rule, ...);
	void AddRule(Segment &segment_1, Segment &segment_2, unsigned rule, ...);
	void AddRule(Segment &segment, Arc &arc, unsigned rule, ...);
	void ChangeStatus(double x, double y);
	void ChangeProperty(unsigned property, ...);
};

#endif // CORE_H
