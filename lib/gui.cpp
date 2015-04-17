#include "gui.h"
#include <iostream>

GUI::GUI()
{
	
}

GUI::~GUI()
{
	
}

void GUI::start()
{
	while (true)
	{
	double x,y;
	std::cin >> x;
	std::cin >> y;
	if (!x && !y) break;
	mycore->AddObject(x, y);
	}
	mycore->Calculate();
	return;
}

void GUI::Draw(double point_x, double point_y)
{
	std::cout << point_x << "\t" << point_y << std::endl;
}

void GUI::Draw(double point1_x, double point1_y, double point2_x, double point2_y)
{
	std::cout << point1_x << "\t" << point1_y << "\t" << point2_x << "\t" << point2_y << "\t" << std::endl;
}

void GUI::Draw(double point_x, double point_y, double radius)
{
	std::cout << point_x << "\t" << point_y << "\t" << radius << std::endl;
}