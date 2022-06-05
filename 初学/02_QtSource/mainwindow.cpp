#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon());

    //使用添加Qt的资源  ": +前缀名 + 文件名"
    //ui->actionnew->setIcon(QIcon(":/照片/1.png"));
}
MainWindow::~MainWindow()
{
    delete ui;
}

