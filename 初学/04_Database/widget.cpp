#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印QT支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    //添加MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");  //数据库服务IP
    db.setUserName("root@localhost");  //数据库用户名
    db.setPassword("1234");  //数据库密码
    db.setDatabaseName("info");  //使用哪个数据库

    //打开数据库
    if( ! db.open())
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return ;
    }
}

Widget::~Widget()
{
    delete ui;
}
