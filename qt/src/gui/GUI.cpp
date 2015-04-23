//
//  GUI.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "./include/gui/GUI.h"
#include <QQmlApplicationEngine>

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
