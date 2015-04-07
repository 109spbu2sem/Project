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

class Scene : public QObject
{
    Q_OBJECT

public:
    Scene();

    ~Scene();

public slots:
    void requestPaint(Point &P);
    QString changeStatusBar(QString String);

    signals:
    void sceneChanged();
    void statusBarChanged();

private:

};

class GUI
{
    QQmlApplicationEngine engine;

public:
    GUI()
    {
        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    }
    
    ~GUI()
    {
        //delete &engine;
    }
    
    Q_INVOKABLE void Draw(Point &P)
    {
        int xpos = P.X;
        int ypos = P.Y;
        //QObject mainCanvas.requestPaint();
    }
    
//    Q_INVOKABLE void Draw(Segment &S)
//    {
        
//    }
    
//    Q_INVOKABLE void Draw(Arc &A)
//    {
        
//    }
    
//    Q_INVOKABLE void WriteError(unsigned int ErrorKey)
//    {
        
//    }
};

#endif /* defined(__Project_2Sem__GUI__) */
