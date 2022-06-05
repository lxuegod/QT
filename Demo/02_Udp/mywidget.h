#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QUdpSocket>  //UDP套接字

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

    void dealMsg();

private slots:
    void on_btnSend_clicked();

    void on_btnClose_clicked();

private:
    Ui::MyWidget *ui;

    QUdpSocket * udpSocket;//UDP套接字
};

#endif // MYWIDGET_H
