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
	//Size
	int size();
private:
	section*_sections;
	int _size;
};
