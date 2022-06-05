#include "widget.h"
#include "ui_widget.h"
#include "dialoglist.h"


//Widget::Widget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::Widget)
//{
//    ui->setupUi(this);
//}

//Widget::~Widget()
//{
//    delete ui;
//}



Widget::Widget(QWidget *parent,QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->backBtn,&QToolButton::clicked,[=](){

        this->close();

    });

//    connect(ui->SetBtn,&QToolButton::clicked,[=](){

//    });

}


void Widget::closeEvent(QCloseEvent *event)
{
    emit this->closeWidget();
    this->close();
}



Widget::~Widget()
{
    delete ui;
}
