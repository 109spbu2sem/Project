//
//  LinkedList_Template.h
//  Project_2Sem
//
//  Created by Никита Попов on 10.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef _LinkedList_Template_h
#define _LinkedList_Template_h

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
    
    
    Item & GetCurrent()
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