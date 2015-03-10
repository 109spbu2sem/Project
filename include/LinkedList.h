//
//  LinkedList.h
//  Project_2Sem
//
//  Created by Никита Попов on 03.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Storage_Template.h"
#include "Storage.h"

//  Список
class LinkedList
{
    struct Cell
    {
        Point Data;
        Cell *Next;
    };
    Cell *_FirstCell;
    Cell *_LastCell;
    Cell *_CurrentCell;
    unsigned _Size;
    
public:
    //  Создание списка
    LinkedList()
    {
        _FirstCell = 0;
        _LastCell = 0;
        _CurrentCell = 0;
        _Size = 0;
    };
    
    //  Добавление элемента
    void Add(const Point&);
    
    //  Получение доступа по номеру элемента
    Point &operator[] (unsigned num);
    
    //  Узнать кол-во элементов
    unsigned Size() const
    {
        return _Size;
    };

    
    Point & GetCurrent()
    {
        if (_CurrentCell)
            return _CurrentCell -> Data;
        else return _FirstCell -> Data;  //  ??
    };  //
    void MoveNext()
    {
        if (_CurrentCell -> Next)
            _CurrentCell = _CurrentCell -> Next;
    };  //  Перемещение к следующему хранилищу
    void Rewind()
    {
        _CurrentCell = _FirstCell;
    };  //  Возвращает текущий элемент
    bool CanMoveNext()
    {
        if (_CurrentCell -> Next)
            return true;
        return false;
    };


private:
    
};

#endif