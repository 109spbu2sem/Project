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
#include "./include/core/Structures.h"
#include "./include/core/LinkedList_Template.h"

class GUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString statusBar READ statusBar WRITE setStatusBar NOTIFY statusBarChanged)
    Q_PROPERTY(Point newPoint READ newPoint WRITE setNewPoint NOTIFY newPointChanged)

public:
     GUI(){}
    ~GUI(){}

public slots:
    const QString statusBar();
    void setStatusBar(const QString &String);

    const Point newPoint();
    void setNewPoint(Point P);

    signals:
    void statusBarChanged();
    void newPointChanged();

private:
    QString _statusBar;
    Point _newPoint;
};


#endif /* defined(__Project_2Sem__GUI__) */
