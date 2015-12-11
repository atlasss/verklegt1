#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dbMain.open();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    dbMain.close();
    delete ui;
}
