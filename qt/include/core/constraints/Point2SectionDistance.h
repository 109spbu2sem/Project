//
//  Point2SectionDistance.h
//  Project_2Sem
//
//  Created by Никита Попов on 31.03.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef Project_2Sem_Point2SectionDistance_h
#define Project_2Sem_Point2SectionDistance_h

class IConstraint             //  Ограничение
{
public:
    virtual double Error() = 0;            //  Ошибка
    virtual double Diff(double *Par) = 0;  //  Массив частных производной по тем параметрам, которые используются в формул
};

class Point2SectionDistance: public IConstraint
{
    Point P;
    Section S;
    double *Dist;
public:
    Point2SectionDistance(Point & P, Section & S, double *Dist);
    virtual double Error()
    {
        double Error = (sqrt(pow((S.A.X - P.X), 2) + pow((S.A.Y - P.Y), 2)) + (sqrt(pow((S.B.X - P.X), 2) + pow((S.B.Y - P.Y), 2)))) - sqrt(pow((S.A.X - S.B.X), 2) + pow((S.A.Y - S.B.Y), 2));
        
        return  Error * Error;
    }
    virtual double Diff(double *Par)
    {
        //  if (*Par == P1)
        return 0;
    }
};

#endif
