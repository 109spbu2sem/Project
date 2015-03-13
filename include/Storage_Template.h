//
//  Storage_Template.h
//  Project_2Sem
//
//  Created by Никита Попов on 10.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef STORAGE_TEMPLATE_H
#define STORAGE_TEMPLATE_H

template<typename Item> class Storage
{
private:
    Item *_Items;
    unsigned _Size;
    
public:
    //  Создание хранилища
    //  Constructor
    Storage(void)
    {
        _Items = 0;
        _Size = 0;
    };
    
    //  Copying constructor
    Storage(const Storage &S)
    {
        _Items = 0;
        _Size = S._Size;
        if(_Size)
        {
            _Items = new Item[S.Size()];
            for (unsigned k = 0; k < S._Size; ++k)
            {
                _Items[k] = S._Items[k];
            }
        }
    };
    
    //  Удаление хранилища
    //  Destructor
    ~Storage(void)
    {
        if (_Items) delete[] _Items;
    };
    
    //  Добавление элемента (Item)
    void Add(Item);
    
    Item& operator[] (int num);
    
    //  Создание копий хранилища
    void operator= (const Storage &S);
    
    //  Получить элемент
    Item Get(int num);
    
    //  Изменить элемент
    void Set(int num, Item P);
    
    Item *Value(int i);
    Item &RefValue(int i);
    
    //  Удалить элемент
    void Drop(int num);
    
    //  Узнать кол-во элементов
    unsigned Size()const
    {
        return _Size;
    };
};

//  Добавление элемента
template<typename Item> void Storage<Item>::Add(Item P)
{
    if (_Items == 0)
    {
        _Items = new Item(P);
        _Size++;
    }
    else
    {
        Item *NewItems = new Item[_Size + 1];
        
        //  Копируем старые элементы в новый массив
        for (unsigned s = 0; s < _Size; ++s)
        {
            NewItems[s] = _Items[s];
        }
        
        //  Добавляем новый
        NewItems[_Size] = P;
        
        //  Освобождаем занимаемую старыми элементами память
        delete[] _Items;
        
        //  Копируем обратно
        _Items = NewItems;
        _Size++;
    }
}

template<typename Item> Item& Storage<Item>::operator[] (int num)
{
    if (num >= _Size)
        throw std::invalid_argument("> Bad array index");
    return _Items[num];
}

//  Копирование хранилища
template<typename Item> void Storage<Item>::operator= (const Storage &S)
{
    if(_Items) delete[] _Items;
    _Items = new Item[S.Size()];
    for (unsigned k = 0; k < S._Size; ++k)
    {
        _Items[k] = S._Items[k];
    }
    _Size = S._Size;
};

//  Удаление элемента
template<typename Item> void Storage<Item>::Drop(int num)
{
    
}

//  Получение элемента
template<typename Item> Item Storage<Item>::Get(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Items[num];
}

//  Изменение элемента | его значение
template<typename Item> Item *Storage<Item>::Value(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Items + num;
}

#endif