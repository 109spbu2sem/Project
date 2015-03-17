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

template<typename A, typename B> class Tree_Storage
{
    struct Cell
    {
        A a;
        B b;
        
        Cell *Left;
        Cell *Right;
    };
    Cell *_Root;  //  Корень
    
public:
    Tree_Storage()
    {
        _Root = 0;
    };
    ~Tree_Storage()
    {
        
    };
    
    void Add(const A& a, const B& b)
    {
        if (_Root == 0)
        {
            _Root = new Cell;
            _Root -> a = a;
            _Root -> b = b;
            _Root -> Left = _Root -> Right = 0;
        }
        else
        {
            Cell *NewCell = new Cell;
            NewCell -> a = a;
            NewCell -> b = b;
            NewCell -> Left = 0;
            NewCell -> Right = 0;
            
            Cell *Current = _Root;
            Cell *Parent = 0;
            
            while (Current)
            {
                if (Current -> a == a)
                {
                    Parent = Current;
                    Current -> b = b;
                }
                if (Current -> a < a)
                    Current = Current -> Right;
                else
                    Current = Current -> Left;
            }
            if (Parent -> a < a)
                Parent -> Right = NewCell;
            else Parent -> Left = NewCell;
        }
    };
    
    bool HasA(const A& a)
    {
        Cell *Current = _Root;
        while (!Current)
        {
            if (Current -> a == a) return true;
            if (Current -> a < a)
                Current = Current -> Right;
            else
                Current = Current -> Left;
        }
        throw 1;
    };
    
    B& GetBbyA(const A& a);
};

#endif /* defined(__Project_2Sem__TreeStorage__) */
