#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *ev)
{
    switch(ev->key()){
    case Qt::Key_0:
        qDebug()<<"按下了0";
        qDebug()<<QString("Qt::Key_0");
        break;
    default:
        break;
    }
}
