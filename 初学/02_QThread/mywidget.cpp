#include "mywidget.h"
#include "ui_mywidget.h"
#include <QThread>
#include <QDebug>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //动态分配空间  不能指定父对象
    myT = new myThread;

    //创建子线程
    thread = new QThread(this);

    //把我自定义的线程加入到子线程中
    myT->moveToThread(thread);

    connect(myT,&myThread::mySignal,this,&myWidget::dealSingnal);

    qDebug()<<"主线程号:"<<QThread::currentThread();

    connect(this,&myWidget::startThread,myT,&myThread::myTimeout);

    connect(this,&myWidget::destroyed,this,&myWidget::dealClose);

    //线程处理函数内部不允许操作图形界面  只能进行数据处理

    //connect()第五个函数作用 连接方式：默认，队列，直接
    //多线程时候才有意义
    //默认的时候
    //如果是多线程 默认使用队列方式
    //如果是单线程 默认使用直接方式
    //队列：槽函数所在的线程和接收者一样
    //直接：参函数所在的线程和发送者一样
}

void myWidget::dealSingnal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void myWidget::dealClose()
{
   on_btnStop_clicked();
   delete myT;
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::on_btnStart_clicked()
{
    if(thread->isRunning() == true)
    {
        return;
    }
    //启动线程 但是没用启动线程处理函数
    thread->start();
    myT->setFlag(false);

    //不能自接调用线程处理函数
    //直接调用，导致，线程处理函数和主线程是在同一个线程
    //myT->myTimeout();

    //只能用 signal - slot 的方式调用
    emit startThread();
}

void myWidget::on_btnStop_clicked()
{
    if(thread->isRunning() == false)
    {
        return;
    }
    myT->setFlag(true);
    thread->quit();
    thread->wait();

}
