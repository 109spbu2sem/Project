struct Point {
	double x;
	double y;
};
class DynArray
{
public:
	DynArray();
	void store(Point);
	Point get(int num);
	Point back();
	int size();
	void del(int num);
private:
	Point*_points;
	unsigned _size;
};

