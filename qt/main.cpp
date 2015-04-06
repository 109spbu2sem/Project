#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GUI ui;

    return app.exec();
}
