//
//  LinkedList.h
//  Project_2Sem
//
//  Created by Никита Попов on 03.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//  Список
class LinkedList
{
private:
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
            if (_CurrentCell && _CurrentCell -> Next)
                return true;
            return false;
        };
    };
    
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
    
    Viewer GetStartingViewer()
    {
        Viewer V(*this);
        return V;
    };
};

#endif