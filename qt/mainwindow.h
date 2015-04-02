#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuick/QQuickView>
#include <QGraphicsObject>
#include <QtGui>

namespace UI
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QQuickView *ui;
};

#endif // MAINWINDOW_H
