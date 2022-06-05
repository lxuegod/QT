#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //重写绘图事件
    void paintEvent(QPaintEvent *);
    void getImage(QImage); //槽函数
    void dealClose();  //关闭窗口槽函数

private:
    Ui::Widget *ui;

    QImage image;
    MyThread * myT;  //自定义线程
    QThread * thread;  //子线程
};

#endif // WIDGET_H
