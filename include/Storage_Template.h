//
//  Storage_Template.h
//  Project_2Sem
//
//  Created by Никита Попов on 10.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef _Storage_Template_h
#define _Storage_Template_h

template<typename Item> class Storage_Template
{
private:
    Item *_Items;
    unsigned _Size;
    
public:
    //  Создание хранилища
    Storage_Template(void)
    {
        _Items = 0;
        _Size = 0;
    };
    
    //  Удаление хранилища
    ~Storage_Template(void)
    {
        if (_Items) delete[] _Items;
    };
    
    //  Добавление элемента (Item)
    void Add(Item);
    
    Item& operator[] (int num);
    
    //  Получить элемент
    Item Get(int num);
    
    //  Изменить элемент
    void Set(int num, Item P);
    
    Item *Value(int i);
    Item &RefValue(int i);
    
    //  Изменение координат
    //  void ChangeCorrdinates;
    
    //  Удалить элемент
    void Drop(int num);
    
    //  Узнать кол-во элементов
    unsigned Size()const
    {
        return _Size;
    };
};

//  Добавление элемента
template<typename Item> void Storage_Template<Item>::Add(Item P)
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

template<typename Item> Item& Storage_Template<Item>::operator[] (int num)
{
    if (num >= _Size)
        throw std::invalid_argument("> Bad array index");
    return _Items[num];
}

//  Удаление элемента
template<typename Item> void Storage_Template<Item>::Drop(int num)
{
    
}

//  Получение элемента
template<typename Item> Item Storage_Template<Item>::Get(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Items[num];
}

//  Изменение элемента | его значение
template<typename Item> Item *Storage_Template<Item>::Value(int num)
{
    if ((num >= _Size) || (num < 0)) throw std::invalid_argument("> Bad array index");
    return _Items + num;
}

#endif