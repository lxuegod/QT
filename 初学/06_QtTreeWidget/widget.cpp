#include "widget.h"
#include "ui_widget.h"
#include <QStringList>
#include <QTreeWidgetItem>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //重置窗口大小
    this->resize(1000,800);

    //treeWidget树控件使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    //追加子节点
    QStringList heroL1;
    heroL1<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成客观的范围输出";
    QTreeWidgetItem * l1 = new QTreeWidgetItem(heroL1);
    liItem ->addChild(l1);




}

Widget::~Widget()
{
    delete ui;
}

