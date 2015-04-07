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
#include "GUI.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Scene>("scene.module", 1, 0, "Scene");

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

    QSurfaceFormat surfaceFormat = window -> requestedFormat();
    window -> setFormat(surfaceFormat);
    window -> show();

    rc = app.exec();

    delete component;

    return rc;
}
