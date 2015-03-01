#include <math.h>

struct Point
{
	double X;
	double Y;
};
struct Sect
{
	Point A;
	Point B;
	double len = sqrt((A.X - B.X)*(A.X - B.X) + (A.Y - B.Y)*(A.Y - B.Y));
};

class DynArrayPoint
{
public:
	//  �������� ���������
	DynArrayPoint(void);

	//  ���������� �������� (�����)
	void Store(Point);

	//  �������� �������
	Point Get(int num);
	//  �������� �������
	void Set(int num, Point P);
	Point *Value(int i);
	//  ������� �������
	void Drop(int num);

	//  ������ ���-�� ���������
	unsigned Size()const
	{
		return _Size;
	};

private:
	Point *_Points;
	unsigned _Size;
};

class DynArraySect
{
public:
	//Create dyn array
	DynArraySect(void);
	//Add section
	void Store(Sect S);
	//get section
	Sect Get(int num);
	//�������� �������
	void Set(int num, Sect S);
	//�������� ����� ��������
	Sect *Value(int num);
	//delete
	void Drop(int num);
	//������ ���-�� ��������� �������
	unsigned Size(){
		return _Size;
	}


private:
	Sect *_Sections;
	unsigned _Size;
};

