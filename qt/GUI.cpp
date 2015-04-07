//
//  GUI.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "GUI.h"
#include <QQmlApplicationEngine>

QString Scene::statusBar()
{
    return _statusBar;
}

void Scene::setStatusBar(const QString statusBarText)
{
    if (!(_statusBar == statusBarText))
    {
        _statusBar = statusBarText;
        emit statusBarChanged();
    }
}
