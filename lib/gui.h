#ifndef GUI_H
#define GUI_H


class GUI
{
public:
	GUI();
	~GUI();
	void Draw(double point_x, double point_y);//Point
	void Draw(double point_x, double point_y, double vector_x, double vector_y);//Segment
	void Draw(double point_x, double point_y, double vector_x, double vector_y, double radius);//Arc
	void WriteError(unsigned ErrorKey);
};

#endif // GUI_H
