#ifndef CORE_H
#define CORE_H
#include "structures.h"
#include "storage_array.h"
#include "storage_list.h"

class CORE
{
private:
	Storage_Array<double> _storage_of_coordinates;
	Storage_Array<Point> _storage_of_points;
	Storage_Array<Segment> _storage_of_segments;
	Storage_Array<Circle> _storage_of_circles;
public:
	CORE();
	~CORE();
	void AddObject(double point_x, double point_y); // add point
	void AddObject(double point_x1, double point_y1, double point_x2, double point_y2); // add segment, automatical adds 2 points
	void AddObject(double point_x, double point_y, double radius); //add circle, automatical add center of circle
	void AddObject(double point_x, double point_y, double vector_x, double vector_y, double angle);
	/*void AddRule(Point &point_1, Point &point_2, unsigned rule, ...);
	void AddRule(Point &point, Segment &segment, unsigned rule, ...);
	void AddRule(Segment &segment_1, Segment &segment_2, unsigned rule, ...);
	void AddRule(Segment &segment, Arc &arc, unsigned rule, ...);*/
	void ChangeStatus(double x, double y, unsigned char status_key);
	void ChangeStatus(double x1, double y1, double x2, double y2, unsigned char status_key);
	void ChangeProperty(unsigned property_key, ...);
};

#endif // CORE_H
