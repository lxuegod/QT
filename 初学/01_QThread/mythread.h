#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    //QThread 的虚函数
    //线程处理函数
    //不能直接调用，通过start的间接调用
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
