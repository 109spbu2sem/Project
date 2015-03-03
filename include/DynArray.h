//
//  DynArray.h
//  Project_2Sem
//
//  Created by Никита Попов on 24.02.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

struct Point    //  Точка
{
    double X;
    double Y;
};

/*
struct Section  //  Отрезок
{
    //  Координаты начала
    double X1;
    double Y1;
    //  Координаты конца
    double X2;
    double Y2;

};
*/

struct Section
{
    Point A;  //  Начальная точка
    Point B;  //  Конечная точка
};

struct Arc      //  Дуга
{

};


//  Массив точек
class DynArrayP
{
public:
    //  Создание хранилища
    DynArrayP(void);
    
    //  Добавление элемента (точка)
    void Store(Point);
    
    Point& operator[] (int num);
    
    //  Получить элемент
    Point Get(int num);
    
    //  Изменить элемент
    void Set(int num, Point P);
    
    Point *Value(int i);
    Point &RefValue(int i);
    
    //  Изменение координат
    //  void ChangeCorrdinates;
    
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

//  Массив отрезков
class DynArrayS
{
public:
    //  Создание хранилища
    DynArrayS(void);
    
    //  Добавление элемента (отрезок)
    void Store(Section);
    
    //  Получить элемент
    Section Get(int num);
    
    //  Изменить элемент
    void Set(int num, Section S);
    
    Section *Value(int i);
    Section &RefValue(int i);
    
    //  Изменение координат
    Section *ChangeCoordinate(int num, unsigned Flag);
    
    //  Удалить элемент
    void Drop(int num);
    
    //  Узнать кол-во элементов
    unsigned Size()const
    {
        return _Size;
    };
    
private:
    Section *_Sections;
    unsigned _Size;
};