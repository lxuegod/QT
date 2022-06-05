#ifndef CLIANWIDGET_H
#define CLIANWIDGET_H

#include <QWidget>
#include <QTcpSocket>  //通信套接字
#include <QFile>

namespace Ui {
class clianwidget;
}

class clianwidget : public QWidget
{
    Q_OBJECT

public:
    explicit clianwidget(QWidget *parent = 0);
    ~clianwidget();

private slots:
    void on_btnConnect_clicked();


private:
    Ui::clianwidget *ui;

    QTcpSocket * tcpSocket;

    QFile file;  //文件对象
    QString fileName; //文件名字
    qint64 fileSize;//文件大小
    qint64 recvSize;//已经接收文件大小

    bool isStart;
};

#endif // CLIANWIDGET_H
