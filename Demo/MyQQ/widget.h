#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //explicit Widget(QWidget *parent = 0);


    explicit Widget(QWidget * parent,QString name);

    //关闭窗口会触发关闭事件
    void closeEvent(QCloseEvent *);


    ~Widget();

signals:
    //关闭窗口发送关闭信息
    void closeWidget();


private:
    Ui::Widget *ui;


};

#endif // WIDGET_H
