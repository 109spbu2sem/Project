//
//  GUI.h
//  Project_2Sem
//
//  Created by Никита Попов on 02.04.15.
//  Copyright (c) 2015 Никита Попов. All rights reserved.
//

#ifndef __Project_2Sem__GUI__
#define __Project_2Sem__GUI__

//  C++
#include <stdio.h>
//  QT
#include <QQmlApplicationEngine>
#include <QObject>
//  Custom
#include "Structures.h"

class GUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString statusBar READ statusBar WRITE setStatusBar NOTIFY statusBarChanged)
    //  Q_PROPERTY(Point mousePosition READ mousePosition WRITE setMousePosition NOTIFY mousePositionChanged)

public:
    Scene(){}

    ~Scene(){}

public slots:
    void requestPaint(Point &P){}

    QString statusBar();
    void setStatusBar(const QString String);

    signals:
    void statusBarChanged();

private:
    QString _statusBar;

};


#endif /* defined(__Project_2Sem__GUI__) */
