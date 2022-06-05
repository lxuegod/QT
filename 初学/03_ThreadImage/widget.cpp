#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QThread>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //自定义类对象 分配空间  不能指定父对象
    myT = new MyThread;
    //创建子线程
    thread = new QThread(this);
    //把自定义模块添加到子线程
    myT->moveToThread(thread);

    //启动子线程  但是并没有启动线程处理函数
    thread->start();

    //线程处理函数必须使用 signal - slot调用
    connect(ui->btn,&QPushButton::pressed,myT,&MyThread::drawImage);
    connect(myT,&MyThread::updateImage,this,&Widget::getImage);

    connect(this,&Widget::destroyed,this,&Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getImage(QImage temp)
{
    image = temp;
    update();  //更新窗口，间接调用painEvent()
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);//创建画家，指定绘图设备为窗口
    p.drawImage(50,50,image);
}

void Widget::dealClose()
{
    //退出子线程
    thread->quit();
    //回收资源
    thread->wait();
    delete myT;
}
