//
//  GUI.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "./include/gui/GUI.h"
#include <QQmlApplicationEngine>
#include <iostream>

const QVariant GUI::statusBar()
{
    return _statusBar;
}

void GUI::setStatusBar(const QVariant &statusBarText)
{
    if (statusBarText != _statusBar)
    {
        _statusBar = statusBarText;
        emit statusBarChanged();
    }
}

const Point GUI::newPoint()
{
    return _newPoint;
}

void GUI::setNewPoint(double x, double y)
{
    Point P;
    P.X = x;
    P.Y = y;
    _newPoint = P;
    std::cout << "x = " << P.X << std::endl << "y = " << P.Y << std::endl;
}

void GUI::addNewPoint(double x, double y)
{
    emit newPointAdded(x, y);
}

const Segment GUI::newSegment()
{
    return _newSegment;
}

void GUI::setNewSegment(double a_x, double a_y, double b_x, double b_y)
{
    Segment S;
    S.A.X = a_x;
    S.A.Y = a_y;
    S.B.X = b_x;
    S.B.Y = b_y;
    _newSegment = S;
    std::cout << "x1 = " << S.A.X << std::endl << "y1 = " << S.A.Y << std::endl << "x2 = " << S.B.X << std::endl << "y2 = " << S.B.Y << std::endl;
}

void GUI::addNewSegment(double a_x, double a_y, double b_x, double b_y)
{
    emit newSegmentAdded(a_x, a_y, b_x, b_y);
}
