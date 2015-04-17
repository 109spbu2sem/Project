//
//  LinkedList.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 03.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "./include/core/Structures.h"
#include "./include/core/LinkedList.h"

void LinkedList::Add(const Point &P)
{
    if (_FirstCell == 0)
    {
        _FirstCell = new Cell;
        _FirstCell -> Data = P;
        _FirstCell -> Next = 0;
        _LastCell = _FirstCell;
    }
    else
    {
        Cell *NewCell = new Cell;
        NewCell -> Data = P;
        NewCell -> Next = 0;
        
        //  Связываем с предыдущей ячейкой
        _LastCell -> Next = NewCell;
        _LastCell = NewCell;
    }
    ++_Size;
};

Point &LinkedList::operator[] (unsigned num)
{
    if (num >= _Size)
        throw std::invalid_argument("> Bad array index");
    Cell *Current = _FirstCell;
    unsigned Counter = 0;
    while (++Counter != num && Current && Current -> Next)
    {
        Current = Current -> Next;
    }
    return Current -> Data;
};
