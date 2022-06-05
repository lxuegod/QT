#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QRadioButton>
#include <QListWidgetItem>
#include <QListWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮   男默认按钮
    ui->rBtnMan->setChecked(true);

    //设置单选按钮   未婚默认按钮
    ui->rUnM->setChecked(true);

    //选中女后  打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
           qDebug()<<"选中女了！";
    });

    //选中男后  打印信息
    connect(ui->rBtnMan,&QRadioButton::clicked,[=](){
           qDebug()<<"选中男了！";
    });

    //选中已婚后  打印信息
    connect(ui->rM,&QRadioButton::clicked,[=](){
           qDebug()<<"选中已婚了！";
    });

    //选中未婚后  打印信息
    connect(ui->rUnM,&QRadioButton::clicked,[=](){
           qDebug()<<"选中未婚了！";
    });

    //多选按钮  2是选中  0是未选中
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });



    //利用listWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    //将一行诗放入到listWidget控件中
//    ui->listWidget->addItem(item );
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList   QList<QString>
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下锄"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);



}

Widget::~Widget()
{
    delete ui;
}

