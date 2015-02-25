//
//  DynArray.h
//  Project_2Sem
//
//  Created by Никита Попов on 24.02.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

struct Point
{
    double X;
    double Y;
};

class DynArray
{
public:
    //  Создание хранилища
    DynArray(void);
    
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