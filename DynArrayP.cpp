//
//  DynArrayP.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 24.02.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "DynArray.h"
#include <stdexcept>

//  Создание хранилища
DynArrayP::DynArrayP(void)
{
    _Points = 0;
    _Size = 0;
}

//  Добавление элемента
void DynArrayP::Store(Point P)
{
    if (_Points == 0)
    {
        _Points = new Point;
        (*_Points).X = P.X;
        (*_Points).Y = P.Y;
        _Size++;
        //  _Points ->
    }
    else
    {
        Point *NewPoints = new Point[_Size + 1];
        
        //  Копируем старые элементы в новый массив
        for (unsigned s = 0; s < _Size; ++s)
        {
            NewPoints[s] = _Points[s];
        }
        
        //  Добавляем новый
            //  NewPoints[_Size] = P; - Равносильно
        NewPoints[_Size].X = P.X;
        NewPoints[_Size].Y = P.Y;
        
        //  Освобождаем занимаемую старыми элементами память
        delete[] _Points;
        
        //  Копируем обратно
        _Points = NewPoints;
        _Size++;
    }
}

//  Удаление элемента
void DynArrayP::Drop(int num)
{
    
}

//  Получение элемента
Point DynArrayP::Get(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Points[num];
}

//  Изменение элемента | его значение
Point *DynArrayP::Value(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Points + num;
}