#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostAddress>
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QHostAddress ABC = QHostAddress::LocalHost;

    //qDebug()<<ABC.toString();
    //指定父对象  分配空间
    udpSocket = new QUdpSocket(this);

    //绑定
    udpSocket->bind(QHostAddress::AnyIPv4,8888);
    //设置窗口
    setWindowTitle("端口号：8888");

    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);
}

void Widget::dealMsg()
{
    //读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr;  //对方的地址
    quint16 port;//对方的端口
    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0)  //读到内容
    {
        //格式化
        QString str = QString("[%1:%2] %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        //给编辑区写内容
        ui->textEditRead->append(str);

    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnSend_clicked()
{
    //获取对方的ip和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();
    //获取编辑区的内容
    QString str = ui->textEditWrite->toPlainText();
    //给指定的ip发送数据
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
    //把自己写读的内容追加到显示区
    //QHostAddress ip2 = QHostAddress::LocalHost;
    QHostAddress ip2 = udpSocket->peerAddress();
    qint16 port2 = 8888;
    QString str2 = QString("[%1:%2] %3").arg(ip2.toString()).arg(port2).arg(str);
    ui->textEditRead->append(str2);
    //清空发送完的编辑区
    ui->textEditWrite->clear();

}

void Widget::on_btnClose_clicked()
{
    //主动和对方断开连接
    udpSocket->disconnectFromHost();
    udpSocket->close();
    //this->close();
}

void Widget::on_btnRoom_clicked()
{
    ui->lineEditIp->setText("255.255.255.255");
    //加入某个组播
    //组播地址是D类地址
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    //退出组播
    //udpSocket->leaveMulticastGroup();
}
