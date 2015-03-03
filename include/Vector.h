//
//  Vector.h
//  Project_2Sem
//
//  Created by Никита Попов on 03.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H

struct Vector2
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

#endif