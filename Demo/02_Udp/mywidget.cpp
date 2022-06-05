#include "mywidget.h"
#include "ui_mywidget.h"
#include <QUdpSocket>
#include <QHostAddress>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //指定父对象 分配空间
    udpSocket = new QUdpSocket(this);
    //绑定端口
    udpSocket->bind(QHostAddress::AnyIPv4,6666);
    //设置窗口
    setWindowTitle("端口为：6666");
    move(500,500);
    connect(udpSocket,&QUdpSocket::readyRead,this,&MyWidget::dealMsg);
}

void MyWidget::dealMsg()
{
    //获取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;
    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0)  //如果读到内容
    {
        //格式化
        QString str = QString("[%1:%2] %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        //获取编辑区的内容
        ui->textEditRead->append(str);
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_btnSend_clicked()
{
    //获取对方的ip和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();
    //获取编辑区的内容
    QString str = ui->textEditWrite->toPlainText();
    //给指定的ip发送信息
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
    //把自己写读的内容追加到显示区
    QHostAddress ip2 = udpSocket->peerAddress();
    qint16 port2 = 6666;
    QString str2 = QString("[%1:%2] %3").arg(ip2.toIPv4Address()).arg(port2).arg(str);
    ui->textEditRead->append(str2);
    //清空编辑区的内容
    ui->textEditWrite->clear();
}

void MyWidget::on_btnClose_clicked()
{
    //主动和对方断开连接
    udpSocket->disconnectFromHost();
    udpSocket->close();
    //this->close();
}
