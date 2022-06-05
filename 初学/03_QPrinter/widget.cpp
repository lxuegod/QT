#include "widget.h"
#include "ui_widget.h"
#include <QPainter>    //画家类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击移动按钮，移动图片

//    connect(ui->pushButton,&QPushButton::clicked,[=](){

//        posX+=20;

//        //如果手动调用绘图事件
//        update();
//    });


}

void Widget::paintEvent(QPaintEvent *)
{
//    //实例画家对象  this 指定绘图的设备
//    QPainter painter(this);

//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    //设置画笔宽度
//    pen.setWidth(5);
//    //设置画笔风格
//    pen.setStyle(Qt::DotLine);
//    //让画家使用这个笔
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(Qt::green);
//    //设置画刷风格
//    pen.setBrush(brush);

//    //画线   参数1  起始坐标  参数2  终点坐标
//    painter.drawLine(QPoint(0,0), QPoint(100,100)  );

//    //画圆  椭圆   QPoint(坐标)  参数3  长轴  参数4  短轴
//    painter.drawEllipse(QPoint(100,100) , 50,50);

//    //画矩形     前两个参数确定矩形左上角的坐标    后两个参数确定    宽 高
//    painter.drawRect(QRect(20,20,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,300,50),"好好学习，天天向上");







    ////////////////////////////////////高级设置////////////////////////////////////
 //   QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置  抗锯齿能力   效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //移动画家
//    painter.translate(100,0);

//    //保存画家状态
//    painter.save();

//    painter.drawRect(QRect(20,20,50,50));

//    painter.translate(100,0);

//    //还原画家状态
//    painter.restore();

//    painter.drawRect(QRect(20,20,50,50));




    ///////////////////////////////利用画家   画资源图片////////////////////////
//    QPainter painter(this);

//    //如果超出屏幕  从0开始
//    if(posX >this->width())
//    {
//        posX = 0;
//    }

//    //painter.drawPixmap(20,100,QPixmap(":/Image/1.png"));





}

Widget::~Widget()
{
    delete ui;
}

