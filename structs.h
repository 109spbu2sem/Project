struct Point
{
	double x;
	double y;
};
class DynArray
{
private:
	Point *_points;
public:
	unsigned _size;
	DynArray(void);
	//���������� ���������
	void store(Point);
	//�������� �������
	Point get(int num);
	//delete elem
	void drop(int num);
};