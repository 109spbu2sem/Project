#ifndef GUI_H
#define GUI_H


class GUI
{
public:
	GUI();
	~GUI();
	void Draw(Point &point);
	void Draw(Segment &segment);
	void Draw(Arc &arc);
	void WriteError(unsigned ErrorKey);
};

#endif // GUI_H
