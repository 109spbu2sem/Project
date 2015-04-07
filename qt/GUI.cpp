//
//  GUI.cpp
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#include "GUI.h"
#include <QQmlApplicationEngine>

QString Scene::changeStatusBar(QString String)
{
    emit statusBarChanged();

    return String;
}
