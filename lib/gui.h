#ifndef GUI_H
#define GUI_H


class GUI
{
private:
	CORE* mycore;

public:
	GUI(CORE* core)
	{
		mycore = core;
	}
	GUI();
	~GUI();
	void ConnectCORE(CORE* core)
	{
		mycore = core;
	}
	void Draw(double point_x, double point_y); // Point
	void Draw(double point1_x, double point1_y, double point2_x, double point2_y); // Segment
	void Draw(double point_x, double point_y, double radius); // Circle
	// void Draw(double point_x, double point_y, double vector_x, double vector_y, double radius);//Arc
	void WriteError(unsigned ErrorKey);
};

#endif // GUI_H
