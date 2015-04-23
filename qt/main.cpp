#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QDebug>
#include <QQmlContext>
#include <QQuickItem>
#include <QObject>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlEngine>
#include <QMetaObject>
#include "./include/gui/GUI.h"
#include "./src/gui/GUI.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<GUI>("gui.module", 1, 0, "GUI");
    GUI gui;
    //CORE core;
    //core.ConnectGUI(gui);


    int rc = 0;

    QQmlEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);

    QObject::connect(&engine, SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));
    component -> loadUrl(QUrl("main.qml"));

    if (!component -> isReady() )
    {
        qWarning("%s", qPrintable(component -> errorString()));
        return -1;
    }

    QObject *topLevel = component -> create();
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QObject::connect(window, SIGNAL(newPointAdded(double, double)), &gui, SLOT(setNewPoint(double, double)));
    QObject::connect(&gui,   SIGNAL(newPointAdded(QVariant, QVariant)), window, SLOT(addNewPoint(QVariant, QVariant)));

    QSurfaceFormat surfaceFormat = window -> requestedFormat();
    window -> setFormat(surfaceFormat);
    window -> show();

    //------------------

    Point P;
    P.X = 200;
    P.Y = 200;
    gui.addNewPoint(P.X, P.Y);

    //------------------

    rc = app.exec();

    delete component;

    return rc;
}
