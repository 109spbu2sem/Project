//
//  main.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 24.02.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Structures.h"
//  #include "LinkedList.h"
#include "LinkedList_Template.h"
#include "Storage_Template.h"
#include "TreeStorage.h"

using namespace std;

int main(int argc, const char * argv[])
{
/*
    //---------------------------------------------------------
    //------------------------  ТОЧКИ  ------------------------
    //---------------------------------------------------------

    Point P;
    unsigned n = 2;
    Storage<Point> StorageP;  //  Связанный список точек
    //  DynArrayP StorageP;  //  Массив точек
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
    StorageP.Add(P);
    cout << "Введите координату X: ";
    cin >> P.X;
    cout << "                   Y: ";
    cin >> P.Y;
    StorageP.Add(P);
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
        
        StorageP.Add(P);
        
        ++n;
    }
    
    //---------------------------------------------------------
    //-----------------------  ОТРЕЗКИ  -----------------------
    //---------------------------------------------------------
    Section S;
    unsigned m = 2;
    Storage<Section> StorageS;  //  Массив отрезков
    unsigned AnsS[2];
    AnsS[0] = 0;
    AnsS[1] = 1;
    
    cout << "Чтобы прекратить вводить координаты введите 00" << endl;
    
    //  Первые два отрезка обязательны
    cout << endl
         << "Заполняем массив отрезков\n"
         << "-------------------------\n"
         << "Введите координату X1: ";
    cin >> S.A.X;
    cout << "                   Y1: ";
    cin >> S.A.Y;
    cout << "                   X2: ";
    cin >> S.B.X;
    cout << "                   Y2: ";
    cin >> S.B.Y;
    cout << endl;
    StorageS.Add(S);
    cout << "Введите координату X1: ";
    cin >> S.A.X;
    cout << "                   Y1: ";
    cin >> S.A.Y;
    cout << "                   X2: ";
    cin >> S.B.X;
    cout << "                   Y2: ";
    cin >> S.B.Y;
    cout << endl;
    StorageS.Add(S);
    cout << endl;
    
    //  Через цикл получаем остальные
    while (true)
    {
        cout << "Введите координату X1: ";
        cin >> S.A.X;
        if (S.A.X == 00)
        {
            cout << "-- Конец ввода отрезков --" << endl << endl;
            break;
        }
        cout << "                   Y1: ";
        cin >> S.A.Y;
        cout << "                   X2: ";
        cin >> S.B.X;
        cout << "                   Y2: ";
        cin >> S.B.Y;
        cout << endl;
        
        StorageS.Add(S);
        
        ++m;
    }
    
    //---------------------------------------------------------
    //------------------------ ВЕКТОРЫ ------------------------
    //---------------------------------------------------------
    Vector2 V1(1, 0);
    Vector2 V2(3, -4);
*/
    
    //---------------------------------------------------------
    //------------------------ ЗАДАНИЯ ------------------------
    //---------------------------------------------------------
/*
    //  1. Найти точки, между которыми наименьшее расстояние, поменять их местами в массиве
    double MinDistance = (sqrt(pow((StorageP.Get(0).X - StorageP.Get(1).X), 2) + pow((StorageP.Get(0).Y - StorageP.Get(1).Y), 2)));
    try
    {
        for (unsigned i = 0; i < n; ++i)
        {
            for (unsigned j = 1; j < n; ++j)
            {
                if (i != j)
                {
                    if ((sqrt(pow((StorageP.Get(i).X - StorageP.Get(j).X), 2) + pow((StorageP.Get(i).Y - StorageP.Get(j).Y), 2))) < MinDistance)
                    {
                        MinDistance = (sqrt(pow((StorageP.Get(i).X - StorageP.Get(j).X), 2) + pow((StorageP.Get(i).Y - StorageP.Get(j).Y), 2)));
                        AnsP[0] = i;
                        AnsP[1] = j;
                    }
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
        cout << e.what() << endl << endl;
    }
    //---------------------------------------------------------
 */

/*
    //  2. Даны две точки и какое-то расстояние. Модифицировать эти точки так, чтобы расстояние между ними стало равным данному.
    double DistanceBetweenTwoPoints;
    
    cout << "Введите новое расстояние между двумя первыми точками: ";
    cin >> DistanceBetweenTwoPoints;
    
    try
    {
        if ((sqrt(pow((StorageP.Get(0).X - StorageP.Get(1).X), 2) + pow((StorageP.Get(0).Y - StorageP.Get(1).Y), 2))) == DistanceBetweenTwoPoints)
        {
            cout << "Расстояние между первыми двумя точками уже равно заданному" << endl;
        }
        else
        {
            //  Модифицируем координаты точки, чтобы изменилось расстояние
            Point ChangeP;
            ChangeP.X = StorageP.Get(1).X;
            ChangeP.Y = StorageP.Get(0).Y + sqrt((DistanceBetweenTwoPoints - StorageP.Get(0).X + StorageP.Get(1).X) * (DistanceBetweenTwoPoints + StorageP.Get(0).X - StorageP.Get(1).X));
            (*StorageP.Value(1)) = ChangeP;
            
            cout << "DistanceBetweenTwoPoints" << sqrt(pow((StorageP.Get(0).X - StorageP.Get(1).X), 2) + pow((StorageP.Get(0).Y - StorageP.Get(1).Y), 2)) << endl;
        }
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl << endl;
    }
 */
 
/*
    //  3. Тесты на уроке
    //  Операции сложения векторов и умножения вектора на число
    Vector2 V3 = V1 + V2;
            V3 = V1.operator+(V2);
 
    Vector2 V4 = V3 * 3;
            V4 = V3.operator*(3);
 
    //  Получение доступа к точке по номеру в массиве
    DynArrayP SP;
    SP.Store(P);
    SP.Store(P);
 
    Point P1 = SP[1];
          P1 = SP.operator[](1);
 
    //---------------------------------------------------------
 */
    
/*
    StorageP.Rewind();
    
    while (StorageP.CanMoveNext())
    {
        cout << StorageP.GetCurrent().X << " " << StorageP.GetCurrent().Y << endl;
        StorageP.MoveNext();
    }
 */
    
/*
    //  4. Вводим с клавиатуры отрезки + определяем все, ортогональные друг другу
        //  Определяем ортогональные отрезки и модифицируем их так, чтобы они стали параллельными
    {
        try
        {
            for (unsigned i = 0; i < m; ++i)
            {
                for (unsigned j = 1; j < m; ++j)
                {
                    if (i != j)
                    {
                        //  Определяем ортогональные отрезки
                        if ((((StorageS.Get(i).A.X - StorageS.Get(i).B.X) - (StorageS.Get(j).A.Y - StorageS.Get(j).B.Y)) == 0) && (((StorageS.Get(j).A.X - StorageS.Get(j).B.X) + (StorageS.Get(i).A.Y - StorageS.Get(i).B.Y) == 0)))
                        {
                            cout << "Отрезок с координатами концов (" << StorageS.Get(i).A.X << ";" << StorageS.Get(i).A.Y << ") и (" << StorageS.Get(i).B.X << ";" << StorageS.Get(i).B.Y  << ") ортогонален отрезку с координатами концов (" << StorageS.Get(j).A.X << ";" << StorageS.Get(j).A.Y << ") и (" << StorageS.Get(j).B.X << ";" << StorageS.Get(j).B.Y  << ")" << endl;
                            
                            //  Модифицируем их так, чтобы они стали параллельными
                            //  Замена местами координат (X1 -> Y2, X2 -> Y1, Y1 -> X1, Y2 -> X2);
                            Section SwapS;
                            SwapS.A.X = StorageS.Get(j).A.Y;
                            SwapS.A.Y = StorageS.Get(j).B.X;
                            SwapS.B.X = StorageS.Get(j).B.Y;
                            SwapS.B.Y = StorageS.Get(j).A.X;
                            (*StorageS.Value(j)) = SwapS;
                            
                            cout << "X1 = " << StorageS.Get(j).A.X
                                 << endl
                                 << "Y1 = " << StorageS.Get(j).A.Y
                                 << endl
                                 << "X2 = " << StorageS.Get(j).B.X
                                 << endl
                                 << "Y2 = " << StorageS.Get(j).B.Y
                                 << endl;
                        }
                    }
                }
            }
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl << endl;
        }
    }
  */
 
/*
    //  Test of LinkedList::Viewer
    Point P;
    P.X = 0;
    P.Y = 0;
    
    LinkedList<Point> LL;
    LL.Add(P);
    LL.Add(P);
    LL.Add(P);
    
    LinkedList<Point>::Viewer LLV(LL);
    LinkedList<Point>::Viewer LLV2(LL);
    LLV2.MoveNext();
    
    while (LLV2.CanMoveNext())
    {
        if (LLV.GetValue().X < LLV2.GetValue().X)
            cout << "Wrong pair" << endl;
        LLV.MoveNext();
        LLV2.MoveNext();
    }
    
    LLV = LL.GetStartingViewer();
    while (LLV.CanMoveNext())
    {
        cout << LLV.GetValue().X << endl;
        LLV.MoveNext();
    }
    
    LLV = LL.GetStartingViewer();
    while (LLV.CanMoveNext())
    {
        LLV.GetValue().X += 2;
        LLV.MoveNext();
    }
    
    LLV = LL.GetStartingViewer();
    while (LLV.CanMoveNext())
    {
        cout << LLV.GetValue().X << endl;
        LLV.MoveNext();
    }
*/
/*
    //  Test TreeStorage
    Tree_Storage<int, int> Tree;
    Tree.Add(0, 0);
    Tree.Add(1, 1);
    Tree.Add(0, 0);
    
    if (Tree.HasA(1))
        cout << "There is 1" << endl;
    else cout << "There is no 1" << endl;
*/    
    cout << endl;
    return 0;
}