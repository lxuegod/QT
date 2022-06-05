#include "mywigdet.h"
#include <qpushbutton.h>  //控制按钮的头文件
#include  "mypushbutton.h"
#include <QDebug>

//命名规范
//类名 首字母大写，单词和单词之间大写
//函数名、变量名称、首字母小写，单词和单词之间首字母大写

//快捷键
//注释  ctrl + /
//运行  ctrl + r
//编译  ctrl + b

//字体的缩放  ctrl + 鼠标滚轮
//查找  ctrl + f
//整行移动  ctrl + shift + ↑或者↓
//帮助文档  F1
//自动对齐 ctrl + i
//同名之间的.h和。cpp切换   F4

//帮助文档  第一中的方式 F1  第二种 左侧按钮  第三种直接打开程序


mywigdet::mywigdet(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn ->show();//show以顶层方式弹出窗口控件
    //让btn对象 依赖在mywidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个按钮");
    //创建第二个按钮
    QPushButton  *  btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,100);

    //按钮可不可以 重新指定大小   可以
    btn->resize(200,50);

  //重置窗口大小
    resize(600,600);

    //设置固定的窗口大小
    setFixedSize(1000,1000);

    //设置窗口标题
    setWindowTitle("第一个窗口");




     //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");

    myBtn->move(600,0);
    myBtn->setParent(this);  //设置到对象树中


   //需求  点击我的按钮  关闭窗口
    //参数1 信号的发送者  参数2  发送的信号(函数的地址)  参数3 信号的接收者  数4 处理的槽函数
    connect(myBtn,&MyPushButton::clicked,this,&mywigdet::close);
    //connect(myBtn,&QPushButton::clicked,this,&mywigdet::close);








}

mywigdet::~mywigdet()
{
    qDebug() << "myWidegt的析构调用";
}

