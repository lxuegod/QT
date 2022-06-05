#include "clianwidget.h"
#include "ui_clianwidget.h"
#include <QHostAddress>

ClianWidget::ClianWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClianWidget)
{
    ui->setupUi(this);

    //窗口设置
    this->setWindowTitle("客户端");
    this->move(1200,600);


    tcpSocket = NULL;

    //分配空间，指定父对象
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->textEditRead->setText("成功和服务器建立连接");
    });

    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        //获取对方发送的内容
        QByteArray array = tcpSocket->readAll();
        //追加到编辑器中
        ui->textEditRead->append(array);
    });

}

ClianWidget::~ClianWidget()
{
    delete ui;
}

void ClianWidget::on_pushButtonConnect_clicked()
{
    //获取服务器ip和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void ClianWidget::on_btn_send_clicked()
{
    //获取编辑框内容
    QString str = ui->textEditWrite->toPlainText();
    //发送数据
    tcpSocket->write(str.toUtf8().data());
    //删除发送的数据
    ui->textEditWrite->clear();

}

void ClianWidget::on_btn_close_clicked()
{
    //主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}
