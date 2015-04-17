//
//  GUI.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "./include/gui/GUI.h"
#include <QQmlApplicationEngine>

const QString GUI::statusBar()
{
    return _statusBar;
}

void GUI::setStatusBar(const QString &statusBarText)
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

void GUI::setNewPoint(Point P)
{
    _newPoint = P;

    emit newPointChanged();
}
