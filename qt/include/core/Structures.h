//
//  Structures.h
//  Project_2Sem
//
//  Created by Никита Попов on 13.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Point    //  Точка
{
    double X;
    double Y;
};

struct Segment  //  Отрезок
{
    Point A;  //  Начальная точка
    Point B;  //  Конечная точка
};

struct Vector2  //  Вектор
{
    double X, Y;
    Vector2(double _X, double _Y):X(_X), Y(_Y){};
    
    //  Сложение векторов
    /*
     Vector2 Sum(const Vector2& V)
     {
     Vector2 V_Res(X,Y);
     V_Res.X += V.X;
     V_Res.Y += V.Y;
     return V_Res;
     };
     */
    Vector2 operator +(const Vector2 &V)
    {
        Vector2 V_Res(X,Y);
        V_Res.X += V.X;
        V_Res.Y += V.Y;
        return V_Res;
    };
    
    //  Умножение вектора на число
    Vector2 operator *(const double &A)
    {
        Vector2 V_Res(X,Y);
        V_Res.X *= A;
        V_Res.Y *= A;
        return V_Res;
    };
};

//==============================================
//==============================================
//==============================================

//struct Angle    //  Угол
//{
//    double Value;
//    
//private:
//    Angle()
//    {
//        Value = 0;
//    }
//    double Grads();
//};
//
//struct Arc      //  Дуга
//{
//public:
//    Point P;
//    Vector2 V;
//    Angle Angle;
//    
//    Arc()
//    {
//        P.X = 0;
//        P.Y = 0;
//        V = { 0, 0 };
//        Angle = 0;
//    };
//    
//    Arc(Point &P1, Vector2 &V1, Angle &Angle1)
//    {
//        P = P1;
//        V = V1;
//        Angle = Angle1;
//    };
//    double Length();
//    double Area();
//    Section Chord();
//};

#endif
