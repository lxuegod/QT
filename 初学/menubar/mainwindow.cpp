#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    QMenu * fileMenu = bar->addMenu("文件");
    fileMenu->addAction("新建");

    this->setWindowIcon(QIcon(":/Imag/10.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
