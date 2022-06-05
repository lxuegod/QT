#include "clianwidget.h"
#include "ui_clianwidget.h"
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>

clianwidget::clianwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clianwidget)
{
    ui->setupUi(this);

    //窗口设置
    setWindowTitle("客户端");
    move(200,600);

    //指定父对象  分配空间
    tcpSocket = new QTcpSocket(this);

    isStart = true;

    //设置进度条为0
    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(recvSize/1024);

    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        //取出接收的内容
         QByteArray buf = tcpSocket->readAll();
        if(true == isStart)
        {
            //接收头
            isStart = false;
//            //解析头部信息
//            QString str = "hello##1024#mike";
//            str.section("##",0,0);

            //初始化
            fileName = QString(buf).section("##",0,0);
            fileSize = QString(buf).section("##",1,1).toInt();
            recvSize = 0;  //已经接收文件大小

            //打开文件
            file.setFileName(fileName);



            bool isOk = file.open(QIODevice::WriteOnly);
            if(false == isOk)
            {
                qDebug()<<"WriteOnly erroe 44";
            }

        }
        else  //文件信息
        {
            qint64 len = file.write(buf);
            recvSize += len;

            if(recvSize == fileSize)   //文件接收完毕
            {
                file.close();
                QMessageBox::information(this,"完成","文件接收完成");

                //断开连接
                tcpSocket->disconnectFromHost();
                tcpSocket->close();   //关闭套接字
           }

        }



    });
}

clianwidget::~clianwidget()
{
    delete ui;
}

void clianwidget::on_btnConnect_clicked()
{
    //获取服务器ip和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //主动与服务器连接
    tcpSocket->connectToHost(QHostAddress(ip),port);


}

