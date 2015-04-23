//
//  LinkedList_Template.h
//  Project_2Sem
//
//  Created by Никита Попов on 10.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef LINKEDLIST_TEMPLATE_H
#define LINKEDLIST_TEMPLATE_H

#include <stdexcept>
#include <iostream>
#include "./include/gui/GUI.h"

template<typename Item> class LinkedList
{
    struct Cell
    {
        Item Data;
        Cell *Next;
    };
    Cell *_FirstCell;
    Cell *_LastCell;
    Cell *_CurrentCell;
    unsigned _Size;
    
public:
    class Viewer
    {
    private:
        LinkedList::Cell *_CurrentCell;
        LinkedList *_Parent;
        
    public:
        Viewer()
        {
            _CurrentCell = 0;
        };
        
        Viewer(LinkedList &L)
        {
            _CurrentCell = L._FirstCell;
            _Parent = &L;
        };
        
        Point& GetValue()
        {
            if (_CurrentCell)
                return _CurrentCell -> Data;
            else throw std::runtime_error("> There is no such point");
        };
        
        void MoveNext()
        {
            if (_CurrentCell)
                _CurrentCell = _CurrentCell -> Next;
        };  //  Перемещение к следующему хранилищу
        
        void Rewind()
        {
            _CurrentCell = _Parent -> _FirstCell;
        };  //  Возвращает текущий элемент
        
        bool CanMoveNext()
        {
            if (_CurrentCell)
                return true;
            return false;
        };
    };
    
    //  Создание списка
    //  Constructor
    LinkedList(void)
    {
        _FirstCell = 0;
        _LastCell = 0;
        _CurrentCell = 0;
        _Size = 0;
    };
    
    //  Copying constructor
    LinkedList(const LinkedList &L)
    {
        if(_FirstCell)
        {
            _CurrentCell = _FirstCell;
            do
            {
                Cell *CC = _CurrentCell -> Next;
                delete _CurrentCell;
                _CurrentCell = CC;
            }
            while (_CurrentCell);
        }
        //  ??
    };
    
    //  Удаление списка
    //  Destructor
    ~LinkedList(void)
    {
        if(_FirstCell)
        {
            _CurrentCell = _FirstCell;
            do
            {
                Cell *CC = _CurrentCell -> Next;
                delete _CurrentCell;
                _CurrentCell = CC;
            }
            while (_CurrentCell);
        }
    };
    
    //  Добавление элемента
    void Add(const Item&);
    
    //  Получение доступа по номеру элемента
    Item &operator[] (unsigned num);
    
    //  Создание копий хранилища
    void operator= (const LinkedList &L);
    
    //  Узнать кол-во элементов
    unsigned Size() const
    {
        return _Size;
    };
    
    Viewer GetStartingViewer()
    {
        Viewer V(*this);
        return V;
    };
    
private:

};

template<typename Item> void LinkedList<Item>::Add(const Item &P)
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

template<typename Item> Item &LinkedList<Item>::operator[] (unsigned num)
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

//  Копирование списка
template<typename Item> void LinkedList<Item>::operator= (const LinkedList &L)
{
    if(_FirstCell)
    {
        _CurrentCell = _FirstCell;
        do
        {
            Cell *CC = _CurrentCell -> Next;
            delete _CurrentCell;
            _CurrentCell = CC;
        }
        while (_CurrentCell);
    }
    //  ??
};

#endif
