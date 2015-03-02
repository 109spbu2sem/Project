//
//  DynArrayS.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 01.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "DynArray.h"
#include <stdexcept>

//  Создание хранилища
DynArrayS::DynArrayS(void)
{
    _Sections = 0;
    _Size = 0;
}

//  Добавление элемента
void DynArrayS::Store(Section S)
{
    if (_Sections == 0)
    {
        _Sections = new Section;
        (*_Sections).X1 = S.X1;
        (*_Sections).Y1 = S.Y1;
        (*_Sections).X2 = S.X2;
        (*_Sections).Y2 = S.Y2;
        _Size++;
    }
    else
    {
        Section *NewSections = new Section[_Size + 1];
        
        //  Копируем старые элементы в новый массив
        for (unsigned s = 0; s < _Size; ++s)
        {
            NewSections[s] = _Sections[s];
        }
        
        //  Добавляем новый
        NewSections[_Size] = S;
        
        //  Освобождаем занимаемую старыми элементами память
        delete[] _Sections;
        
        //  Копируем обратно
        _Sections = NewSections;
        _Size++;
    }
}

//  Удаление элемента
void DynArrayS::Drop(int num)
{
    
}

//  Получение элемента
Section DynArrayS::Get(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Sections[num];
}

//  Изменение элемента | его значение
Section *DynArrayS::Value(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Sections + num;
}