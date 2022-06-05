#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件使用

    //设置默认定位
    ui->stackedWidget->setCurrentIndex(0);

    //scollArea按钮
    connect(ui->btn_scollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //toolBox按钮
    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //TabWidget按钮
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });


    //下拉框
   ui->comboBox->addItem("奔驰");
   ui->comboBox->addItem("宝马");
   ui->comboBox->addItem("拖拉机");

   //点击按钮  选中拖拉机
   connect(ui->btn_select,&QPushButton::clicked,[=](){
      // ui->comboBox->setCurrentIndex(2);
       ui->comboBox->setCurrentText("拖拉机");
   });

//   //利用QLabel显示图片
//   ui->lbl_Image->setPixmap(QPixmap("地址"));

//   //利用QLable显示gif动态图
//   QMovie * movie = new QMovie("地址");
//   ui->lbl_movie->setMovie(movie);
//   //播放动图
//   movie->start();

}

Widget::~Widget()
{
    delete ui;
}

