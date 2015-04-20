#ifndef GUI_H
#define GUI_H

#include "core.h"

class CORE;

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

	void show();

   void Draw(double point_x, double point_y, unsigned color = 0); // Point
   void Draw(double point1_x, double point1_y, double point2_x, double point2_y, unsigned color = 0); // Segment
   void Draw(double point_x, double point_y, double radius, unsigned color = 0); // Circle
	// void Draw(double point_x, double point_y, double vector_x, double vector_y, double radius);//Arc
	void WriteError(unsigned ErrorKey);
};

#endif // GUI_H
