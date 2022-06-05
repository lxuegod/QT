#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>  //UDP通信套接字

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void dealMsg();  //槽函数

private slots:
    void on_btnSend_clicked();

    void on_btnClose_clicked();

    void on_btnRoom_clicked();

private:
    Ui::Widget *ui;

    QUdpSocket * udpSocket;  //UDP通信套接字
};

#endif // WIDGET_H
