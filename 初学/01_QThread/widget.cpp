#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //指定父对象 分配空间
    myTimer = new QTimer(this);

    //只要定时器启动  自动触发timerout
    connect(myTimer,&QTimer::timeout,this,&Widget::dealTimeout);

    //指定父对象  分配空间
    thread = new MyThread(this);

    connect(thread,&MyThread::isDone,this,&Widget::dealDone);

    //当按窗口左上角x时  自动触发timeout
    connect(thread,&MyThread::destroyed,this,&Widget::stopThread);


}

void Widget::stopThread()
{
    thread->quit();
    //等待线程处理完手头东西
    thread->wait();
}

void Widget::dealDone()
{
    qDebug()<<"it is over ";
    myTimer->stop();
}

void Widget::dealTimeout()
{
    static int i = 0;
    i++;
    //设置lcd的值
    ui->lcdNumber->display(i);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //如果定时器没有工作
    if(myTimer->isActive() == false)
    {
        myTimer->start(100);
    }

    //启动线程，处理数据
    thread->start();


}

void Widget::on_pushButton_2_clicked()
{
    myTimer->stop();
}
