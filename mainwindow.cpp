#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "storages.h"
#include "objectpropertieswindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonChange_clicked()
{
	objectPropertiesWindow *ow = new objectPropertiesWindow(this);
	ow->show();
}

void MainWindow::on_buttonAdd_clicked()
{
	objectPropertiesWindow *ow = new objectPropertiesWindow(this);
	ow->show();
}
