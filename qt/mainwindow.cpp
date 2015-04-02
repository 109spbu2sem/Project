#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //  Add main.qml
    ui = new QQuickView;
    ui -> setSource(QUrl("qrc:/main.qml"));
    setCentralWidget(ui);
    ui -> setResizeMode(QQuickView::SizeRootObjectToView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
