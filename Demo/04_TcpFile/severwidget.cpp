#include "severwidget.h"
#include "ui_severwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QTimer>


SeverWidget::SeverWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeverWidget)
{
    ui->setupUi(this);

    //监听套接字
    tcpSever = new QTcpServer(this);

    //监听
    tcpSever->listen(QHostAddress::Any,6666);
    setWindowTitle("服务器端口为：6666");

    //两个按钮都不能按
    ui->btnSelect->setEnabled(false);
    ui->btnSend->setEnabled(false);

    //如果客户端成功和客户端连接
    //tcpSever会自动触发  newConnection()
    connect(tcpSever,&QTcpServer::newConnection,[=](){
        //取出建立好的套接字
        tcpSocket = tcpSever->nextPendingConnection();
        //获取对方的ip和端口
        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();

        QString str = QString("[%1:%2]  连接成功").arg(ip).arg(port);
        ui->textEditRead->setText(str);  //显示到编辑区

        //成功连接后 才能选择文件
        ui->btnSelect->setEnabled(true);


    });


    connect(&timer,&QTimer::timeout,[=](){
        //关闭定时器
        timer.stop();

        //发送文件
        sendData();

    });



}

SeverWidget::~SeverWidget()
{
    delete ui;
}

//选择文件的按钮
void SeverWidget::on_btnSelect_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");
    if(false == filePath.isEmpty())   //如果选择文件路径有效
    {
        fileName.clear();
        fileSize = 0;

        //获取文件信息
        QFileInfo info(filePath);
        fileName = info.fileName(); //获取文件名字
        fileSize = info.size();  //获取文件大小

        sendSize = 0;//发送文件大小

        //只读方式打开文件
        //指定文件的名字
        file.setFileName(filePath);

        //打开文件
        bool isOk = file.open(QIODevice::ReadOnly);
        if(false == isOk)
        {
            qDebug()<<"只读方式打开按钮失败  86";
        }
        //提示打开文件的路径
        ui->textEditRead->append(filePath);

        ui->btnSelect->setEnabled(false);
        ui->btnSend->setEnabled(true);


    }
    else
    {
        qDebug()<<"选择文件出错 98";
    }


}

//发送文件按钮
void SeverWidget::on_btnSend_clicked()
{
    //发送文件头部的信息  文件名##文件大小
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    //发送头部信息
    qint64 len = tcpSocket->write(head.toUtf8());
    if(len>0)  //头部信息发送成功
    {
        //发送真正的信息
        //防止TCP黏包文件
        //需要通过定时器延时 20 ms
        timer.start(20);
    }
    else
    {
        qDebug()<<"头部信息发送失败  120";
        file.close();
        ui->btnSelect->setEnabled(true);
        ui->btnSend->setEnabled(false);
    }



}

void SeverWidget::sendData()
{
    qint64 len = 0;
    do
    {
        //每次发送数据的大小
        char buf[4*1024] = {0};
        len = 0;

        //往文件中读数据
        len = file.read(buf,sizeof(buf));
        //发送数据，读多少，发多少
        len = tcpSocket->write(buf,len);

        //发送的数据需要累加
        //sendSize += len;

    }while(len > 0);

    //是否发送文件完毕
    if(sendSize ==fileSize)
    {
        ui->textEditRead->append("文件发送完毕");
        file.close();

        //把客户端断开
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }


}
