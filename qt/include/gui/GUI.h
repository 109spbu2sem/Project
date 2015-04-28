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
    Q_PROPERTY(QVariant statusBar READ statusBar WRITE setStatusBar NOTIFY statusBarChanged)

public:
     GUI(QObject *parent = 0){}
    ~GUI(){}

public slots:
    const QVariant statusBar();
    void setStatusBar(const QVariant &String);

    const Point newPoint();
    void setNewPoint(double x, double y);
    void addNewPoint(double x, double y);
    void addNewSection(double a_x, double a_y, double b_x, double b_y);

    signals:
    void statusBarChanged();
    void newPointAdded(QVariant x, QVariant y);
    void newSectionAdded(QVariant a_x, QVariant a_y, QVariant b_x, QVariant b_y);

private:
    QVariant _statusBar;
    Point _newPoint;
};


#endif /* defined(__Project_2Sem__GUI__) */
