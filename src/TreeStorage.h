//
//  TreeStorage.h
//  Project_2Sem
//
//  Created by Никита Попов on 17.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef __Project_2Sem__TreeStorage__
#define __Project_2Sem__TreeStorage__

#include <stdio.h>
#include <iostream>
#include <stdexcept>

template<typename Type1, typename Type2> class Tree_Storage
{
    struct Cell
    {
        Type1 A;
        Type2 B;
        
        Cell *Left;
        Cell *Right;
    };
    
    Cell *_Root;     //  Корень
    Cell *_Current;  //  Нынешняя ячейка
    
    int  Height(Cell*);      //  Высота дерева
    int  HeightDiff(Cell*);  //  Разница по высоте левой и правой "ветвей"
    void RotCCW(Cell*);      //  Поворот по часовой стрелке [1]
    void RotCCW2(Cell*);     //  Поворот по часовой стрелке [2]
    
public:
    //  Constructor
    Tree_Storage()
    {
        _Root    = 0;
        _Current = 0;
    };
    
    //  Destructor
    ~Tree_Storage()
    {
             _Current = _Root;
        Cell * Parent = _Current;
        while (Parent)
        {
            while (_Current -> Left)
            {
                Parent   = _Current;
                _Current = _Current -> Left;
            }
            while (_Current -> Right)
            {
                Parent   = _Current;
                _Current = _Current -> Right;
            }
            if (!(_Current -> Left) && !(_Current -> Right))
            {
                if (Parent -> Left == _Current)
                {
                    delete [] _Current;
                    Parent -> Left = 0;
                }
                else
                {
                    delete [] _Current;
                    Parent -> Right = 0;
                }
                if (_Current == _Root)
                {
                    break;
                }
                _Current = _Root;
            }
        }
        
    };
    
    //  Add element to the tree
    void Add(const Type1& A, const Type2& B)
    {
        if (_Root == 0)
        {
            _Root = new Cell;
            _Root -> A = A;
            _Root -> B = B;
            _Root -> Left = _Root -> Right = 0;
        }
        else
        {
            Cell *NewCell = new Cell;
            NewCell -> A = A;
            NewCell -> B = B;
            NewCell -> Left = 0;
            NewCell -> Right = 0;
            
            Cell *Current = _Root;
            Cell *Parent = 0;
            
            while (Current)
            {
                if (Current -> A == A)
                {
                    Parent = Current;
                    Current -> B = B;
                    return;
                }
                if (Current -> A < B)
                {
                    Parent = Current;
                    Current = Current -> Right;
                }
                else
                {
                    Parent = Current;
                    Current = Current -> Left;
                }
            }
            if (Parent -> A < A)
                Parent -> Right = NewCell;
            else Parent -> Left = NewCell;
        }
    };
    
    //  Is A in the tree?
    bool HasA(const Type1& A)
    {
        Cell *Current = _Root;
        while (Current)
        {
            if (Current -> A == A) return true;
            if (Current -> A <  A)
                Current = Current -> Right;
            else
                Current = Current -> Left;
        }
        return 0;
    };
    
    //  What B w/ this A?
    Type2& GetBbyA(const Type1& A)
    {
        _Current = _Root;
        while (_Current)
        {
            if (_Current -> A == A)
            {
                return _Current -> B;
            }
            
            if (_Current -> A <  A)
            {
                _Current = _Current -> Right;
            }
            else
            {
                _Current = _Current -> Left;
            }
        }
    };
};


//  Height of the tree
template <typename Type1, typename Type2> int Tree_Storage<Type1, Type2>::Height(Cell* C)
{
    if (C == 0)
    {
        return 0;
    }
    
    return (1 + max(Height(C -> Left), Height(C -> Right)));
};

//  Difference in height between Left and Right
template <typename Type1, typename Type2> int Tree_Storage<Type1, Type2>::HeightDiff(Cell* C)
{
    if (C == 0)
    {
        return 0;
    }
    
    return (Height(C -> Left) - Height(C -> Right));
};

//  Rotate the tree [1]
template <typename Type1, typename Type2> void Tree_Storage<Type1, Type2>::RotCCW(Cell* C)
{

};

//  Rotate the tree [2]
template <typename Type1, typename Type2> void Tree_Storage<Type1, Type2>::RotCCW2(Cell* C)
{
    
};

#endif /* defined(__Project_2Sem__TreeStorage__) */
