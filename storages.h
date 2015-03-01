#ifndef STORAGES
#define STORAGES

struct Point
{
	double x;
	double y;
};
struct Segment
{
	Point o;//begin
	Point d;//direction
};
//points
class storagePoints
{
private:
	Point *_points;
	unsigned _size;
public:
	//constructor
	storagePoints(void)
	{
		_points = 0;
		_size = 0;
	}
	//destructor
	~storagePoints(void)
	{
		delete[] _points;
	}
	//we can work with storage as an array
	Point& operator[] (unsigned num);
	//add elem
	void add(Point);
	//get _size
	unsigned size() const
	{
		return _size;
	}
};
//segments
class storageSegments
{
private:
	Segment *_segments;
	unsigned _size;
public:
	//constructor
	storageSegments(void)
	{
		*_segments;
		_size = 0;
	}
	//destructor
	~storageSegments(void)
	{
		delete[] _segments;
	}
	//we can work with storage as an array
	Segment& operator[] (unsigned num);
	//add elem
	void add(Segment);
	//get _size
	unsigned size() const
	{
		return _size;
	}
};
//class for all objects
struct storeOfObjects
{
	//points
	storagePoints points;
	storageSegments segments;
};
#endif //STORAGES
