#ifndef STORAGES_H  // с которым работаю 
#define STORAGES_H

struct Point
{
	double x;
	double y;
};
struct Segment
{
	Point o; //begin
	Point d; //direction
};
//points
class storagepoints
{
private:
	Point *_points;
	unsigned _size;
public:
	//constructor
	storagepoints(void)
	{
		_points = 0;
		_size = 0;
	};
	//destructor
	~storagepoints(void)
	{
		delete[] _points;
	};
	///we can work with storage as an array
	Point& operator[] (unsigned num);
	///add elem
	void add(Point);
	//get _size
	unsigned size() const
	{
		return _size;
	}
};
//segments
class storagesegments
{
private:
	Segment *_segments;
	unsigned _size;
public:
	//constructor
	storagesegments(void)
	{
		*_segments;
		_size = 0;
	};
	//destructor
	~storagesegments(void)
	{
		delete[] _segments;
	};
	///we can work with storage as an array
	Segment& operator[] (unsigned num);
	///add elem
	void add(Segment);
	//get _size
	unsigned size() const
	{
		return _size;
	}
};
#endif