#ifndef SEVERWIDGET_H
#define SEVERWIDGET_H

#include <QWidget>
#include <QTcpServer>  //监听套接字
#include <QTcpSocket>  //通信套接字
#include <QFile>
#include <QTimer>

namespace Ui {
class SeverWidget;
}

class SeverWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SeverWidget(QWidget *parent = 0);
    ~SeverWidget();

    void sendData();  //发送文件数据

private slots:
    void on_btnSelect_clicked();

    void on_btnSend_clicked();

private:
    Ui::SeverWidget *ui;

    QTcpServer * tcpSever;//监听套接字
    QTcpSocket * tcpSocket;//通信套接字

    QFile file;  //文件对象
    QString fileName; //文件名字
    qint64 fileSize;//文件大小
    qint64 sendSize;//已经发送文件大小

    QTimer timer; //定时器


};

#endif // SEVERWIDGET_H
