#include "mythread.h"
#include <QThread>
#include <QDebug>

myThread::myThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void myThread::myTimeout()
{
    while(isStop == false)
    {
        QThread::sleep(1);
        emit mySignal();

        qDebug()<<"子线程号:"<<QThread::currentThread();

        if(true ==isStop)
        {
            break;
        }
    }
}

void myThread::setFlag(bool flag)
{
    isStop = flag;
}
