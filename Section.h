struct section {
	double x1, x2, y1, y2;
};
class DynArray
{
public:
	DynArray();
	//Add element
	void add(section);
	//Get element
	section get(int num);
	//Delete element
	void del(int num);
	//Value
	void value(int num1, int num2);
	//Size
	int size();
private:
	section*_sections;
	int _size;
};

