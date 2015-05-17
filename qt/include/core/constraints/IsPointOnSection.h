//
//  IsPointOnSegment.h
//  Project_2Sem
//
//  Created by Никита Попов on 31.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef Project_2Sem_IsPointOnSegment_h
#define Project_2Sem_IsPointOnSegment_h

#include <cmath>

class IConstraint             //  Ограничение
{
public:
    virtual double Error() = 0;            //  Ошибка
    virtual double Diff(double *Par) = 0;  //  Массив частных производной по тем параметрам, которые используются в формуле
};

double Length(double X1, double Y1, double X2, double Y2)
{
    return sqrt(pow((X1 - X2), 2) + pow((Y1 - Y2), 2));
}

class IsPointOnSegment: public IConstraint
{
private:
    Point   *P;
    Segment *S;
    
public:
    IsPointOnSegment(Point & P1, Segment & S1)
    {
        P = P1;
        S = S1;
    };
    virtual double Error()
    {
        double Error = Length(S.A.X, S.A.Y, P.X, P.Y) + Length(S.B.X, S.B.Y, P.X, P.Y) - Length(S.A.X, S.A.Y, S.B.X, S.B.Y);  //  Length between two Points A and B of Segment S == summ of Lengths between Point P and Points A and B of Segment S => Point P is on Segment S
        
        return  Error * Error;
    };
    virtual double Diff(double *Par)
    {
        if (Par == P.X)   return (((P.X + S.B.X) / fabs((P.X + S.B.X))) + ((P.X + S.A.X)   / fabs((P.X + S.A.X))));
        if (Par == P.Y)   return (((P.Y + S.B.Y) / fabs((P.Y + S.B.Y))) + ((P.Y + S.A.Y)   / fabs((P.Y + S.A.Y))));
        if (Par == S.A.X) return (((S.A.X + P.X) / fabs((S.A.X + P.X))) - ((S.A.X + S.A.Y) / fabs((S.A.X + S.A.Y))));
        if (Par == S.A.Y) return (((S.A.Y + P.Y) / fabs((S.A.Y + P.Y))) - ((S.A.X + S.A.Y) / fabs((S.A.X + S.A.Y))));
        if (Par == S.B.X) return (((S.B.X + P.X) / fabs((S.B.X + P.X))) - ((S.B.X + S.B.Y) / fabs((S.B.X + S.B.Y))));
        if (Par == S.B.Y) return (((S.B.Y + P.Y) / fabs((S.B.Y + P.Y))) - ((S.B.X + S.B.Y) / fabs((S.B.X + S.B.Y))));
            return 0;
    };
};

#endif
