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
	//  Создание хранилища
	DynArrayPoint(void);

	//  Добавление элемента (точка)
	void Store(Point);

	//  Получить элемент
	Point Get(int num);
	//  Изменить элемент
	void Set(int num, Point P);
	Point *Value(int i);
	//  Удалить элемент
	void Drop(int num);

	//  Узнать кол-во элементов
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
	//Изменить элемент
	void Set(int num, Sect S);
	//получить адрес элемента
	Sect *Value(int num);
	//delete
	void Drop(int num);
	//узнать кол-во элементов массива
	unsigned Size(){
		return _Size;
	}


private:
	Sect *_Sections;
	unsigned _Size;
};

