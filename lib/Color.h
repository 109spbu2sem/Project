#ifndef COLOR_H
#define COLOR_H
class Color
{
private:
	unsigned _color;
public:
	Color();
	~Color();
	void setColor(unsigned long);
	void setColor(unsigned char, unsigned char, unsigned char);
	unsigned getColor(char mode = 0) const;
};

#endif // COLOR_H