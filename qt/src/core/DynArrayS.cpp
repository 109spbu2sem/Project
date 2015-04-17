//
//  DynArrayS.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 01.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include <iostream>
#include "./include/core/Structures.h"
#include "./include/core/Storage.h"
#include <stdexcept>

//  Создание хранилища
DynArrayS::DynArrayS(void)
{
    _Sections = 0;
    _Size = 0;
}

//  Добавление элемента
void DynArrayS::Add(Section S)
{
    if (_Sections == 0)
    {
        _Sections = new Section;
        (*_Sections).A.X = S.A.X;
        (*_Sections).A.Y = S.A.Y;
        (*_Sections).B.X = S.B.X;
        (*_Sections).B.Y = S.B.Y;
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

//  Изменение координат
//Section *DynArrayS::ChangeCoordinate(int num, unsigned Flag)
//{
//    switch (Flag)
//    {
//        case 1:
//            return (_Sections + num).A.X;
//            break;
//        case 2:
//            return (_Sections + num).A.Y;
//            break;
//        case 3:
//            return (_Sections + num).B.X;
//            break;
//        case 4:
//            return (_Sections + num).B.Y;
//            break;
//            
//        default:
//            std::cout << "Введен неверный флаг:\n"
//                      << "1 - X1\n"
//                      << "2 - Y1\n"
//                      << "3 - X2\n"
//                      << "4 - Y2\n"
//                      << std::endl;
//            break;
//    }
//}
