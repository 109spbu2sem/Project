//
//  main.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 24.02.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "DynArray.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //---------------------------------------------------------
    //------------------------  ТОЧКИ  ------------------------
    //---------------------------------------------------------
    Point P;
    unsigned n = 2;
    DynArrayP StorageP;  //  Массив точек
    unsigned AnsP[2];
    AnsP[0] = 0;
    AnsP[1] = 1;
    
    cout << "Чтобы прекратить вводить координаты введите 00" << endl;
    
    //  Первые две точки обязательны
    cout << endl
         << "Заполняем массив точек\n"
         << "----------------------\n"
         << "Введите координату X: ";
    cin >> P.X;
    cout << "                   Y: ";
    cin >> P.Y;
    cout << endl;
    StorageP.Store(P);
    cout << "Введите координату X: ";
    cin >> P.X;
    cout << "                   Y: ";
    cin >> P.Y;
    StorageP.Store(P);
    cout << endl;
    
    //  Через цикл получаем остальные
    while (true)
    {
        cout << "Введите координату X: ";
        cin >> P.X;
        if (P.X == 00)
        {
            cout << "-- Конец ввода точек --" << endl << endl;
            break;
        }
        cout << "                   Y: ";
        cin >> P.Y;
        cout << endl;
        
        StorageP.Store(P);
        
        ++n;
    }
    
    
    //---------------------------------------------------------
    //-----------------------  ОТРЕЗКИ  -----------------------
    //---------------------------------------------------------
    Section S;
    unsigned m = 2;
    DynArrayS StorageS;  //  Массив отрезков
    unsigned AnsS[2];
    AnsS[0] = 0;
    AnsS[1] = 1;
    
    cout << "Чтобы прекратить вводить координаты введите 00" << endl;
    
    //  Первые два отрезка обязательны
    cout << endl
         << "Заполняем массив отрезков\n"
         << "-------------------------\n"
         << "Введите координату X1: ";
    cin >> S.X1;
    cout << "                   Y1: ";
    cin >> S.Y1;
    cout << "                   X2: ";
    cin >> S.X2;
    cout << "                   Y2: ";
    cin >> S.Y2;
    cout << endl;
    StorageS.Store(S);
    cout << "Введите координату X1: ";
    cin >> S.X1;
    cout << "                   Y1: ";
    cin >> S.Y1;
    cout << "                   X2: ";
    cin >> S.X2;
    cout << "                   Y2: ";
    cin >> S.Y2;
    cout << endl;
    StorageS.Store(S);
    cout << endl;
    
    //  Через цикл получаем остальные
    while (true)
    {
        cout << "Введите координату X1: ";
        cin >> S.X1;
        if (S.X1 == 00)
        {
            cout << "-- Конец ввода отрезков --" << endl << endl;
            break;
        }
        cout << "                   Y1: ";
        cin >> S.Y1;
        cout << "                   X2: ";
        cin >> S.X2;
        cout << "                   Y2: ";
        cin >> S.Y2;
        cout << endl;
        
        StorageS.Store(S);
        
        ++m;
    }
    
    //---------------------------------------------------------
    //------------------------ ЗАДАНИЯ ------------------------
    //---------------------------------------------------------
    
    //  1. Найти точки, между которыми наименьшее расстояние, поменять их местами в массиве
    double MinDistance = (sqrt(pow((StorageP.Get(0).X - StorageP.Get(1).X), 2) + pow((StorageP.Get(0).Y - StorageP.Get(1).Y), 2)));
    try
    {
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned k = 1; k < n; ++k)
            {
                if (i != k)
                    if ((sqrt(pow((StorageP.Get(i).X - StorageP.Get(k).X), 2) + pow((StorageP.Get(i).Y - StorageP.Get(k).Y), 2))) < MinDistance)
                    {
                        MinDistance = (sqrt(pow((StorageP.Get(i).X - StorageP.Get(k).X), 2) + pow((StorageP.Get(i).Y - StorageP.Get(k).Y), 2)));
                        AnsP[0] = i;
                        AnsP[1] = k;
                    }
            }
        }
        
        cout << "Min distance: " << MinDistance << endl;
        cout << "1: " << StorageP.Get(AnsP[0]).X << " " << StorageP.Get(AnsP[0]).Y << endl;
        cout << "2: " << StorageP.Get(AnsP[1]).X << " " << StorageP.Get(AnsP[1]).Y << endl << endl;
        
        //  Меняем эти две точки местами
        Point P1 = StorageP.Get(AnsP[0]);
        (*StorageP.Value(AnsP[0])) = (*StorageP.Value(AnsP[1]));
        (*StorageP.Value(AnsP[1])) = P1;
        
        cout << "1: " << StorageP.Get(AnsP[0]).X << " " << StorageP.Get(AnsP[0]).Y << endl;
        cout << "2: " << StorageP.Get(AnsP[1]).X << " " << StorageP.Get(AnsP[1]).Y << endl << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    //---------------------------------------------------------
    
    //  2. Вводим с клавиатуры отрезки + определяем все, ортогональные друг другу
    
    cout << endl;
    return 0;
}