#include "gui.h"
#include "global.h"
#include <iostream>

GUI::GUI()
{
	
}

GUI::~GUI()
{
	
}

void help()
{
	std::cout << "'e' - exit, close program" << std::endl;
	std::cout << "'a' - add to the canvas\n\t 'p' - point\n\t 's' - segment\n\t 'c' - circle" << std::endl;
	std::cout << "'s' - select object in position" << std::endl;
	std::cout << "'c' - clear selection" << std::endl;
	std::cout << "'w' - work, calculate true position of objects on the canvas" << std::endl;
	std::cout << "'r' - rule, add rule (constraint) to selected objects" << std::endl;
	std::cout << "'b' - brush, clear screen" << std::endl;
	std::cout << "'l' - list, show list of\n\t 'o' - objects (doesn't work)\n\t 's' - selected objects (doesn't work)" << std::endl;
	std::cout << "'h' - help, show this text again" << std::endl;
}

void GUI::show()
{
	help();
	while (true)
	{
		char letter;
		std::cout << "\n=";
		std::cin >> letter;
		switch (letter)
		{
		case 'e':
			return;
		case 'h':
		{
			help();
			break;
		}
		case 'c':
		{
			mycore->ClearSelection();
			break;
		}
		case 's':
		{
			double x, y;
			std::cout << "x: ";
			std::cin >> x;
			std::cout << "y: ";
			std::cin >> y;
			mycore->Select(x, y);
			break;
		}
		case 'r':
		{
			char key;
			std::cout << "a - point to point distance\nb - point to line distance\nc - three points on the line\n" <<
							 "d - angle(radian) between lines\ne - point to segment distance" << std::endl;
			std::cout << "key: ";
			std::cin >> key;
			switch (key)
			{
			case 'a':
			{
				double v;
				std::cout << "value: ";
				std::cin >> v;
				mycore->AddRule(CONSTR_P2PDIST, v);
				break;
			}
			case 'b':
			{
				double v;
				std::cout << "value: ";
				std::cin >> v;
				mycore->AddRule(CONSTR_P2LINEDIST, v);
				break;
			}
			case 'c':
			{
				mycore->AddRule(CONSTR_3PONLINE);
				break;
			}
			case 'd':
			{
				double v;
				std::cout << "value: ";
				std::cin >> v;
				mycore->AddRule(CONSTR_L2LANGLE, v);
				break;
			}
			case 'e':
			{
				double v;
				std::cout << "value: ";
				std::cin >> v;
				mycore->AddRule(CONSTR_P2SECTDIST, v);
				break;
			}
			default:
			{
				std::cout << "wrong parameter" << std::endl;
				break;
			}
			}
			break;
		}
		case 'a':
		{
			char key;
			std::cin >> key;
			switch (key)
			{
			case 'p':
			{
				double x, y;
				std::cout << "x: ";
				std::cin >> x;
				std::cout << "y: ";
				std::cin >> y;
				mycore->AddObject(x, y);
				break;
			}
			case 's':
			{
				double x1, y1, x2, y2;
				std::cout << "x1: ";
				std::cin >> x1;
				std::cout << "y1: ";
				std::cin >> y1;
				std::cout << "x2: ";
				std::cin >> x2;
				std::cout << "y2: ";
				std::cin >> y2;
				mycore->AddObject(x1, y1, x2, y2);
				break;
			}
			case 'c':
			{
				double x, y, r;
				std::cout << "x: ";
				std::cin >> x;
				std::cout << "y: ";
				std::cin >> y;
				std::cout << "r: ";
				std::cin >> r;
				mycore->AddObject(x, y, r);
				break;
			}
			default:
			{
				std::cout << "wrong parameter" << std::endl;
				break;
			}
			}
			break;
		}
		case 'b':
		{
			system("cls");
			break;
		}
		case 'w':
		{
			std::cout << std::endl;
			mycore->Calculate();
			break;
		}
		case 'l':
		{
			break;
		}
		default:
		{
			std::cout << "wrong parameter" << std::endl;
			break;
		}
		}
	}
	mycore->Calculate();
	return;
}

void GUI::Draw(double point_x, double point_y, unsigned color)
{
   std::cout << "(P) ";
	std::cout << point_x << "\t" << point_y;
   if (color) std::cout << "\t(s)";
   std::cout << std::endl;
}

void GUI::Draw(double point1_x, double point1_y, double point2_x, double point2_y, unsigned color)
{
   std::cout << "(S) ";
	std::cout << point1_x << "\t" << point1_y << "\t" << point2_x << "\t" << point2_y << "\t";
   if (color) std::cout << "\t(s)";
   std::cout << std::endl;
}

void GUI::Draw(double point_x, double point_y, double radius, unsigned color)
{
   std::cout << "(C) ";
	std::cout << point_x << "\t" << point_y << "\t" << radius;
   if (color) std::cout << "\t(s)";
   std::cout << std::endl;
}

bool GUI::Redraw()
{
	if (mycore->StreamIsOpened()) return false;
	mycore->OpenStream();

	for (unsigned i = 0; i < points_amount; i++)
	{
		std::cout << "(P) ";
		std::cout << mycore->GetFromStream() << "\t" << mycore->GetFromStream();
		if (mycore->GetFromStream()) std::cout << "\t(s)";
		std::cout << std::endl;
	}

	mycore->CloseStream();
	return true;
}