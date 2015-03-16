#ifndef CORE_H
#define CORE_H
#include "structures.h"
#include "storages.h"

class CORE
{
private:
	Storage_Array<Point> _storage_of_points;
	Storage_Array<Segment> _storage_of_segments;
	Storage_Array<Arc> _storage_of_arcs;
public:
	CORE();
	~CORE();
	void AddObject(double point_x, double point_y);
	void AddObject(double point_x, double point_y, double vector_x, double vector_y);
	void AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle);
	/*void AddRule(Point &point_1, Point &point_2, unsigned rule, ...);
	void AddRule(Point &point, Segment &segment, unsigned rule, ...);
	void AddRule(Segment &segment_1, Segment &segment_2, unsigned rule, ...);
	void AddRule(Segment &segment, Arc &arc, unsigned rule, ...);*/
	void ChangeStatus(double x, double y);
	void ChangeStatus(double x1, double y1, double x2, double y2);
	void ChangeProperty(unsigned property_key, ...);
};

#endif // CORE_H
